#include <iostream>
#include <vector>

/** @brief Recursive function to perform a linear search
 *  @param arr The array to be searched
 *  @param key The value to be searched for
 *  @param index The current index in the array
 *  @return The index of the key if found, otherwise -1
 */
int recursiveLinearSearch(const std::vector<int>& arr, int key, int index) {
    /* Base case: If index is out of bounds, return -1 */
    if (index >= arr.size()) {
        return -1;
    }

    /* If the element at the current index is the key, return the index */
    if (arr[index] == key) {
        return index;
    }

    /* Recursive case: Search in the rest of the array */
    return recursiveLinearSearch(arr, key, index + 1);
}

int main(void) {
    std::vector<int> arr = {34, 67, 23, 1, 89, 2, 56, 78};
    int key = 0;

    std::cout << "Enter the value to search: ";
    std::cin >> key;

    int result = recursiveLinearSearch(arr, key, 0);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
