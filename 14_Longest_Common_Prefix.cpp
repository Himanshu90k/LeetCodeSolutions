#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string common = "";
        std::sort(strs.begin(), strs.end());

        if(strs[0].size() == 0) {
            return common; //return empty string
        }
        std::string first = strs[0];
        std::string last = strs[strs.size() -1];
        for(int i = 0; i < strs[0].size(); i++) {
            if(first[i] == last[i]) {
                common+= first[i];
            } else {
                return common; //return the longest common prefix
            }

        }

        return first; //return the longest common prefix as first element
    }
};

int main() {
    Solution solution;

    std::vector<std::string> str1 = {"flower", "flow", "flight"};
    std::cout<< solution.longestCommonPrefix(str1) <<std::endl;
}