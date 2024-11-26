#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int middle = (begin + end)/2;
        while (nums[middle] != target && begin <= end) {
            if(nums[middle] > target) {
                end = middle-1;
            } else {
                begin = middle+1;
            }
            middle = (begin + end)/2;
        }

        if(begin > end) {
            return begin;
        }
        return middle;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,3,5,6};
    int target = 2;

    std::cout<< solution.searchInsert(nums, target) << std::endl;
}