#include <iostream>
#include <cstring>
#define MAX_LENGTH 256

int main(void) {
    char firstString[MAX_LENGTH];
    char secondString[MAX_LENGTH];

    /* Input two strings */
    std::cout << "Enter the first string: ";
    std::cin.getline(firstString, MAX_LENGTH);

    std::cout << "Enter the second string: ";
    std::cin.getline(secondString, MAX_LENGTH);

    /* Compare the two strings using strcmp */
    int result = strcmp(firstString, secondString);

    /* Output the result */
    if (strlen(firstString) < strlen(secondString)) {
        std::cout << "The first string is less than the second string." << std::endl;
    } else if (result == 0) {
        std::cout << "The first string is equal to the second string." << std::endl;
    } else {
        std::cout << "The first string is greater than the second string." << std::endl;
    }

    return 0;
}
