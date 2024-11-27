#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:

    ListNode *addNode(int node, ListNode *head) {
        ListNode *newNode = new ListNode(node);

        if(head == nullptr) {
            return newNode;
        }

        ListNode *temp1 = head;
        while(temp1->next != nullptr) {
            temp1= temp1->next;
        }
        temp1->next = newNode;
        return head;
    }

    void printNode(ListNode *head) {
        ListNode *temp1 = head;
        while(temp1 != nullptr) {
            std::cout<< temp1->val << " ";
            temp1 = temp1->next;
        }
        std::cout<< std::endl;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *l3 = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int res = 0;
            if(l1 != nullptr) {
                res = (l1->val);
                l1 = l1->next;
            } 
            if(l2 != nullptr) {
                res+= (l2->val);
                l2 = l2->next;
            }
            res+= carry;
            
            int node = res % 10; // get the last digit.
            l3 = addNode(node, l3);
            carry = res / 10; //update the carry value.
        }

        if(carry > 0) {
            l3 = addNode(carry, l3);
        }

        return l3;
    }
};

int main() {
    Solution solution;

    ListNode *l1 = nullptr;
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    l1 = solution.addNode(9, l1);
    solution.printNode(l1);

    ListNode *l2 = nullptr;
    l2 = solution.addNode(9, l2);
    l2 = solution.addNode(9, l2);
    l2 = solution.addNode(9, l2);
    l2 = solution.addNode(9, l2);
    solution.printNode(l2);

    ListNode *l3 = solution.addTwoNumbers(l1, l2);

    solution.printNode(l3);

}