/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

*/

#include <iostream>

struct ListNode{

    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {}; 

};

ListNode* MergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* head = new ListNode();
    ListNode* cur = head;

    while( list1 && list2 ) {
        if( list1->val < list2->val ) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }

        cur = cur->next;
    }

    cur->next = list1 ? list1 : list2;

    return head->next;
};

void AddListValues( ListNode* &head, int value ) {

    ListNode* node = new ListNode(value);
    if ( head == nullptr ) {
        head = node;
    } else {
        ListNode* curr = head;
        while ( curr->next != nullptr ) {
            curr = curr->next;
        }
        curr->next = node;
    }
};

ListNode* CreateLinkedList(int *list, int length) {

    ListNode* head = nullptr;
    for(int i = 0; i < length; i++) {
        AddListValues(head, list[i]);
    }

    return head;
}

void PrintLinkedList(ListNode* head) {
    ListNode* temp = head;
    while ( temp != nullptr ) {
        std::cout << temp->val <<" ";
        temp = temp->next;
    }
}

int main() {

    int list1[] = {1, 2, 4};
    int list2[] = {1, 3, 4};

    ListNode* LinkedList1 =  CreateLinkedList(list1, (sizeof(list1)/sizeof(list1[0])));
    ListNode* LinkedList2 =  CreateLinkedList(list2, (sizeof(list2)/sizeof(list2[0])));

    ListNode* h1 = MergeTwoLists(LinkedList1, LinkedList2);

    PrintLinkedList(LinkedList2);

    return 0;
};