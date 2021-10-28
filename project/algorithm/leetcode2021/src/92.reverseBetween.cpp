#include"leetcode.h"
#include"leetcodenode.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* node = head;
        ListNode* left=nullptr;
        ListNode* right=nullptr;
        ListNode* reverseheadpre=nullptr;
        ListNode* reversehead = head;;
        int i=1;
        if(m!=1){
            while(i<m-1){
                node = node->next;
                i++;
            }
            reverseheadpre = node;
            reversehead = node->next;
        }

        left = reversehead;
        right = left->next;
        i = m;
        while(i<n){
            node = right->next;
            right->next = left;
            left = right;
            right = node;
            i++;
        }
        if(m==1){
            head = left;
            reversehead->next = right;
        }
        else{
            reverseheadpre->next = left;
            reversehead->next = right;
        }
        return head;
    }
};