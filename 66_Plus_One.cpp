#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int sum = digits.at(digits.size()-1) + 1;

        if(sum <= 9) {
            digits.at(digits.size() -1) = sum;
            return digits;
        }

        int carry = 1;
        for(int i = digits.size() - 1; i > -1; i--) {
            sum = digits.at(i) + carry;
            if(sum <= 9) {
                digits.at(i) = sum;
                carry = 0;
                break;
            }

            digits.at(i) = 0; // max sum value can be 10.
        }

        if(carry == 0) {
            return digits;
        }

        std::vector<int> resized_vector;
        resized_vector.push_back(1);
        for(int i = 0; i < digits.size(); i++) {
            resized_vector.push_back(digits.at(i));
        }
        return resized_vector;
    };
};

int main() {

    std::vector<int> No1 = {3,4,6};
    std::vector<int> No2 = {9,9,9,9};
    std::vector<int> No3 = {8,9,9,9};

    Solution solution;
    solution.plusOne(No1);
    No2 = solution.plusOne(No2);
    No3 = solution.plusOne(No3);

    for(int i: No3) {
        std::cout<< i << std::endl;
    };
    
    return 0;
};