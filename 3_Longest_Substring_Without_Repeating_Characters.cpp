#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map <char, int> subStr;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++) {
            char c = s[right];
            subStr[c] = subStr[c] + 1;

            while(subStr[c] > 1) {
                char c = s[left];
                subStr[c] = subStr[c] - 1;
                left++;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
        
    }
};

int main() {
    Solution solution;

    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";
    std::string s4 = "";


    //print the length of the longest unique substring.
    std::cout<< solution.lengthOfLongestSubstring(s1) << std::endl;
    std::cout<< solution.lengthOfLongestSubstring(s2) << std::endl;
    std::cout<< solution.lengthOfLongestSubstring(s3) << std::endl;
    std::cout<< solution.lengthOfLongestSubstring(s4) << std::endl;
}