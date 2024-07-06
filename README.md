# Sea Horizon Detection

This project detects the horizon line in sea images using OpenCV library in C++.

## Features

- Converts the image to grayscale
- Applies median filtering to reduce noise
- Detects edges using Canny algorithm
- Finds horizontal lines using Hough transform
- Draws the detected horizon line on the original image

## Prerequisites

- C++ compiler (e.g., GCC, Clang)
- OpenCV library (version 4.x or higher)

## Installation

1. Clone the repository:
   git clone https://github.com/your-username/seaHorizonDetection.git

3. Navigate to the project directory:
   cd seaHorizonDetection

5. Create a build directory:
   mkdir build
   cd build

6. Generate the Makefild using CMake:
   cmake ..

7. Build the project:
   make

8. Run the project: ./SeaImageProcessing <image_path>
