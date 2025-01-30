#include <iostream>
#include <bitset>

/** @brief Function to reverse the bits of an unsigned integer
  * @param n Taking an unsigned integer
  * @return an unsigned integer
*/
unsigned int reverseBits(unsigned int n) {
    unsigned int reversed = 0;
    unsigned int bitCount = (unsigned int)sizeof(n) * 8u;

    for (unsigned int i = 0; i < bitCount; ++i) {
        if ((n & (1u << i)) != 0u) {
            reversed |= (1u << ((bitCount - 1u) - i));
        }
    }

    return reversed;
}

/** @brief Function to print the bits of an unsigned integer
 *  @param n Taking an unsigned integer
*/
void printBits(unsigned int n) {
    std::bitset<32> bits(n);
    std::cout << bits;
}

int main(void) {
    unsigned int value;
    std::cout << "Enter an unsigned integer: ";
    std::cin >> value;

    std::cout << "Original bits: ";
    printBits(value);
    std::cout << std::endl;

    unsigned int reversedValue = reverseBits(value);

    std::cout << "Reversed bits: ";
    printBits(reversedValue);
    std::cout << std::endl;
}
