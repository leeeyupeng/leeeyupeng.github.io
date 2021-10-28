#include <iostream>
#include <vector>
#include<string>
using namespace std;

#define CHARMAX 10
class Solution{
private:
    struct TrieNode{
        char value = 0;
        TrieNode* children[CHARMAX];

        TrieNode():value(0){
            for(int i = 0; i < CHARMAX;i ++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root=nullptr;
    bool _add(TrieNode* node,string &pn,int index){
        if(index == pn.length()){
            if(node->value == 1 || node->value == 2){return false;}
            else{node->value = 2;return true;}
        }
        if(node->value==2){return false;}

        node->value = 1;
        int key=pn[index] - '0';
        
        if(node->children[key] == nullptr){
            node->children[key] = new TrieNode();
        }
        return _add(node->children[key],pn,index+1);
    }
    bool add(string &pn){
        return _add(root,pn,0);
    }

    void _clear(TrieNode* node){
        for(int i = 0; i < CHARMAX; i ++){
            if(node->children[i]!=nullptr){
                _clear(node->children[i]);
            }
        }
        delete node;
        node = nullptr;
    }
public:
    bool hasprefix(vector<string> &pns){
        root=nullptr;
        root = new TrieNode();
        int n = pns.size();
        for(int i = 0; i < n; i ++){
            if(add(pns[i]) == false){
                return true;
            }
        }
        return false;
    }
    
    void clear(){
        _clear(root);
    }
};

// int main(){
//     int n = 0;    
//     while(cin>>n && n > 0){
//         Solution solution;
//         bool ret=false;
//         vector<string>  pns(n);
//         for(int i = 0; i < n; i ++){
//             cin>>pns[i];
//         }
//         ret = solution.hasprefix(pns);
//         solution.clear();
//         if(ret){printf("NO\n");}
//         else{printf("YES\n");}
//     }
//     return 0;
// }