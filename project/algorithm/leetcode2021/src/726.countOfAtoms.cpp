#include"leetcode.h"

class Solution {
private:
    struct Node{
        enum Type{
            Atom,
            Set,
        };

        Type type;

        string str;
        int nums;  

        Node* parent;
        vector<Node*> children;

        Node(){parent = nullptr;nums = 1;str="";} 
    };
    void dfs(map<string,int>& simap,Node* node,int mul){
        if(node->type == Node::Type::Set){
            for(int i = 0; i < node->children.size();i++){
                dfs(simap,node->children[i],mul * node->nums);
            }
        }
        else{
            if(simap.find(node->str)==simap.end()){
                simap.insert({node->str,0});
            }
            simap[node->str]+=node->nums * mul;
        }
    }
    inline void int2string(int value,string & ret){
        if(value == 0){ret.push_back('0');return;}
        while(value!=0){
            ret.push_back(value%10+'0');
            value/=10;
        }
        reverse(ret.begin(),ret.end());
    }
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        int i = 0;

        Node* root=new Node();
        root->type = Node::Type::Set;
        root->nums=1;
        string str;
        int nums;
        Node* parent = root;
        Node* node = root;
        while(i<n){
            if(formula[i] == '('){
                node = new Node();
                node->type = Node::Type::Set;
                node->str="(";
                node->parent = parent;
                parent->children.push_back(node);
                parent = node;
                i++;
                
            }
            else if(formula[i]==')'){
                while(parent->type!=Node::Type::Set){
                    parent = parent->parent;
                }
                node = parent;
                parent = node->parent;
                i++;
            }
            else if(formula[i]>='0' && formula[i]<='9'){
                nums = formula[i]-'0';
                i++;
                while(i<n && formula[i]>='0' && formula[i]<='9'){
                    nums=nums*10 + formula[i] - '0';
                    i++;
                }

                node->nums = nums;
            }
            else{
                str.clear();
                str.push_back(formula[i]);
                i++;
                while(i<n && formula[i] >='a' && formula[i] <='z'){
                    str.push_back(formula[i]);
                    i++;
                } 

                node = new Node();
                node->type = Node::Type::Atom;
                node->str = str;
                node->parent = parent;
                parent->children.push_back(node);
            }
        }

        map<string,int> simap;
        dfs(simap,root,1);
        
        string ret;
        string strdigit;
        for(map<string,int>::iterator ite = simap.begin();ite!=simap.end();ite++){
            ret+=(ite->first);
            if(ite->second!=1){
                strdigit.clear();
                int2string(ite->second,strdigit);
                ret+=strdigit;
            }
        }
        return ret;

    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.countOfAtoms("Mg(OH)2");

//     return 0;
// }