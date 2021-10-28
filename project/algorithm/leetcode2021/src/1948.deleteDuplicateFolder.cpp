#include"leetcode.h"

class Solution {
private:
    struct Node{
        string val;
        int height;
        int issamechildren;
        int issame;
        bool visit;
        Node* parent;
        map<string,Node*> children;
        Node():val(""),height(0),issamechildren(0),issame(0),visit(false),parent(nullptr),children({}){}
        Node(string &_val):val(_val),height(0),issamechildren(0),issame(0),visit(false),parent(nullptr),children({}){}
    };

    int dfsheight(Node* node){
        if(node==nullptr){return 0;}
        int h = 1;
        for(map<string,Node*>::iterator ite = node->children.begin();ite!=node->children.end();ite++){
            h = max(h,1+dfsheight(ite->second));
        }
        node->height = h;
        return h;
    }
    void dfsleaf(Node* node,vector<Node*> &vleaf){
        if(node->children.size() == 0){vleaf.push_back(node);return;}
        for(map<string,Node*>::iterator ite = node->children.begin();ite!=node->children.end();ite++){
            dfsleaf(ite->second,vleaf);
        }
    }
    bool isleaf(Node* nodea,Node* nodeb){
        if(nodea->children.size() == 0 || nodeb->children.size() == 0){return true;}
        return false;
    }
    bool issamechildren(Node* nodea,Node* nodeb){
        if(nodea->children.size() == 0 || nodeb->children.size() == 0){return false;}
        auto itea = nodea->children.begin();
        auto iteb = nodeb->children.begin();
        while(itea!=nodea->children.end() && iteb != nodeb->children.end()){
            if(itea->second->issame!=0 && itea->second->issame == iteb->second->issame){

            }
            else{
                return false;
            }
            itea ++;
            iteb ++;
        }
        return itea==nodea->children.end() && iteb == nodeb->children.end();
    }

    bool dfscheck(vector<string> &path,int index,Node* node){
        if(index == path.size()){return true;}
        if(node->issamechildren!=0){return false;}
        if(index+1==path.size()){return true;}
        return dfscheck(path,index+1,node->children[path[index+1]]);
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
        }

        dfsheight(root);

        vector<Node*> vheight[2];
        dfsleaf(root,vheight[0]);

        int sameid = 0;
        int sid;
        int hindex = 1;
        while(hindex<root->height){
            vector<Node*> &vh = vheight[(hindex^0b1)&0b1];
            vector<Node*> &vhtemp = vheight[(hindex&0b1)&0b1];
            vhtemp.clear();
            hindex++;
            for(int i = 0; i < vh.size(); i ++){
                for(int j = i+1; j < vh.size();j ++){
                    if(isleaf(vh[i],vh[j])){
                        if(vh[i]->val == vh[j]->val){
                            sid = max(vh[i]->issame,vh[j]->issame);
                            if(sid == 0){sid = ++ sameid;}
                            
                            vh[i]->issame = sid;
                            vh[j]->issame = sid;
                            if(vh[i]->parent->height == hindex && vh[i]->parent->visit == false){
                                vhtemp.push_back(vh[i]->parent);
                                vh[i]->parent->visit = true;
                            }

                            if(vh[j]->parent->height == hindex && vh[j]->parent->visit == false){
                                vhtemp.push_back(vh[j]->parent);
                                vh[j]->parent->visit = true;
                            }
                        }
                    }
                    else if(issamechildren(vh[i],vh[j])){
                        sid = max(vh[i]->issamechildren,vh[j]->issamechildren);
                        if(sid == 0){sid = ++ sameid;}
                        vh[i]->issamechildren = sid;
                        vh[j]->issamechildren = sid;

                        if(vh[i]->val == vh[j]->val){
                            sid = max(vh[i]->issame,vh[j]->issame);
                            if(sid == 0){sid = ++ sameid;}
                            vh[i]->issame = sid;
                            vh[j]->issame = sid;

                            if(vh[i]->parent->height == hindex && vh[i]->parent->visit == false){
                                vhtemp.push_back(vh[i]->parent);
                                vh[i]->parent->visit = true;
                            }

                            if(vh[j]->parent->height == hindex && vh[j]->parent->visit == false){
                                vhtemp.push_back(vh[j]->parent);
                                vh[j]->parent->visit = true;
                            }
                        }
                    }
                    else{

                    }
                }
            }
        }
        vector<vector<string>> ret;
        for(int i = 0; i < n; i ++){
            if(dfscheck(paths[i],0,root->children[paths[i][0]])){
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