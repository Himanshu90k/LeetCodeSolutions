// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.

#include <iostream>
#include <queue>

bool isPalindrome(int x) {
    if(x < 0 || (x != 0 && x % 10 == 0) ) { // check for negative no or no with trailing zeroes.
        return false;
    }

    int reversed = 0;
    int temp = x;
    while ( temp > reversed) {
        reversed = (reversed*10) + (temp % 10);
        temp = temp / 10;
    }

    return (reversed == temp) || (reversed / 10 == temp);
    
}

int main() {

    std::cout<< isPalindrome(0) <<std::endl;
    std::cout<< isPalindrome(121) <<std::endl;
    std::cout<< isPalindrome(10) <<std::endl;
    std::cout<< isPalindrome(-2) <<std:: endl;
    std::cout<< isPalindrome(1221) <<std::endl;

    return 0;
}