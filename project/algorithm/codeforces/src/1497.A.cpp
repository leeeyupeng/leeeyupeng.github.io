#include"codeforces.h"

#define NMAX 110
int nums[NMAX];
int ansnums[NMAX];
class Solution_1497_A{
public:
    void solve(int n){
        sort(nums,nums+n);
        int i = 0,j = n;
        ansnums[i] = nums[0];
        for(int k = 1; k < n; k ++){
            if(ansnums[i] < nums[k]){
                ansnums[++i] = nums[k];
            }
            else{
                ansnums[--j] = nums[k];
            }
        }
    }
};

int main_1497_A(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t = read();
    Solution_1497_A solution;
    int n;
    for(int i = 0; i < t; i ++){
        n = read();
        for(int j = 0; j < n; j ++){
            nums[j] = read();
        }

        solution.solve(n);
        for(int j = 0; j < n-1; j ++){
            write(ansnums[j]);
            putchar(' ');
        }
        write(ansnums[n-1]);        
        putchar('\n');
    }
}