#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

/** @brief Comparator function to compare two strings case-insensitively
 *  @param a The first string to compare
 *  @param b The second string to compare
 *  @return true if a should appear before b in alphabetical order, false otherwise
 */
bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
    std::string upperA = a;
    std::string upperB = b;
    std::transform(upperA.begin(), upperA.end(), upperA.begin(), ::toupper);
    std::transform(upperB.begin(), upperB.end(), upperB.begin(), ::toupper);
    return upperA < upperB;
}

int main() {
    std::vector<std::string> animals;
    std::string animal;

    std::cout << "Enter animal names (type 'done' to finish):" << std::endl;

    /* Read animal names from user input until "done" is entered */
    while (true) {
        std::getline(std::cin, animal);
        if (animal == "done") {
            break;
        }
        animals.push_back(animal);
    }

    /* Sort the animal names using the case-insensitive comparator */
    std::sort(animals.begin(), animals.end(), caseInsensitiveCompare);

    std::cout << "\nAlphabetized list of animal names:" << std::endl;

    /* Display the sorted list of animal names */
    for (const auto& name : animals) {
        std::cout << name << std::endl;
    }

    return 0;
}
