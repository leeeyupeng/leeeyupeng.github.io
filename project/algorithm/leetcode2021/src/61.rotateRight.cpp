#include"leetcode.h"
#include"leetcodenode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){return head;}
        int n = 0;
        ListNode* node = head;
        while(node!=nullptr){n++;node=node->next;}
        k = k % n;
        if(k == 0){return head;}
        ListNode* left=nullptr,*right=nullptr;
        int counter = 0;
        left = head;
        while(counter<n-k-1){
            left = left->next;
            counter++;
        }
        right = left->next;
        left->next = nullptr;
        ListNode* ret = right;
        while(right->next!=nullptr){right=right->next;}
        right->next = head;
        return ret;        
    }
};