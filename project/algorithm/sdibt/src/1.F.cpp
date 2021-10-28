#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<ctime>
#if defined(linux)
#include<math.h>
#include<memory.h>
#include<limits.h>
#endif
using namespace std;

#define MAXN 31
class Solution{
private:
    int n;
    char matrix[MAXN][MAXN];
    bool islegal(pair<int,int> pos){
        return pos.first >= 0 && pos.first<n && pos.second>=0 && pos.second<n;
    }
    char convert(int t,int x,int y){
        return (matrix[x][y] + t) % 4;
    }
    pair<int,int> offset1[4]{{0,1},{0,-1},{1,0},{-1,0}};
    pair<int,int> step1(int t,pair<int,int> start){
        pair<int,int> step = offset1[(int)convert(t,start.first,start.second)];
        pair<int,int> target={start.first + step.first,start.second+step.second};
        if(islegal(target)){return target;}
        else{return start;} 
    }
    int distanceab(pair<int,int> a,pair<int,int> b){
        //return abs(b.first - a.first) + abs(b.second - a.second);
        return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
    }
    pair<int,int> offset2[5]{{0,0},{0,1},{0,-1},{-1,0},{1,0}};
    pair<int,int> step2(pair<int,int> start,pair<int,int> treasurepos){
        pair<int,int> next=start;
        int distance = INT_MAX;
        pair<int,int> tempnext;
        int tempdistance;
        pair<int,int> step;
        for(int i = 0; i < 5; i ++){
            step = offset2[i];
            tempnext = {start.first+step.first,start.second+step.second};
            if(!islegal(tempnext)){continue;}
            tempdistance = distanceab(tempnext,treasurepos);
            if(tempdistance<distance){
                next = tempnext;
                distance = tempdistance;
            }
        }
        return next;
    }
    bool issuccess(pair<int,int> a,pair<int,int> b){
        return a.first == b.first && a.second == b.second;
    }
    unordered_set<int>  us;
    bool isexist(int t,pair<int,int> sayapos,pair<int,int> treasurepos){
        int key = (t%4) * n * n * n * n + sayapos.first * n * n *n + sayapos.second * n * n + treasurepos.first *n + treasurepos.second;
        if(us.find(key) != us.end()){
            return true;
        }
        return false;
    }
public:
    void init(int n){
        us.clear();
        this->n = n;        
    }
    void setmatrix(int x,int y,char value){
        matrix[x][y] = value;
    }

    string Solve(){
        int t = 0;
        pair<int,int> saya= {0,0};
        pair<int,int> treasure = {n-1,n-1};
        while(t<100){
            
            saya = step1(t,saya);
            saya = step2(saya,treasure);
            treasure=step1(t,treasure);
            t++;
            if(issuccess(saya,treasure)){
                return "Get the treasure! At step "+to_string(t)+".";
            }
            else if(isexist(t,saya,treasure)){
                return "Impossible. At step "+to_string(t)+".";
            }
            else{

            }        
        }
        return "Not sure.";
    }
};

// int main(){
//     int casecounter = 0;
//     int n = 0;
//     char d;
//     char value;
//     Solution solution;
//     while(cin>>n && n > 0){
//         solution.init(n);
//         for(int i = 0; i < n; i ++){
//             for(int j = 0; j < n; j ++){
//                 cin>>d;
//                 switch (d)
//                 {
//                 case 'E':
//                     value = 0;
//                     break;
//                 case 'W':
//                     value = 1;
//                     break;
//                 case 'S':
//                     value = 2;
//                     break;
//                 case 'N':
//                     value = 3;
//                     break;
//                 default:
//                     break;
//                 }

//                 solution.setmatrix(i,j,value);
//             }
//         }
//         casecounter++;
//         printf("Case %d:\n",casecounter);
//         cout<<solution.Solve()<<endl;
//         cout<<endl;
//     }
// }