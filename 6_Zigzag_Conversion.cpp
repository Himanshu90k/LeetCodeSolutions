#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::vector<std::vector<char>> zigZagString(numRows);

        if(s.length() <= numRows || numRows == 1) {
            return s;
        }

        int row = 0;
        int down = 0;
        for(int i = 0; i < s.length(); i++) {
            zigZagString[row].push_back(s[i]);

            if(row == numRows - 1) {
                down = -1;
            } else if (row == 0) {
                down = 1;
            }
            row+= down;
        }

        std::string result;
        for(const std::vector<std::vector<char>>::iterator::value_type &row: zigZagString) {
            for(const char &c: row) {
                result+= c;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    std::string s1 = "PAYPALISHIRING";
    std::string s2 = "A";

    std::cout<< solution.convert(s1, 3)<< std::endl;
    std::cout<< solution.convert(s1, 4)<< std::endl;
    std::cout<< solution.convert(s2, 1)<< std::endl;
}