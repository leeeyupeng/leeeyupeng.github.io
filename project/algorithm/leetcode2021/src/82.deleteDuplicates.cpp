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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret=nullptr;
        ListNode* node=nullptr;
        ListNode* next=nullptr;
        ListNode* pre=nullptr;
        bool flag = false;
        node = head;
        next = node;
        while(node!=nullptr){
            next = next->next;
            if(next!=nullptr && next->val == node->val){flag = true;continue;}
            else{
                if(flag == true){
                    node=next;
                    flag = false;
                }
                else{
                    if(pre == nullptr){
                        pre = node;
                        ret = node;
                    }
                    else{
                        pre->next = node;
                        pre = node;
                    }
                    node = next;                 
                }

            }
        }
        if(pre!=nullptr){pre->next = nullptr;}
        return ret;
    }
};