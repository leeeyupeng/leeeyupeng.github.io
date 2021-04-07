#include"codeforces.h"

#define RCMAX 200010
pair<int,int> rc[RCMAX];
class Solution_1506_F{
private:
    inline int getcost(pair<int,int> &a,pair<int,int> &b){
        pair<int,int> c = {b.first - a.first,b.second - a.second};
        int r = c.second;
        int l = c.first - c.second;
        int ret = 0;
        if(((a.first + a.second) & 0x1) == 0x0){
            if(l>0){
                ret = l >> 1;
            }
            else{
                ret = r;
            }
        }
        else{
            ret = (l+1)>>1;
        }
        return ret;
    }
public:
    int solve(int n){
        sort(rc,rc+n,[](pair<int,int> &a,pair<int,int> &b){
            return a.first < b.first;
        });
        pair<int,int> start{1,1};
        auto ret = getcost(start,rc[0]);
        for(int i = 1; i < n; i ++){
            ret += getcost(rc[i-1],rc[i]);
        }
        return ret;
    }
};
int main_1506_F(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t = read();
    Solution_1506_F solution;
    int n;
    for(int i = 0; i < t; i ++){
        n = read();
        for(int j = 0; j < n; j ++){
            rc[j].first = read();
        }
        for(int j = 0; j < n; j ++){
            rc[j].second = read();
        }

        auto ret = solution.solve(n);
        write(ret);
        putchar('\n');
    }
}