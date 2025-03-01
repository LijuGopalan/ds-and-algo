#include <iostream>
#include <cuda_runtime.h>

// Kernel function to print "Hello, World!" from the GPU
__global__ void helloWorldKernel() {
    printf("Hello, World from GPU!\n");
}

int main() {
    // Launch the kernel with a single thread
    helloWorldKernel<<<1, 1>>>();

    // Wait for the GPU to finish before accessing the results
    cudaDeviceSynchronize();

    std::cout << "Hello, World from CPU!" << std::endl;

    return 0;
}