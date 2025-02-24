#include <stdio.h>
#include <string.h>

#define FLAG "01111110"
#define MAX_LEN 100

void bit_stuffing(char *input, char *output) {
  int count = 0, j = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    output[j++] = input[i];
    if (input[i] == '1') {
      count++;
      if (count == 5) {
        output[j++] = '0';
        count = 0;
      }
    } else {
      count = 0;
    }
  }
  output[j] = '\0';
}

int main() {
  char input[MAX_LEN], payload[MAX_LEN], stuffed[MAX_LEN];
  printf("Enter the binary sequence: ");
  scanf("%s", input);
  if (strncmp(input, FLAG, 8) != 0 ||
      strcmp(input + strlen(input) - 8, FLAG) != 0) {
    printf("Invalid frame: Must start and end with 01111110\n");
    return 1;
  }

  strncpy(payload, input + 8, strlen(input) - 16);
  payload[strlen(input) - 16] = '\0';
  bit_stuffing(payload, stuffed);
  printf("Stuffed frame: %s%s%s\n", FLAG, stuffed, FLAG);
  return 0;
}
