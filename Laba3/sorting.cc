#include <vector>
#include <iostream>

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};


void swap(int& a, int& b, stats& st) {
    int temp = a;
    a = b;
    b = temp;
    st.copy_count += 2;
}


stats bubbleSort(std::vector<int>& arr) {
    stats st;
    auto n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            ++st.comparison_count;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1], st);
                swapped = true;
            }
        }

        if (!swapped) 
            break;
    }

    return st;
}


stats shakerSort(std::vector<int>& arr) {
    stats st;
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            ++st.comparison_count;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1], st);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            ++st.comparison_count;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1], st);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        ++start;
    }

    return st;
}

void merge(std::vector<int>& arr, int left, int mid, int right, std::vector<int>& tempArr, stats& st) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        ++st.comparison_count;
        if (arr[i] <= arr[j]) {
            tempArr[k++] = arr[i++];
        }
        else {
            tempArr[k++] = arr[j++];
        }
        ++st.copy_count;
    }

    while (i <= mid) {
        tempArr[k++] = arr[i++];
        ++st.copy_count;
    }

    while (j <= right) {
        tempArr[k++] = arr[j++];
        ++st.copy_count;
    }


    for (i = left; i <= right; ++i) {
        arr[i] = tempArr[i];
        ++st.copy_count;
    }
}


stats naturalTwoWayMergeSort(std::vector<int>& arr) {
    stats st;
    auto n = arr.size();

    std::vector<int> tempArr(n);
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        auto left = 0;

        while (left < n) {
            int mid = left;

            while (mid + 1 < n && arr[mid] <= arr[mid + 1]) {
                ++mid;
            }

            if (mid + 1 < n) {
                int right = mid + 1;

                while (right + 1 < n && arr[right] <= arr[right + 1]) {
                    ++right;
                }

                merge(arr, left, mid, right, tempArr, st);
                sorted = false;
                left = right + 1;
            }
            else {
                left = n;
            }
        }
    }

    return st;
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}