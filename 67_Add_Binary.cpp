#include <string>
#include <iostream>
#include <math.h>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string resultstr;

        if(a.length() > b.length()) {
            int difference = a.length() - b.length();
            b.insert(0, difference, '0');
        } else {
            int difference = b.length() - a.length();
            a.insert(0, difference, '0');
        }

        int carry = 0;
        for(int i = a.length() - 1; i > -1; i--) {
            int val1 = a.at(i) - '0';
            int val2 = b.at(i) - '0';
            int sum = val1 + val2 + carry;

            if(sum == 2) {
                resultstr.insert(0, "0");
                carry = 1;
            } else if(sum == 3) {
                resultstr.insert(0, "1");
                carry = 1;
            } else {
                resultstr.insert(0, std::to_string(sum));
                carry = 0;
            }

        }

        if(carry == 1) {
            resultstr.insert(0, "1");
            return resultstr;
        }
        return resultstr;

    };
};

int main() {
    Solution solution;
    std::string s1 = "0";
    std::string s2 = "0";

    std::cout<< solution.addBinary(s1, s2) <<std::endl;

    return 0;
};