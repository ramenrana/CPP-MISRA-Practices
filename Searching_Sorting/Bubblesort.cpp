#include <iostream>
#include <vector>

/** @brief bubbleSort A function to sort an array of elements
 *  @param arr Container which is a vector of integer
*/
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
 
    /* Perform n-1 passes */
    for (int pass = 0; pass < (n - 1); ++pass) {
        bool swapped = false;
        /* Perform a single pass */
        for (int i = 0; i < (n - 1 - pass); ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        /* If no two elements were swapped by the inner loop, then break */
        if (!swapped) {
            break;
        }
    }
}

/** @brief Display A function to display the sorted array 
 *  @param arr Container of a vector of integer
*/
void Display(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
 
    std::cout << "Unsorted array: ";
    Display(arr);
 
    bubbleSort(arr);
 
    std::cout << "Sorted array: ";
    Display(arr);
 
    return 0;
}