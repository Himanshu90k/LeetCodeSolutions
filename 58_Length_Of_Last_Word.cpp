#include <string>
#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {

        int counter = 0;
        int prevCounter = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                counter++;
                prevCounter = counter;
                continue;
            }

            counter = 0;

        }

        if(counter == 0) {
            return prevCounter;
        }

        return counter;
    }
};

int main() {

    Solution solution;

    std::string s1 = " the work is kingofthe  ";

    std::cout<< solution.lengthOfLastWord(s1)<< std::endl;
    return 0;
};