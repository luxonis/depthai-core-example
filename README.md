# CMake C++ example project for depthai-core library

CMake example project which serves as a template on how to quickly get started with C++ and the [depthai-core](https://github.com/luxonis/depthai-core/) library.

## Depthai library dependencies
- cmake >= 3.20
- C/C++17 compiler

## Prerequisites 

### OpenCV - optional (for this example only) 
OpenCV is required to run the out-of-box example. You can install OpenCV using one of the options below:

- Ubuntu 20.04, Ubuntu 22.04, Ubuntu 24.04 - `sudo apt install libopencv-dev`
- Fedora36+ - `sudo dnf install opencv-devel`
- MacOS - `brew install opencv`
- Windows - `choco install opencv` or from source or a pre-built package
- Or install from package / sources (other OSes)
https://docs.opencv.org/master/d0/d3d/tutorial_general_install.html


## Building

### Clone and build depthai-core
```bash
git clone https://github.com/luxonis/depthai-core.git --recursive && cd depthai-core
cmake -Bbuild -S. -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/path/to/install/dir
cmake --build build --target install --config Release --parallel 4

## Windows: You might have to provide path to OpenCV. If you installed OpenCV using choco, use
cmake -Bbuild -S. -DOpenCV_DIR=C:/tools/opencv/build -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/path/to/install/dir
```

Navigate to your example project's root folder.

### Build example project
```bash
cmake -Bbuild -S. -DCMAKE_PREFIX_PATH=/path/to/install/dir
cmake --build build --config Release --parallel 4

## Windows: You might have to provide path to OpenCV. If you installed OpenCV using choco, use
cmake -Bbuild -S. -DOpenCV_DIR=C:/tools/opencv/build -DCMAKE_PREFIX_PATH=/path/to/install/dir
```

Make sure to change the `/path/to/install/dir` to a desired location on your filesystem.
On Linux-based systems, if the `-DCMAKE_INSTALL_PREFIX=/path/to/install/dir` option is omited, `depthai-core` will get installed to `/usr/local`.
In that case, you don't need to specify the `-DCMAKE_PREFIX_PATH=/path/to/install/dir` option.

## Running

To run the example application 'myapp', navigate to build directory and run 'myapp' executable
```
./myapp
```
