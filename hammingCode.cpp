#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Constants for HDLC frame
const uint8_t HDLC_FLAG = 0x7E;     // 01111110
const uint8_t HDLC_ESCAPE = 0x7D;   // 01111101
const uint8_t HDLC_ESC_MASK = 0x20; // 00100000

class HammingCode {
private:
  int m_dataSize;
  int m_totalSize;

  // Calculate number of parity bits needed
  int calculateParityBits(int dataSize) {
    // 2^r >= m + r + 1 where r is parity bits and m is data bits
    int r = 0;
    while (std::pow(2, r) < dataSize + r + 1) {
      r++;
    }
    return r;
  }

  // Check if index is a power of 2
  bool isPowerOfTwo(int n) { return (n > 0) && ((n & (n - 1)) == 0); }

public:
  HammingCode(int dataSize) : m_dataSize(dataSize) {
    int parityBits = calculateParityBits(dataSize);
    m_totalSize = dataSize + parityBits;
  }

  // Encode data using Hamming code
  std::vector<bool> encode(const std::vector<bool> &data) {
    std::vector<bool> encoded(m_totalSize, false);

    // Place data bits in non-parity positions
    int dataIndex = 0;
    for (int i = 1; i <= m_totalSize; i++) {
      if (!isPowerOfTwo(i)) {
        encoded[i - 1] = data[dataIndex++];
        if (dataIndex >= data.size())
          break;
      }
    }

    // Calculate parity bits
    for (int i = 0; i < log2(m_totalSize) + 1; i++) {
      int parityPos = std::pow(2, i) - 1;
      bool parity = false;

      // Check bits where this parity bit has influence
      for (int j = parityPos; j < m_totalSize; j++) {
        if ((j + 1) & (1 << i)) {
          parity ^= encoded[j];
        }
      }

      encoded[parityPos] = parity;
    }

    return encoded;
  }

  // Decode and correct errors in Hamming code
  std::vector<bool> decode(const std::vector<bool> &encoded) {
    std::vector<bool> corrected = encoded;

    // Calculate syndrome
    int errorPos = 0;
    for (int i = 0; i < log2(m_totalSize) + 1; i++) {
      bool parity = false;
      for (int j = 0; j < m_totalSize; j++) {
        if ((j + 1) & (1 << i)) {
          parity ^= encoded[j];
        }
      }

      if (parity) {
        errorPos += std::pow(2, i);
      }
    }

    // Correct error if found
    if (errorPos > 0 && errorPos <= m_totalSize) {
      corrected[errorPos - 1] = !encoded[errorPos - 1];
      std::cout << "Error corrected at position " << errorPos << std::endl;
    }

    // Extract data bits
    std::vector<bool> data;
    for (int i = 1; i <= m_totalSize; i++) {
      if (!isPowerOfTwo(i)) {
        data.push_back(corrected[i - 1]);
        if (data.size() >= m_dataSize)
          break;
      }
    }

    return data;
  }
};

class HDLC {
private:
  HammingCode m_hammingCode;

  // Convert byte to bit vector
  std::vector<bool> byteToBits(uint8_t byte) {
    std::vector<bool> bits(8);
    for (int i = 0; i < 8; i++) {
      bits[i] = (byte >> i) & 1;
    }
    return bits;
  }

  // Convert bit vector to byte
  uint8_t bitsToBytes(const std::vector<bool> &bits, int startIdx = 0) {
    uint8_t byte = 0;
    for (int i = 0; i < 8 && (startIdx + i) < bits.size(); i++) {
      if (bits[startIdx + i]) {
        byte |= (1 << i);
      }
    }
    return byte;
  }

  // Bit stuffing to avoid flag sequence in data
  std::vector<bool> bitStuff(const std::vector<bool> &data) {
    std::vector<bool> stuffed;
    int consecutiveOnes = 0;

    for (bool bit : data) {
      stuffed.push_back(bit);

      if (bit) {
        consecutiveOnes++;
        if (consecutiveOnes == 5) {
          stuffed.push_back(false); // Insert 0 after five consecutive 1s
          consecutiveOnes = 0;
        }
      } else {
        consecutiveOnes = 0;
      }
    }

    return stuffed;
  }

  // Remove bit stuffing from received data
  std::vector<bool> bitUnstuff(const std::vector<bool> &stuffed) {
    std::vector<bool> data;
    int consecutiveOnes = 0;

    for (size_t i = 0; i < stuffed.size(); i++) {
      bool bit = stuffed[i];

      if (bit) {
        consecutiveOnes++;
        data.push_back(bit);

        if (consecutiveOnes == 5 && i + 1 < stuffed.size() && !stuffed[i + 1]) {
          i++; // Skip the stuffed 0
          consecutiveOnes = 0;
        }
      } else {
        data.push_back(bit);
        consecutiveOnes = 0;
      }
    }

    return data;
  }

  // Calculate Frame Check Sequence (simple XOR-based CRC)
  uint16_t calculateFCS(const std::vector<uint8_t> &data) {
    uint16_t fcs = 0xFFFF;

    for (uint8_t byte : data) {
      fcs ^= byte;
      for (int i = 0; i < 8; i++) {
        if (fcs & 1) {
          fcs = (fcs >> 1) ^ 0x8408; // CRC-16-CCITT polynomial
        } else {
          fcs >>= 1;
        }
      }
    }

    return ~fcs;
  }

public:
  HDLC() : m_hammingCode(8) {} // Initialize for 8-bit data segments

