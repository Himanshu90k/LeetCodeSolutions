#include <string>
#include <iostream>


class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int haystackLength = haystack.size(); // to do the subtracton in int form instead of unsigned int form that is returned by size().
        int needleLength = needle.size();

        for(int i = 0; i <= haystackLength - needleLength; i++) {
            std::string subString = haystack.substr(i, needle.size());
            if(subString == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::string haystack = "sadbutsad";
    std::string needle = "sad";

    std::cout<< solution.strStr(haystack, needle) << std::endl;
}
