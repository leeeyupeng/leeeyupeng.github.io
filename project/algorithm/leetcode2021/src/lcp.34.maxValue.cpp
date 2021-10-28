#include"leetcode.h"

#include"leetcodenode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int k;
    void _maxvalue(TreeNode* node,vector<int> &values){
        if(node == nullptr){
            for(int i = 0; i <= k; i ++){values[i] = 0;}
            return ;
        }

        vector<int> leftvalues(k+1,0);
        vector<int> rightvalues(k+1,0);
        _maxvalue(node->left,leftvalues);
        _maxvalue(node->right,rightvalues);

        values[0] = leftvalues[k] + rightvalues[k];
        values[0] = max(values[0],leftvalues[0] + rightvalues[0]);
        values[0] = max(values[0],leftvalues[0] + rightvalues[k]);
        values[0] = max(values[0],leftvalues[k] + rightvalues[0]);
        for(int i = 1; i <= k; i ++){
            for(int j = 0; j < i; j ++){
                values[i] = max(values[i],node->val + leftvalues[j] + rightvalues[i-1-j]);
            }
        }
        for(int i = 2; i <= k; i ++){
            values[i] = max(values[i],values[i-1]);
        }
    }
public:
    int maxValue(TreeNode* root, int k) {
        this->k = k;
        vector<int> values(k+1,0);
        _maxvalue(root,values);
        int ret = values[0];
        for(int i = 1;i <= k; i ++){
            ret = max(ret,values[i]);
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     TreeNode* root;
//     root = new TreeNode(5);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     int k = 2;
//     auto ret = solution.maxValue(root,k);

//     return 0;
// }