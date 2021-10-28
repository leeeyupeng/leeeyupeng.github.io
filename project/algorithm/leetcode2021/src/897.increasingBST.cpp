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
    pair<TreeNode*,TreeNode*> dfs(TreeNode* node){
        if(node == nullptr){return {nullptr,nullptr};}
        pair<TreeNode*,TreeNode*> left = dfs(node->left);
        pair<TreeNode*,TreeNode*> right = dfs(node->right);
        pair<TreeNode*,TreeNode*> ret{node,node};
        if(left.first!=nullptr){
            ret.first = left.first;
            left.second->right = node;
        }
        if(right.first!=nullptr){
            ret.second = right.second;
            node->right = right.first;
        }
        node->left = nullptr;
        return ret;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        pair<TreeNode*,TreeNode*> lr = dfs(root);
        return lr.first;
    }
};