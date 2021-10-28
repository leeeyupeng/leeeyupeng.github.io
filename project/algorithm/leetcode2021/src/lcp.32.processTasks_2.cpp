#include"leetcode.h"

class SegementTree{
public:
    struct Node
    {
        int l,r;
        int value;
        Node *left,*right;
        Node(int _l,int _r):l(_l),r(_r),value(0),left(nullptr),right(nullptr){}
    };
    
private:
    Node* root;

    int _get(Node* node,int l,int r){
        if(node==nullptr){return 0;}
        if(node->value == 0){return 0;}
        if(node->l == l && node->r == r){
            return node->value;
        }
        if(node->r == r){
            if(node->r - node->l + 1 == node->value){
                return node->r - l + 1;
            }

            if(node->left == nullptr && node->right == nullptr){
                return min(node->value,node->r - l + 1);
            }
        }
        if(node->l == node->r){
            return node->value;
        }
        
        int mid = (node->l + node->r)>>1;
        int ret = 0;
        if(l<=mid){
            ret += _get(node->left,l,min(mid,r));
        }
        if(r>mid){
            ret += _get(node->right,max(mid+1,l),r);
        }
        return ret;
    }

    int _insert(Node* node,int value,int r){
        if(node->r - node->l + 1 == node->value){return 0;}
        int mid = (node->l + node->r)>>1;
        if(node->left == nullptr && node->right == nullptr && node->r == r){
            value = min(value,node->r - node->l + 1 - node->value);
            node->value += value;
            return value;
        }
        
        if(node->r == r && node->r - node->l + 1 - node->value <= value){
            value = min(value,node->r - node->l + 1 - node->value);
            node->value += value;
            return value;
        }
        
        
        int rvalue = 0;
        if(r > mid){
            if(node->right == nullptr){
                node->right = new Node(mid+1,node->r);
            }
            rvalue = _insert(node->right,value,r);
        }
        value -= rvalue;
        int lvalue = 0;        
        if(0 != value){  
            if(node->left == nullptr){
                node->left = new Node(node->l,mid);
            }          
            lvalue = _insert(node->left,value,min(mid,r));
        }
        value -= lvalue;
        node->value = (node->left!=nullptr?node->left->value:0) + (node->right!=nullptr?node->right->value:0);
        return rvalue + lvalue;
    }
public:
    SegementTree(int l,int r){
        root = new Node(l,r);
    }
    //获取[s,e]的数量
    int get(int s,int e){
        return _get(root,s,e);
    }
    //以e为尾，往前插入value
    void insert(int value,int e){
        _insert(root,value,e);
    }
};
class Solution {
public:
    int processTasks(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> endsort(n,0);
        for(int i = 0; i < n; i ++){endsort[i]=i;}
        sort(endsort.begin(),endsort.end(),[&tasks](int &a,int &b){
            if(tasks[a][1] == tasks[b][1]){
                if(tasks[a][0] == tasks[b][0]){
                    return tasks[a][2] < tasks[b][2];
                }
                return tasks[a][0] < tasks[b][0];
            }
            return tasks[a][1] < tasks[b][1];
        });

        int MAX = 0;
        for(int i = 0; i < n; i ++){MAX=max(MAX,tasks[i][1]);}
        SegementTree segement(0,MAX);
        int index=0;
        int has=0;
        int ret = 0;
        for(int i = 0; i < n; i ++){
            index = endsort[i];
            has = segement.get(tasks[index][0],tasks[index][1]);
            if(tasks[index][2] - has>0){
                ret += tasks[index][2] - has;
                segement.insert(tasks[index][2] - has,tasks[index][1]);
            }
        }

        return segement.get(0,MAX);
    }
};