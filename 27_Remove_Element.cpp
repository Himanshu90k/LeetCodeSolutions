#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        
        std::vector<int>::iterator newEnd = std::remove(nums.begin(), nums.end(), val);
        int k = std::distance(nums.begin(), newEnd);
        nums.erase(newEnd, nums.end());
        return k;
    }
};

int main() {
    Solution solution;

    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    std::cout<< solution.removeElement(nums, val) <<std::endl;

    
}