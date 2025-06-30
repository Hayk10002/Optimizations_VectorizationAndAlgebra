#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>

double calculate(const std::vector<double>& arr) {
    double sum = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i] * arr[i] * arr[i] * arr[i] / (arr[i] - 1) / (arr[i] - 1) / (arr[i] - 1) / (arr[i] - 1);
    }
    return sum;
}

double generateRandomNumber()
{
    static std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> distribution(50.0, 500.0);
    return distribution(generator);
}

int main() {
    const size_t N = 1 << 24;
    std::vector<double> data(N);

    for (size_t i = 0; i < N; ++i)
        data[i] = generateRandomNumber();

    auto start = std::chrono::high_resolution_clock::now();
    double result = calculate(data);
    auto time = std::chrono::high_resolution_clock::now() - start;
    
    volatile int x = result;
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(time) << '\n';


    return 0;
}
