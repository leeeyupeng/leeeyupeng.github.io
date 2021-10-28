#include"leetcode.h"

class Solution {
private:
    struct Node{
        string val;
        int height;
        int issamechildren;
        int issame;
        Node* parent;
        map<string,Node*> children;
        Node():val(""),height(0),issamechildren(0),issame(0),parent(nullptr),children({}){}
        Node(string &_val):val(_val),height(0),issamechildren(0),issame(0),parent(nullptr),children({}){}
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
    void dfsleaf(Node* node,map<string,set<Node*>> &vleaf){
        if(node->children.size() == 0){
            auto ite = vleaf.find(node->val);
            if(ite == vleaf.end()){
                vleaf.insert({node->val,{node}});
            }
            else{
                ite->second.insert(node);
            }
            return;
        }
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

        for(int i = 0; i < n; i ++){
            parent = root;
            for(int j = 0; j < paths[i].size();j++){
                auto ite = parent->children.find(paths[i][j]);
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

        vector<map<string,set<Node*>>> vheight[2];
        vheight[0].push_back({});
        dfsleaf(root,vheight[0].front());

        int sameid = 0;
        int sid;
        int hindex = 1;
        while(hindex<root->height){
            vector<map<string,set<Node*>>> &vmvh = vheight[(hindex^0b1)&0b1];
            vector<map<string,set<Node*>>> &vmvhtemp = vheight[(hindex&0b1)&0b1];
            vmvhtemp.clear();
            hindex++;
            for(int ivmvh = 0;ivmvh<vmvh.size(); ivmvh++){
                for(auto ite = vmvh[ivmvh].begin();ite!=vmvh[ivmvh].end();ite++){
                    set<Node*> &vh = ite->second;
                    if(vh.size()<2){continue;}
                    vmvhtemp.push_back({});
                    map<string,set<Node*>> &mvtemp = vmvhtemp.back();
                    for(auto itei = vh.begin(); itei!=vh.end(); itei ++){
                        auto itej  = itei;
                        itej ++;
                        for(; itej !=vh.end(); itej ++){
                            Node* nodei,*nodej;
                            nodei = (*itei);
                            nodej = (*itej);

                            if(isleaf(nodei,nodej)){
                                if(nodei->val == nodej->val){
                                    sid = max(nodei->issame,nodej->issame);
                                    if(sid == 0){sid = ++ sameid;}
                                    
                                    nodei->issame = sid;
                                    nodej->issame = sid;
                                    if(nodei->parent->height == hindex){
                                        auto ite2 = mvtemp.find(nodei->val);
                                        if(ite2 == mvtemp.end()){
                                            mvtemp.insert({nodei->val,{nodei->parent}});
                                        }
                                        else{
                                            if(ite2->second.find(nodei->parent)==ite2->second.end()){
                                                ite2->second.insert(nodei->parent);
                                            }                                            
                                        }
                                    }

                                    if(nodej->parent->height == hindex){
                                        auto ite2 = mvtemp.find(nodej->val);
                                        if(ite2 == mvtemp.end()){
                                            mvtemp.insert({nodej->val,{nodej->parent}});
                                        }
                                        else{
                                            if(ite2->second.find(nodej->parent)==ite2->second.end()){
                                                ite2->second.insert(nodej->parent);
                                            }      
                                        }
                                    }
                                }
                            }
                            else if(issamechildren(nodei,nodej)){
                                sid = max(nodei->issamechildren,nodej->issamechildren);
                                if(sid == 0){sid = ++ sameid;}
                                nodei->issamechildren = sid;
                                nodej->issamechildren = sid;

                                if(nodei->val == nodej->val){
                                    sid = max(nodei->issame,nodej->issame);
                                    if(sid == 0){sid = ++ sameid;}
                                    nodei->issame = sid;
                                    nodej->issame = sid;

                                    if(nodei->parent->height == hindex){
                                        auto ite2 = mvtemp.find(nodei->val);
                                        if(ite2 == mvtemp.end()){
                                            mvtemp.insert({nodei->val,{nodei->parent}});
                                        }
                                        else{
                                            if(ite2->second.find(nodei->parent)==ite2->second.end()){
                                                ite2->second.insert(nodei->parent);
                                            }      
                                        }
                                    }

                                    if(nodej->parent->height == hindex){
                                        auto ite2 = mvtemp.find(nodej->val);
                                        if(ite2 == mvtemp.end()){
                                            mvtemp.insert({nodej->val,{nodej->parent}});
                                        }
                                        else{
                                            if(ite2->second.find(nodej->parent)==ite2->second.end()){
                                                ite2->second.insert(nodej->parent);
                                            }      
                                        }
                                    }
                                }
                            }
                            else{

                            }
                        }
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

int main(){
    Solution solution;
    vector<vector<string>> paths = {
        {"a"},{"a","x"},{"a","x","y"},{"a","z"},{"b"},{"b","x"},{"b","x","y"},{"b","z"},{"b","w"},{"c"},{"c","y"}
    };

    auto ret = solution.deleteDuplicateFolder(paths);

    return 0;
}