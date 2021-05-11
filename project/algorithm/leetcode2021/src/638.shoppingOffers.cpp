#include"leetcode.h"

#define MAX 11
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
        int maxkey = convertv2i(needs,needs);
        vector<int> dp(maxkey+1,INT_MAX);
        int nn = 0;
        dp[0] = 0;
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        vector<int> v3(n,0);
        int key1;
        int key2;
        int key3;
        cout<<maxkey<<endl;
        for(int i = 1; i <= maxkey; i ++){
            converti2v(i,v1,needs);
            if(vsubv(needs,v1,v3)){
                dp[i] = 0;
                for(int j = 0; j < n; j ++){
                    dp[i] += price[j] * v1[j];
                }
                for(int j = 0; j < sn; j ++){
                    if(vsubv(v1,special[j],v3)){
                        key3 = convertv2i(v3,needs);
                        cout<<i<<endl;
                        cout<<key3<<endl;
                        cout<<dp[key3]<<endl;
                        if(dp[key3]==INT_MAX){
                            cout<<dp[key3]<<endl;
                        }
                        dp[i] = min(dp[i],dp[key3] + special[j][n]);
                    }
                }
            }
        }

        return dp[maxkey];
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