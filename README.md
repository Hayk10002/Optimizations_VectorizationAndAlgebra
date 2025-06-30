# Optimizations_VectorizationAndAlgebra

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Example Output](#example-output)
- [How does this work](#how-does-this-work)

## Introduction
This program demonstrates the performance impact of vectorization and algebraic manipulations in C++. 

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/Optimizations_VectorizationAndAlgebra

# Go into the repository
$ cd Optimizations_VectorizationAndAlgebra

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Then, run the executable generated in the `build` directory.
$ your/path/to/exe/runner.exe
```

## Example Output

```
Running: no vectorization, no fast math
Elapsed time: 77ms
Running: no vectorization, fast math
Elapsed time: 18ms
Running: vectorization, no fast math
Elapsed time: 52ms
Running: vectorization, fast math
Elapsed time: 10ms
```

## How does this work
This project compiles a single c++ program with different compiler flags to demonstrate the effects of vectorization and fast math optimizations. The program performs a simple numerical computation and measures the elapsed time for each configuration.

The vectorization makes the computer use SIMD (Single Instruction, Multiple Data) instructions to perform operations on multiple data points simultaneously, which can significantly speed up numerical computations.

The fast math optimizations allow the compiler to make certain assumptions about floating-point arithmetic, which leads to faster computation.
