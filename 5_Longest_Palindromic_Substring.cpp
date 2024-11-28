#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.length(); i++) {
            int even = findLongestPalindrome(i, i+1, s); // for the even length palindrome - two center
            int odd = findLongestPalindrome(i, i, s); // for the odd length palindrome - one center
            int maxLengthPalindrome = std::max(even , odd);

            if(maxLengthPalindrome > end - start) {
                start = i - (maxLengthPalindrome -1)/2; // for the even length palindrome -1
                end = i + maxLengthPalindrome/2;
            }
        }
        return s.substr(start, end-start +1); //end-start+1 for the length of the substr. important for the palindrome of full length s.
        
    }

private:
    int findLongestPalindrome(int left, int right, std::string s) {
        while (left >= 0 && right < s.length() && (s[left] == s[right])) {
            left--;
            right++;
        }
        return right - left -1;
    }
};

int main() {
    Solution solution;

    std::string s1 = "babad";
    std::string s2 = "cbbd";
    std::string s3 = "abcba";


    std::cout<< solution.longestPalindrome(s1) << std::endl;
    std::cout<< solution.longestPalindrome(s2) << std::endl;
    std::cout<< solution.longestPalindrome(s3) << std::endl;
}