#include "sorting.cc"

int main() {
    std::vector<int> arr = { 19, 2, 9, 1, 5, 6 };

    std::cout << "Original array: ";
    printArray(arr);

    // Example usage of sorting functions
    stats bubble_stats = bubbleSort(arr);
    std::cout << "Array sorted by Bubble Sort: ";
    printArray(arr);
    std::cout << "Bubble Sort Comparison Count: " << bubble_stats.comparison_count << std::endl;
    std::cout << "Bubble Sort Copy Count: " << bubble_stats.copy_count << std::endl;

    std::vector<int> arr1 = { 19, 2, 9, 1, 5, 6 };
    stats shaker_stats = shakerSort(arr1);
    std::cout << "Array sorted by Shaker Sort: ";
    printArray(arr1);
    std::cout << "Shaker Sort Comparison Count: " << shaker_stats.comparison_count << std::endl;
    std::cout << "Shaker Sort Copy Count: " << shaker_stats.copy_count << std::endl;


    std::vector<int> arr2 = { 19, 2, 9, 1, 5, 6 };
    stats merge_stats = naturalTwoWayMergeSort(arr2);
    std::cout << "Array sorted by Natural Two-Way Merge Sort: ";
    printArray(arr2);
    std::cout << "Natural Two-Way Merge Sort Comparison Count: " << merge_stats.comparison_count << std::endl;
    std::cout << "Natural Two-Way Merge Sort Copy Count: " << merge_stats.copy_count << std::endl;

    return 0;
}