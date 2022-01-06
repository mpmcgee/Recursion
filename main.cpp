#include <iostream>

int decimalToBinary(int);
bool palindromeCheck(std::string, int, int);
int binaryToDecimal(std::string, int i = 0);
std::string reverseString(std::string);
std::string keyEncode(std::string, int);
//std::string formatString(std::string);

int main() {
    std::cout << "Recursion Projects" << std::endl;
    //std::cout << decimalToBinary(5);
//    std::string word = "racecar";
//    std::cout << palindromeCheck(word, 0, word.length()-1);
    //std::cout << binaryToDecimal("1110101010");
    std::cout << keyEncode("hello", 27);

    return 0;
}

//converts a decimal number to binary
int decimalToBinary(int decimal) {
    if (decimal == 0) {
        return 0;
    }

    return (10 * decimalToBinary(decimal / 2) + (decimal % 2));
}

//converts a binary number to decimal
int binaryToDecimal(std::string binary, int i) {
    int n = binary.length();
    if (i == n-1) {
        return binary[i] - '0';
    }
    return ((binary[i] - '0') << (n-i-1)) + binaryToDecimal(binary, i+1);
}

//checks to see if a string is a palindrome and returns true or false
bool palindromeCheck(std::string word, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (word.at(start) != word.at(end)) {
        return false;
    }

    return palindromeCheck(word, ++start, --end);
}

//reverses a string
std::string reverseString(std::string str) {
    if (str.length() == 1) {
        return str;
    }

    return str.at(str.length() - 1) + reverseString(str.substr(0 ,str.length() - 1));
}

//caesar cipher encryption
std::string keyEncode(std::string str, int key) {
    if (str.length() == 0) {
        return str;
    }
    return (char((str.at(0) + key - 97) % 26 + 97) + keyEncode(str.substr(1, str.length() - 1), key));
}

