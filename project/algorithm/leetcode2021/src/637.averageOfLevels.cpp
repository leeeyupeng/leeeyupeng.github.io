#include"leetcode.h"
#include"leetcodenode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q[2];
        queue<TreeNode*> *q1,*q2;
        q1 = &q[1];q2 = &q[2];
        q1->push(root);
        vector<double> ret;
        int sums = 0;
        int counter = 0;
        TreeNode* node;
        while(!q1->empty()){
            node = q1->front();
            q1->pop();
            if(node!= nullptr){
                sums+=node->val;
                counter++;
                q2->push(node->left);
                q2->push(node->right);
            }
            if(q1->empty() && counter > 0){
                ret.push_back(1.0d *sums / counter);
                swap(q1,q2);
            }
        }
        return ret;
    }
};