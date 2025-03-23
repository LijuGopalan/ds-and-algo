
#include <iostream>
#include <cuda_runtime.h>

__global__ void helloFromGPU() {
    printf("Hello World from GPU!\n");
}

int main() {
    // Launch kernel
    helloFromGPU<<<1, 10>>>();
    
    // Wait for GPU to finish before accessing on host
    cudaDeviceSynchronize();
    
    std::cout << "Hello World from CPU!" << std::endl;
    return 0;
}