#include <random>
#include "sorting.cc" 

std::vector<int> generateRandomArray(size_t size, int seed) {
    std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(1, 1000);
    std::vector<int> arr(size);
    for (int& num : arr) {
        num = dist(mt);
    }
    return arr;
}



std::vector<int> generateSortedArray(size_t size) {
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<int>(i + 1);
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(size_t size) {
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<int>(size - i);
    }
    return arr;
}

int main() {
    const int numArrays = 100;
    const int seed = 42;

    std::vector<int> sizes = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };

    for (int size : sizes) {
        stats totalStats; 

        for (int i = 0; i < numArrays; ++i) {
            std::vector<int> randomArray = generateRandomArray(size, seed + i);
            stats randomStats = naturalTwoWayMergeSort(randomArray);
            totalStats.comparison_count += randomStats.comparison_count;
            totalStats.copy_count += randomStats.copy_count;
        }

        totalStats.comparison_count /= numArrays;
        totalStats.copy_count /= numArrays;

        std::cout << "Random Array Size: " << size << std::endl;
        std::cout << "Average Comparison Count: " << totalStats.comparison_count << std::endl;
        std::cout << "Average Copy Count: " << totalStats.copy_count << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    
    for (int size : sizes) {
        std::vector<int> sortedArray = generateSortedArray(size);
        stats sortedStats = naturalTwoWayMergeSort(sortedArray);
        std::cout << "Sorted Array Size: " << size << std::endl;
        std::cout << "Comparison Count: " << sortedStats.comparison_count << std::endl;
        std::cout << "Copy Count: " << sortedStats.copy_count << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    
    for (int size : sizes) {
        std::vector<int> reverseSortedArray = generateReverseSortedArray(size);
        stats reverseSortedStats = naturalTwoWayMergeSort(reverseSortedArray);
        std::cout << "Reverse Sorted Array Size: " << size << std::endl;
        std::cout << "Comparison Count: " << reverseSortedStats.comparison_count << std::endl;
        std::cout << "Copy Count: " << reverseSortedStats.copy_count << std::endl;
        std::cout << "------------------------" << std::endl;
    }


    return 0;
}
