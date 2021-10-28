#include"leetcode.h"

class Solution {
private:
    inline void converti2v(int key,vector<int>& v,vector<int> &needs){
        int n = v.size();
        int mul = 1;
        for(int i = 0; i < n; i ++){
            mul = (needs[i]+1);
            v[i] = key%mul;
            key /= mul;
        }
    }

    inline int convertv2i(vector<int>& v,vector<int> & needs){
        int n = v.size();
        int mul = 1;
        int key = 0;
        for(int i = 0; i < n; i ++){            
            key += v[i] * mul;
            mul *= (needs[i]+1);
        }
        return key;
    }
    inline bool vsubv(vector<int> &v1,vector<int> &v2,vector<int> &v3){
        int n = v1.size();
        for(int i = 0; i < n; i ++){
            v3[i] = v1[i] - v2[i];
            if(v3[i]<0){return false;}
        }
        return true;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int sn = special.size();
        auto cmp = [](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second){
                return a.first > b.first; 
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({convertv2i(needs,needs),0});
        int ret = INT_MAX; 
        pair<int,int> top;
        unordered_set<int> us;
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        vector<int> v3(n,0);
        int value;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            if(us.find(top.first)!=us.end()){continue;}
            if(top.second>=ret){break;}
            converti2v(top.first,v1,needs);
            value = top.second;
            for(int i = 0; i < n;i ++){
                value += price[i] * v1[i];
            }
            ret = min(ret,value);
            for(int i = 0; i < sn; i ++){
                if(vsubv(v1,special[i],v3)){
                    pq.push({convertv2i(v3,needs),top.second + special[i][n]});
                }
            }
        }
        return ret;
    }
};

// int main(){
//     vector<int> price{2,5,1};
//     vector<vector<int>> special{{3,0,0,5},{1,2,0,10},{0,0,10,8}};
//     vector<int> needs{3,2,6};

//     Solution solution;
//     auto ret = solution.shoppingOffers(price,special,needs);

//     return 0;
// }