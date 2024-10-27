/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.*/

#include <iostream>
#include <string>
#include <map>
#include <stack>
int romanToInt(std::string s) {

    std::map<char, int> Map = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}}; //map for roman to integer

    char prev;
    int Number = 0;
    int currentNumber = 0;
    for(int i = (s.length() - 1); i >= 0; i--) {
        char current = s[i];

            if (current == 'I') {
                if (prev == 'V' || prev == 'X') {
                    currentNumber -= Map[current];
                }
            }
            if (current == 'X') {
                if (prev == 'L' || prev == 'C') {
                    currentNumber -= Map[current];
                }
            }
            if (current == 'C') {
                if (prev == 'D' || prev == 'M') {
                    currentNumber -= Map[current];
                }
            }
            if(current) {
                if (currentNumber == Number) {
                    currentNumber += Map[current];
                }
            }

            Number = currentNumber;
            prev = current;
    }

    return Number;
}


int main() {

    std::cout<< romanToInt("MCMXCIV") <<std::endl; //1994

    std::cout << "The integer value of III is " << romanToInt("III") << std::endl;       // 3
    std::cout << "The integer value of IV is " << romanToInt("IV") << std::endl;         // 4
    std::cout << "The integer value of IX is " << romanToInt("IX") << std::endl;         // 9
    std::cout << "The integer value of LVIII is " << romanToInt("LVIII") << std::endl;   // 58
    std::cout << "The integer value of MMXXIII is " << romanToInt("MMXXIII") << std::endl; // 2023

    return 0;
}