  // Create an HDLC frame with Hamming code protection
  std::vector<uint8_t> createFrame(uint8_t address, uint8_t control,
                                   const std::vector<uint8_t> &data) {
    std::vector<uint8_t> frameContent;
    frameContent.push_back(address);
    frameContent.push_back(control);

    // Add data
    for (uint8_t byte : data) {
      frameContent.push_back(byte);
    }

    // Calculate FCS
    uint16_t fcs = calculateFCS(frameContent);
    frameContent.push_back(fcs & 0xFF);
    frameContent.push_back((fcs >> 8) & 0xFF);

    // Apply Hamming code to each byte
    std::vector<bool> encodedBits;
    for (uint8_t byte : frameContent) {
      std::vector<bool> bits = byteToBits(byte);
      std::vector<bool> encoded = m_hammingCode.encode(bits);
      encodedBits.insert(encodedBits.end(), encoded.begin(), encoded.end());
    }

    // Apply bit stuffing
    std::vector<bool> stuffedBits = bitStuff(encodedBits);

    // Convert back to bytes and add flags
    std::vector<uint8_t> frame;
    frame.push_back(HDLC_FLAG); // Opening flag

    // Convert bit array to bytes
    for (size_t i = 0; i < stuffedBits.size(); i += 8) {
      uint8_t byte = bitsToBytes(stuffedBits, i);

      // Byte stuffing for flag and escape characters
      if (byte == HDLC_FLAG || byte == HDLC_ESCAPE) {
        frame.push_back(HDLC_ESCAPE);
        frame.push_back(byte ^ HDLC_ESC_MASK);
      } else {
        frame.push_back(byte);
      }
    }

    frame.push_back(HDLC_FLAG); // Closing flag
    return frame;
  }

  // Process and validate an HDLC frame
  std::vector<uint8_t> processFrame(const std::vector<uint8_t> &frame) {
    if (frame.size() < 6 || frame.front() != HDLC_FLAG ||
        frame.back() != HDLC_FLAG) {
      std::cout << "Invalid frame format" << std::endl;
      return {};
    }

    // Remove flags and unescape bytes
    std::vector<uint8_t> frameContent;
    for (size_t i = 1; i < frame.size() - 1; i++) {
      if (frame[i] == HDLC_ESCAPE && i + 1 < frame.size() - 1) {
        frameContent.push_back(frame[++i] ^ HDLC_ESC_MASK);
      } else {
        frameContent.push_back(frame[i]);
      }
    }

    // Convert to bits and remove bit stuffing
    std::vector<bool> receivedBits;
    for (uint8_t byte : frameContent) {
      std::vector<bool> bits = byteToBits(byte);
      receivedBits.insert(receivedBits.end(), bits.begin(), bits.end());
    }

    std::vector<bool> unstuffedBits = bitUnstuff(receivedBits);

    // Apply Hamming code decoding with error correction
    int hammingCodeSize =
        m_hammingCode.encode(std::vector<bool>(8, false)).size();
    std::vector<uint8_t> decodedData;

    for (size_t i = 0; i + hammingCodeSize <= unstuffedBits.size();
         i += hammingCodeSize) {
      std::vector<bool> segment(unstuffedBits.begin() + i,
                                unstuffedBits.begin() + i + hammingCodeSize);
      std::vector<bool> corrected = m_hammingCode.decode(segment);

      decodedData.push_back(bitsToBytes(corrected));
    }

    if (decodedData.size() < 4) {
      std::cout << "Frame too short after decoding" << std::endl;
      return {};
    }

    // Extract FCS from the frame
    uint16_t receivedFCS = decodedData.back();
    receivedFCS = (receivedFCS << 8) | decodedData[decodedData.size() - 2];

    // Remove FCS from data for validation
    std::vector<uint8_t> dataWithoutFCS(decodedData.begin(),
                                        decodedData.end() - 2);

    // Calculate and check FCS
    uint16_t calculatedFCS = calculateFCS(dataWithoutFCS);
    if (receivedFCS != calculatedFCS) {
      std::cout << "FCS validation failed" << std::endl;
      return {};
    }

    // Extract and return the data field (skip address and control)
    return std::vector<uint8_t>(dataWithoutFCS.begin() + 2,
                                dataWithoutFCS.end());
  }

  // Introduce random bit errors for testing
  void introduceError(std::vector<uint8_t> &frame, int position) {
    if (position > 0 && position < frame.size() - 1) { // Don't modify flags
      frame[position] ^= (1 << (rand() % 8));          // Flip a random bit
      std::cout << "Introduced error in byte " << position << std::endl;
    }
  }
};

// Demo usage
int main() {
  HDLC hdlc;

  // Create test data
  std::vector<uint8_t> testData = {'H', 'e', 'l', 'l', 'o',
                                   ' ', 'H', 'D', 'L', 'C'};

  // Create HDLC frame with address 0x01 and control 0x03
  std::vector<uint8_t> frame = hdlc.createFrame(0x01, 0x03, testData);

  std::cout << "HDLC Frame created, size: " << frame.size() << " bytes"
            << std::endl;
  std::cout << "Frame contents (hex): ";
  for (uint8_t byte : frame) {
    std::cout << std::hex << std::uppercase << (int)byte << " ";
  }
  std::cout << std::dec << std::endl;

  // Introduce random bit error
  srand(time(nullptr));
  hdlc.introduceError(frame, 3 + (rand() % (frame.size() - 6)));

  // Process and validate the frame
  std::vector<uint8_t> receivedData = hdlc.processFrame(frame);

  if (!receivedData.empty()) {
    std::cout << "Successfully decoded data: ";
    for (uint8_t byte : receivedData) {
      std::cout << byte;
    }
    std::cout << std::endl;
  } else {
    std::cout << "Failed to decode frame" << std::endl;
  }

  return 0;
}
