from PIL import Image, ImageEnhance

ASCII_CHARS = "@&?*+=-:.~$^+"


def resize_image(image, new_width=100):
    width, height = image.size
    aspect_ratio = height / width
    new_height = int(new_width * aspect_ratio * 0.55)
    return image.resize((new_width, new_height))


def enhance_contrast(image, factor=0.85):
    """Enhance the contrast for better details."""
    enhancer = ImageEnhance.Contrast(image)
    return enhancer.enhance(factor)


def grayify(image):
    return image.convert("L")


def pixels_to_ascii(image):
    pixels = image.getdata()
    scale_factor = 255 // (len(ASCII_CHARS) - 1)
    ascii_str = "".join(ASCII_CHARS[pixel // scale_factor] for pixel in pixels)
    return ascii_str


def create_detailed_ascii_art(image_path, new_width=100, contrast_factor=0.85):
    try:
        image = Image.open(image_path)
    except Exception as e:
        return f"Unable to open image file: {e}"

    # Resize and process image
    image = resize_image(image, new_width)
    image = enhance_contrast(image, contrast_factor)
    grayscale_image = grayify(image)

    # Convert pixels to ASCII characters
    ascii_str = pixels_to_ascii(grayscale_image)

    # Format ASCII string to match the image dimensions
    ascii_width = grayscale_image.width
    ascii_art = "\n".join(
        ascii_str[i : i + ascii_width] for i in range(0, len(ascii_str), ascii_width)
    )
    return ascii_art

# Input and output
image_path = "img.png"  # Your uploaded file
ascii_art = create_detailed_ascii_art(image_path, new_width=100, contrast_factor=0.85)

# Save and print the ASCII art
output_path = "ascii_art_detailed.txt"
with open(output_path, "w") as f:
    f.write(ascii_art)

print(ascii_art)
