# BMP Reader Library

This project is a simple BMP (Bitmap) file reader implemented in C++. It focuses on reading BMP files with a 14-byte file header (BITMAPFILEHEADER) and a 40-byte info header (BITMAPINFOHEADER). The reader does not support compression and is compatible with BMP images using 1, 4, 8, 16, 24, or 32 bits per pixel (bpp) formats.

## Features

- **Header**: Supports only the standard 14-byte BITMAPFILEHEADER header.
- **Info Header**: Handles only the 40-byte BITMAPINFOHEADER structure.
- **Bit Depth Support**: Works with BMP files using 1, 4, 8, 16, 24, or 32 bpp.
- **No Compression**: Only supports uncompressed BMP files (BI_RGB).

## How to Use the Library

You can use the BMP reader library in two main ways:

### Option 1: Copy Header File

If you prefer a minimal setup:

1. Copy the `bmpreader.hpp` file into your project's source directory.
2. Include it in your source code:

`#include "bmpreader.hpp"`

You're ready to use the BMP reader classes and functions.

### Option 2: Add as a Subdirectory (CMake Integration)

For a more modular and maintainable approach:

1. Clone this project into your project directory, for example:

```bash 
git clone https://github.com/Hayk10002/bmpreader.git external/bmpreader
```

2. In your project's `CMakeLists.txt`, add the following lines:

```cmake
add_subdirectory(external/bmpreader)  
target_link_libraries(your_project PRIVATE bmpreader)
```

3. Then, include the header in your source files using:

```cpp
#include <bmpreader.hpp>
```

## Example Usage

Here is a basic example of how to use the BMP reader to read a BMP file and access its header information.

```cpp
#include "bmpreader.hpp"

int main() {
    Image image(readBitmapImage("filename.bmp"));
    
    std::cout << "Width: " << image.width << '\n';
    std::cout << "Height: " << image.height << '\n';

    std::cout << "Pixel value (R,G,B) at coordinates (0, 0): (" << (unsigned int)image.pixels[0].red << ", " << (unsigned int)image.pixels[0].green << ", " << (unsigned int)image.pixels[0].blue << ")\n"; 
    return 0;
}
```
