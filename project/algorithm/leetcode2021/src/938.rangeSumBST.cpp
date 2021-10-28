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
private:
    int dfs(TreeNode* node,int low,int high){
        if(node == nullptr){return 0;}
        int ret = 0;
        if(node->val>=low && node->val<=high){
            ret += node->val;
        }
        if(node->val>=low){ret+=dfs(node->left,low,high);}
        if(node->val <= high){ret+=dfs(node->right,low,high);}
        return ret;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root,low,high);
    }
};