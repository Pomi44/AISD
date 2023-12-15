#include <vector>

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
    int n = arr.size();
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