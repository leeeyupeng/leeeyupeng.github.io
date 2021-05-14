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

#define MAXRC 302
#define MAXN 1010
class Solution{
private:
    struct xy
    {
        int x;
        int y;
        xy(int _x,int _y):x(_x),y(_y){}
        bool operator==(const xy &a){
            return this->x == a.x && this->y == a.y;
        }
        bool operator < (const xy &b) const{
            if(this->x < b.x){return true;}
            if(this->x == b.x && this->y < b.y){return true;}
            return false;
        }
        // bool operator > (const xy &b)const{
        //     if(this->x < b.x){return false;}
        //     if(this->x == b.x && this->y < b.y){return false;}
        //     return true;
        // }
    };
    set<xy>  s;
public:
    void addelement(int x,int y){
        xy p = {x,y};
        s.insert(p);
        // if(s.find(p)==s.end()){
        //     s.insert(p);
        // }
    }
    void removeelement(int x,int y){
        xy p = {x,y};
        s.erase(p);
        // if(s.find(p)!=s.end()){
        //     s.erase(p);
        // }
    }
    pair<int,int> get(int x,int y){
        xy p = {x,y};
        xy pp = {x+1,y+1};
        set<xy>::iterator ite;
        while(true)
        {            
            ite = s.lower_bound(pp);
            if(ite==s.end()){break;}
            if(ite->x == pp.x){
                return {ite->x,ite->y};
            }
            else{
                pp.x = ite->x;
            }
        }
        return {-1,-1};
    }
};
// int main(){
//     int casecounter = 0;
//     int n = 0;
//     string oper;
//     int x,y;
//     pair<int,int> value;
    
//     Solution solution;
//     while(cin>>n && n > 0){
//         //n  = 200000;
//         casecounter++;
//         printf("Case %d:\n",casecounter);
//         for(int i = 0; i < n; i ++){
//             cin>>oper>>x>>y;
//             // int o = rand() % 3;
//             // if(o==0){oper = "add";}
//             // else if(o == 1){oper = "remove";}
//             // else{oper="find";}
//             // x = rand() % 1000000000;
//             // y = rand() % 1000000000;
//             if(oper[0] == 'a'){
//                 solution.addelement(x,y);
//             }
//             else if(oper[0] == 'r'){
//                 solution.removeelement(x,y);
//             }
//             else if(oper[0] == 'f'){
//                 value = solution.get(x,y);
//                 if(value.first == -1){
//                     printf("-1\n");
//                 }
//                 else{
//                     printf("%d %d\n",value.first,value.second);
//                 }
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }