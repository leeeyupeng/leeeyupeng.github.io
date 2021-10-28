#include"leetcode.h"

#define DIGITMAX 5
class Solution {
private:
    int MIN(int a,int b,int c){
        int ret = a;
        ret = min(ret,b);
        ret = min(ret,c);
        return ret;
    }
    int getnumber(int a,int b,int c){
        int minabc = MIN(a,b,c);
        int ret1 = minabc + (a-minabc)/3 + (b-minabc)/3+(c-minabc)/3;
        int ret2 = a/3+b/3+c/3;
        return max(ret1,ret2);
    }

    void state(int dp1[DIGITMAX][DIGITMAX],int dp2[DIGITMAX][DIGITMAX],int value){
        for(int i = 0; i < DIGITMAX; i ++){
            for(int j = i; j < DIGITMAX; j ++){
                if(value<j){
                    dp2[i][j] = -1;
                }
                else{
                    for(int jj = i; jj <DIGITMAX;jj++){
                        for(int ii = 0;ii<=jj;ii++) {
                            if(dp1[ii][jj]!=-1){
                                dp2[i][j] = max(dp2[i][j],dp1[ii][jj] + getnumber(ii,jj-i,value - j));
                            }
                        }
                    }                   
                }
            }
        }
    }

    void dpinit(int dp[DIGITMAX][DIGITMAX]){
        for(int i = 0; i < DIGITMAX; i ++){
            for(int j = 0; j < DIGITMAX; j ++){
                dp[i][j] = -1;
            }
        }
    }
    void dpcopy(int dp1[DIGITMAX][DIGITMAX],int dp2[DIGITMAX][DIGITMAX]){
        for(int i = 0; i < DIGITMAX; i ++){
            for(int j = 0; j < DIGITMAX; j ++){
                dp1[i][j] = dp2[i][j];
            }
        }
    }
    int getnubmerdp(int dp[DIGITMAX][DIGITMAX]){
        int ret = 0;
        for(int i = 0; i < DIGITMAX; i ++){
            for(int j = 0; j < DIGITMAX; j ++){
                if(dp[i][j]!=-1){
                    ret = max(ret,dp[i][j] + getnumber(i,j,0));
                }
            }
        }
        return ret;
    }
public:
    int maxGroupNumber(vector<int>& tiles) {
        int n = tiles.size();
        sort(tiles.begin(),tiles.end());
        vector<pair<int,int>> vnums;
        int i=0;
        int k;
        for(k = 1; k < n; k ++){
            if(tiles[k] == tiles[i]){continue;}
            else{
                vnums.push_back({tiles[i],k - i});
                i = k;
            }
        }
        vnums.push_back({tiles[i],k - i});
        int dp1[DIGITMAX][DIGITMAX];
        int dp2[DIGITMAX][DIGITMAX];
        dpinit(dp1);
        

        int vn = vnums.size();
        dp1[0][0] = 0;
        dpinit(dp2);
        state(dp1,dp2,vnums[0].second);
        dpcopy(dp1,dp2);
        dpinit(dp2);
        int ret = 0;
        for(int i = 1; i < vn; i ++){
            if(vnums[i].first == vnums[i-1].first+1){
                state(dp1,dp2,vnums[i].second);
                dpcopy(dp1,dp2);
                dpinit(dp2);
            }
            else{
                ret += getnubmerdp(dp1);
                dpinit(dp1);
                dp1[0][0] = 0;
                state(dp1,dp2,vnums[i].second);
                dpcopy(dp1,dp2);
                dpinit(dp2);
            }
        }
        ret += getnubmerdp(dp1);
        return ret;
    }
};

// int main(){
//     vector<int> tiles{
// 2,2,2,3,4,5,5,5,5,6,6,6,7,7,7,8,8,9,9,9,9,9,9,15,16,16,16,17,17,17,18,18
//     };

//     Solution solution;
//     auto ret = solution.maxGroupNumber(tiles);

//     return 0;
// }