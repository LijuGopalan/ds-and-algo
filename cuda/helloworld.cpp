/*
    CUDA C++ "Hello, World!" Example

    This file demonstrates a basic CUDA C++ program that launches a kernel on the
    GPU to print a message. It illustrates the fundamental concepts of CUDA programming.

    Key CUDA Concepts Shown:
    - `__global__` specifier: This declares a function as a "kernel" that can be
      called from the host (CPU) and is executed on the device (GPU).
    - Kernel Launch (`<<<...>>>`): The triple-angle-bracket syntax is used to
      launch a kernel. `helloWorldKernel<<<1, 1>>>()` launches the kernel with
      one block of one thread.
    - `cudaDeviceSynchronize()`: This is a crucial function that blocks the CPU
      execution until all previously issued commands to the GPU have completed.
      It ensures that we see the GPU's output before the CPU program exits.
*/

#include <iostream>
#include <cuda_runtime.h>

/**
 * @brief A CUDA kernel function that prints a message from the GPU.
 *
 * The `__global__` keyword indicates that this function runs on the GPU and
 * can be called from CPU code.
 */
__global__ void helloWorldKernel() {
    // printf is used here because it can be executed on the GPU device
    // and prints to the standard output of the host.
    printf("Hello, World from GPU!\n");
}

/**
 * @brief The main function (host code) that launches the CUDA kernel.
 * @return 0 on successful execution.
 */
int main() {
    // Launch the kernel on the GPU.
    // The <<<1, 1>>> syntax specifies the execution configuration:
    // 1 block of threads, 1 thread per block.
    helloWorldKernel<<<1, 1>>>();

    // Wait for the GPU to finish all its tasks before the CPU continues.
    // This is necessary to ensure the printf from the kernel completes
    // before the main function might exit.
    cudaError_t err = cudaDeviceSynchronize();
    if (err != cudaSuccess) {
        std::cerr << "CUDA error: " << cudaGetErrorString(err) << std::endl;
        return -1;
    }

    // This message is printed from the CPU.
    std::cout << "Hello, World from CPU!" << std::endl;

    return 0;
}