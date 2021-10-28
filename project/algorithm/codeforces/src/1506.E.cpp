#include"codeforces.h"

#define NMAX 200010
int q[NMAX];
char pvisit[NMAX];
int pmin[NMAX];
int pmax[NMAX];

class Solution_1506_E{
private:
    void caclpmin(int n){
        memset(pvisit,0,sizeof(char) * n);
        int i = 0,j = 1;
        int curmax = 0;
        for(i = 0; i < n; i ++){
            if(q[i] > curmax){
                pmin[i] = q[i];
                pvisit[q[i]] = 1;
                curmax = q[i];
            }
            else{
                while(pvisit[j] == 1){j++;}
                pmin[i] = j;
                pvisit[j] = 1;                
            }
        }
    }
    void caclpmax(int n){
        set<int> s;
        set<int>::iterator ite;
        for(int i = 1; i <= n; i ++){
            s.insert(i);
        }
        int curmax = 0;
        for(int i = 0; i < n; i ++){
            if(q[i] > curmax){
                pmax[i] = q[i];
                curmax = q[i];
                s.erase(q[i]);
            }
            else{
                ite = s.lower_bound(curmax);
                ite--;
                pmax[i] = (*ite);
                s.erase((*ite));
            }
        }
    }
public:
    void solve(int n){
       caclpmin(n);
       caclpmax(n);
    }
};
int main_1506_E(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t = read();
    Solution_1506_E solution;
    int n;
    for(int i = 0; i < t; i ++){
        n = read();
        for(int j = 0; j < n; j ++){
            q[j] = read();
        }

        solution.solve(n);
        for(int j = 0; j < n-1; j ++){
            write(pmin[j]);
            putchar(' ');
        }
        write(pmin[n-1]);
        putchar('\n');
        for(int j = 0; j < n-1; j ++){
            write(pmax[j]);
            putchar(' ');
        }
        write(pmax[n-1]);
        putchar('\n');
    }

    // fclose(stdin);
	// fclose(stdout);
}