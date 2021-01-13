# CMake C++ example project for depthai-core Library

Example project which includes the necessary things to get started with DepthAI and C++ quick

## Dependencies
- cmake >= 3.2
- libusb1 development package
- C/C++11 compiler
 
MacOS: `brew install libusb`

Linux: `sudo apt install libusb-1.0-0-dev`

## Prerequisites 

Make sure submodules are initialized and updated 
```
git submodule update --init --recursive
```

## Building

Configure and build
```
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
```

## Running

To run the example application 'myapp', navigate to build directory and run 'myapp' executable
```
./myapp
```
