#include <iostream>
#include <vector>

/** @brief Recursive function to perform a binary search
 *  @param arr The sorted array to be searched
 *  @param key The value to be searched for
 *  @param low The starting index of the current subarray
 *  @param high The ending index of the current subarray
 *  @return The index of the key if found, otherwise -1
 */
int recursiveBinarySearch(const std::vector<int>& arr, int key, int low, int high) {
    /* Base case: If low index is greater than high index, key is not found */
    if (low > high) {
        return -1;
    }

    /* Calculate the mid index */
    int mid = low + (high - low) / 2;

    /* If the element at mid index is the key, return the mid index */
    if (arr[mid] == key) {
        return mid;
    }

    /* If the key is smaller than the mid element, search in the left subarray */
    if (arr[mid] > key) {
        return recursiveBinarySearch(arr, key, low, mid - 1);
    }

    /* If the key is larger than the mid element, search in the right subarray */
    return recursiveBinarySearch(arr, key, mid + 1, high);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int key = 0;

    std::cout << "Enter the value to search: ";
    std::cin >> key;

    int result = recursiveBinarySearch(arr, key, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
