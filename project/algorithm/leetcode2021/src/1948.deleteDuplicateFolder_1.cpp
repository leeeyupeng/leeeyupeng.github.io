#include"leetcode.h"

class Solution {
private:
    struct Node{
        string val;
        int pathid;
        int counter;
        Node* parent;
        map<string,Node*> children;
        Node():val(""),pathid(-1),counter(0),parent(nullptr),children({}){}
        Node(string &_val):val(_val),pathid(-1),counter(0),parent(nullptr),children({}){}
    };

    void dfsleaf(Node* node,vector<Node*> &vleaf){
        if(node->children.size() == 0){vleaf.push_back(node);return;}
        for(map<string,Node*>::iterator ite = node->children.begin();ite!=node->children.end();ite++){
            dfsleaf(ite->second,vleaf);
        }
    }

    bool dfscheck(vector<string> &path,int index,Node* node){
        if(index < 0){return true;}
        if(node->counter>=2){return false;}
        if(index-1< 0){return true;}
        return dfscheck(path,index-1,node->children[path[index-1]]);
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        int n = paths.size();
        Node* root = new Node();
        Node* parent;
        Node* node;
        map<string,Node*>::iterator ite;
        for(int i = 0; i < n; i ++){
            parent = root;
            for(int j = 0; j < paths[i].size();j++){
                ite = parent->children.find(paths[i][j]);
                if(ite == parent->children.end()){
                    node = new Node(paths[i][j]);
                    node->parent = parent;
                    parent->children.insert({paths[i][j],node});
                    parent = node;
                }
                else{
                    parent = ite->second;
                }
            }
            parent->pathid = i;
        }

        Node* root2 = new Node();

        vector<Node*> vleaf;
        dfsleaf(root,vleaf);
        unordered_map<int,Node*> um2;
        Node* nodetemp;
        for(int i = 0; i < vleaf.size(); i++){
            node = vleaf[i];
            parent = root2;
            while(node!=root){
                auto ite = parent->children.find(node->val);
                if(ite == parent->children.end()){
                    nodetemp = new Node(node->val);
                    nodetemp->counter ++;
                    parent->children.insert({node->val,nodetemp});
                    nodetemp->parent = parent;
                    parent = nodetemp;
                }
                else{
                    ite->second->counter++;
                    parent = ite->second;
                }
                if(node->pathid!=-1){
                    parent->pathid = node->pathid;
                    um2.insert({node->pathid,parent});
                }
                node = node->parent;
            }
        }


        vector<vector<string>> ret;
        for(int i = 0; i < n; i ++){
            if(dfscheck(paths[i],paths[i].size()-1,um2[i])){
                ret.push_back(paths[i]);
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<string>> paths = {
//         {"a"},{"c"},{"d"},{"a","b"},{"c","b"},{"d","a"}
//     };

//     auto ret = solution.deleteDuplicateFolder(paths);

//     return 0;
// }