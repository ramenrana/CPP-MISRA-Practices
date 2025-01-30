#include <iostream>
#include <vector>

/**
 * @brief Checks if a given vector is a palindrome.
 *
 * A palindrome is a sequence that reads the same forward and backward.
 * This function template works for any type that supports equality comparison.
 *
 * @tparam T The type of the elements in the vector.
 * @param Vec The vector to check.
 * @return true if the vector is a palindrome, false otherwise.
 */
template <typename T>
bool palindrome(const std::vector<T> &Vec)
{
    size_t left = 0;
    size_t right = Vec.size();
    bool success = true;
    right--;

    /* Loop to compare elements from both ends towards the center */
    while (left < right)
    {
        /* If elements at the current indices are not equal, set success to false and break the loop */
        if (Vec[left] != Vec[right]) {
            success = false;
            break;
        }
        left++;
        right--;
    }
    return success;
}

int main(void) {
    std::vector<int> vec1 = {1, 2, 3, 2, 1};
    std::vector<int> vec2 = {1, 2, 3, 2};

    /* Check if vec1 is a palindrome and print the result */
    if (palindrome(vec1)) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not Palindrome!!!!\n"; 
    }

    /* Check if vec2 is a palindrome and print the result */
    if (palindrome(vec2)) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not Palindrome!!!!\n"; 
    }

    return 0;
}
