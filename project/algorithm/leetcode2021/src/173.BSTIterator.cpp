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
class BSTIterator {
private:
    stack<TreeNode*> s;
    int ret = 0;
    TreeNode* top;
    TreeNode* node;
public:
    BSTIterator(TreeNode* root) {
        node = root;
        while(node!=nullptr){
            s.push(node);
            node=node->left;
        }
    }
    
    int next() {
        if(!s.empty()){
            top = s.top();
            ret = top->val;
            s.pop();
            node = top->right;
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */