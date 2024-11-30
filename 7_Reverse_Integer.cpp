#include <iostream>

class Solution {
public:
    int reverse(int x) {
        
        int reversedInt = 0;
        while(x != 0) {
            int lastDigit = x % 10;

            //check if the value of reversed int is going to overflow.
            if(reversedInt > INT32_MAX / 10 || reversedInt < INT32_MIN / 10) {
                return 0;
            }
            
            reversedInt = reversedInt*10 + lastDigit;
            x = x/10;
        }

        return reversedInt;
    }
};

int main() {
    Solution solution;

    std::cout<< solution.reverse(123) <<std::endl;
    std::cout<< solution.reverse(-123) <<std::endl;
    std::cout<< solution.reverse(120) <<std::endl;
    std::cout<< solution.reverse(1534236469) <<std::endl;
}