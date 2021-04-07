#include"leetcode.h"

#define MAX 1000000007ll
#define TREEMAX 100010
class SegMentTree{
public:
    struct TreeNode{
        int add;
        int mult;

        int l;
        int r;

        TreeNode* left;
        TreeNode* right;
        TreeNode(int _l,int _r):l(_l),r(_r),add(0),mult(1),left(nullptr),right(nullptr){}
    };

    struct addmult
    {
        int add;
        int mult;
        addmult(int _add,int _mult):add(_add),mult(_mult){};
    };
    
private:
    TreeNode* root;
    void _buildTree(TreeNode* node){
        if(node->l == node->r-1){return;}
        else{
            int mid = (node->l + node->r)>>1;
            node->left = new TreeNode(node->l,mid);
            _buildTree(node->left);
            node->right = new TreeNode(mid,node->r);
            _buildTree(node->right);
        }
    }

    void _add(TreeNode* node,int index,int add,int mult){
        if(node->l == node->r-1){node->add = add;node->mult = mult;return;}
        int mid = (node->l+node->r)>>1;
        if(index < mid){
            if(node->left==nullptr){node->left = new TreeNode(node->l,mid);}
            _add(node->left,index,add,mult);
        }
        else{
            if(node->right==nullptr){node->right = new TreeNode(mid,node->r);}
            _add(node->right,index,add,mult);
        }
        if(node->left != nullptr && node->right != nullptr){
            node->add = ((long long)node->left->add * (long long)node->right->mult + (long long)node->right->add) % MAX;
            node->mult = ((long long)node->left->mult * (long long)node->right->mult) % MAX;
        }
        else if(node->left!=nullptr){
            node->add = node->left->add;
            node->mult = node->left->mult;
        }
        else if(node->right!=nullptr){
            node->add = node->right->add;
            node->mult = node->right->mult;
        }
    }
    addmult _get(TreeNode* node,int l,int r){
        if(node->l == node->r-1){return addmult(node->add,node->mult);}
        if(node->l == l && node->r == r){return addmult(node->add,node->mult);}
        int mid = (node->l+node->r)>>1;
        addmult laddmult(0,1),raddmult(0,1);
        if(l < mid && node->left!=nullptr){
            laddmult = _get(node->left,l,min(mid,r));
        }
        if(r > mid&&node->right!=nullptr){
            raddmult = _get(node->right,max(mid,l),r);
        }
        return addmult(((long long)laddmult.add * (long long)raddmult.mult + (long long)raddmult.add) % MAX,((long long)laddmult.mult * (long long)raddmult.mult)%MAX);
    }
public:
    SegMentTree(int treesize){
        root = new TreeNode(0,treesize);
        //_buildTree(root);
    }
    void add(int index,int add,int mult){
        _add(root,index,add,mult);
    }

    addmult get(int l,int r){
        return _get(root,l,r);
    }
};


class Fancy {
public:
    int vn;
    int on;
    vector<char> vvalues;
    vector<int> vindex;

    SegMentTree st;
public:
    Fancy():st(TREEMAX) {
        vn = 0;
        on = 0;
        vvalues.clear();
    }
    
    void append(int val) {
        vn++;
        vindex.push_back(on);
        vvalues.push_back(val);
    }
    
    void addAll(int inc) {
        st.add(on,inc,1);        
        on++;

    }
    
    void multAll(int m) {
        st.add(on,0,m);   
        on++;

    }
    
    int getIndex(int idx) {
        if(idx>=vn){return -1;}
        int index = vindex[idx];
        SegMentTree::addmult am= st.get(index,on);
        return (((long long)vvalues[idx]*(long long)am.mult) + am.add) % MAX;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */


class Fancy2 {
public:
    int n;
    vector<unsigned long long> vvalues;
public:
    Fancy2() {
        n = 0;
        vvalues.clear();
    }
    
    void append(int val) {
        n++;
        vvalues.push_back(val);
    }
    
    void addAll(int inc) {
        for(int i = 0; i < n;i ++){
            vvalues[i] += inc;
            if(vvalues[i] >= (long long)MAX){vvalues[i] -= MAX;}
        }
    }
    
    void multAll(int m) {
        for(int i = 0; i < n;i ++){
            vvalues[i] *= m;
            if(vvalues[i] >= (long long)MAX){vvalues[i] %= MAX;}
        }
    }
    
    int getIndex(int idx) {
        if(idx>=n){return -1;}
        return vvalues[idx];
    }
};

int main2(){
    Fancy fancy;
    Fancy2 fancy2;
    int n = 1000000;

    int rrr = rand() % 100;
    fancy.append(rrr);
    fancy2.append(rrr);
    for(int i = 0; i < n; i ++){
        int r = rand()% 4;
        int rr = rand()%100;
        switch (r)
        {
        case 0:
            fancy.append(rr);
            fancy2.append(rr);
            break;
        case 1:
            fancy.addAll(rr);
            fancy2.addAll(rr);
            break;
        case 2:
            fancy.multAll(rr);
            fancy2.multAll(rr);
            break;
        case 3:
            int idx = rand() % (fancy.vn + 10);
            auto ret = fancy.getIndex(idx);
            // auto ret2 = fancy2.getIndex(idx);
            // if(ret != ret2){
            //     cout<<"error"<<endl;
            // }
            break;
        
        // default:
        //     break;
        }

        for(int i = 0; i < fancy.vn;i ++){
            auto ret = fancy.getIndex(i);
            auto ret2 = fancy2.getIndex(i);
            if(ret!=ret2){
                cout<<"error"<<endl;
            }
        }
    }

    return 0;
}