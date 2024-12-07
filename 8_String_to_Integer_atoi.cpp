#include <string>
#include <iostream>

class Solution {
public:
    int myAtoi(std::string s) {
        int sign = 1;
        int ans = 0;
        int i = 0;

        //skip leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        //set the sign
        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            i++;
        }

        //update the ans
        ans = ans*sign;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            //check if the ans will overflow
            if(ans > INT32_MAX/10) {
                return INT32_MAX;
            } else if(ans == INT32_MAX/10 && digit >= 7) {
                return INT32_MAX;
            } else if ( ans < INT32_MIN/10) {
                return INT32_MIN;
            } else if(ans == INT32_MIN/10 && digit >= 8) {
                return INT32_MIN;
            }

            //add the digit to the end
            if(sign == 1) {
                ans = ans*10 + digit;
                i++;
            } else if (sign == -1) {
                ans = ans*10 - digit;
                i++;
            }
            
        }
        return ans;
        
    }
};

int main() {
    Solution solution;

    std::cout<< solution.myAtoi("42") <<std::endl;
    std::cout<< solution.myAtoi("   -042") <<std::endl;
    std::cout<< solution.myAtoi("1337c0d3") <<std::endl;
    std::cout<< solution.myAtoi("0-1") <<std::endl;
    std::cout<< solution.myAtoi("words and 987") <<std::endl;
    std::cout<< solution.myAtoi("2147483647") <<std::endl;
    std::cout<< solution.myAtoi("2147483648") <<std::endl;
    std::cout<< solution.myAtoi("2147483646") <<std::endl;
    std::cout<< solution.myAtoi("-21474836488") <<std::endl;
    std::cout<< solution.myAtoi("-91283472332") <<std::endl;
    std::cout<< solution.myAtoi("++6488")<<std::endl;

}