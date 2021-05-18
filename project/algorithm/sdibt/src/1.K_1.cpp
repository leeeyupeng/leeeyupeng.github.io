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

#define MAXOPER 200100
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
    };

    int cnt;
    set<xy>  s;

    //线段树
    int st[MAXOPER<<2];
    //查询lr之间最大值大于y的最小x
    int query(int l,int r,int node,int x,int y){
        if(x>=r){return -1;}
        if(st[node]<=y){return -1;}
        //if(x<=l){if(st[node]>y){return l;}else{return -1;}}
        if(l==r-1){if(st[node]>y){return l;}else{return -1;}}
        int mid = (l+r)>>1;
        int ret=-1;
        if(x<mid){ret =query(l,mid,node<<1,x,y);}
        if(ret!=-1){return ret;}
        if(x<r){
            ret = query(mid,r,(node<<1)+1,max(mid,x),y);
        }
        return ret;
    }
    void update(int l,int r,int node,int x,int y){
        if(l==r-1){st[node] = y;return;}
        int mid = (l+r)>>1;
        if(mid > x){update(l,mid,node<<1,x,y);}
        else{update(mid,r,(node<<1) + 1,x,y);}
        st[node] = max(st[node<<1],st[(node<<1)+1]);
    }
public:
    void init(int _cnt){
        cnt = _cnt;
        s.clear();
        memset(st,-1,sizeof(int) * (MAXOPER<<1));
    }
    void addelement(int x,int y){
        xy p = {x,y};
        s.insert(p);
        set<xy>::iterator ite=s.lower_bound({x+1,-1});
        ite--;
        update(0,cnt,1,x,ite->y);
    }
    void removeelement(int x,int y){
        xy p = {x,y};
        s.erase(p);

        set<xy>::iterator ite=s.lower_bound({x+1,-1});
        if(ite!=s.begin()){
            ite--;
            if(ite->x == x){
                update(0,cnt,1,x,ite->y);
            }
            else{
                update(0,cnt,1,x,-1);
            }
        }
        else{
            update(0,cnt,1,x,-1);
        }
    }
    pair<int,int> get(int x,int y){
        int x1 = query(0,cnt,1,x+1,y);
        if(x1==-1){return {-1,-1};}
        set<xy>::iterator ite = s.lower_bound({x1,y+1});
        return {ite->x,ite->y};
    }
};

int casecounter = 0;
int n = 0;

struct Oper{
    char flag;
    int x;
    int y;
};
//操作
Oper Opers[MAXOPER];

//离散化
int dis[MAXOPER];
int cnt;
void initdis(){
    int _dis[MAXOPER];
    for(int i = 0; i < n; i ++){
        _dis[i] = Opers[i].x;
    }
    sort(_dis,_dis+n);
    cnt = 0;
    dis[0] = _dis[0];cnt++;
    for(int i = 1; i < n; i ++){
        if(_dis[i]!=_dis[i-1]){
            dis[cnt++] = _dis[i];
        }
    }
}
int getdis(int x){
    int i = 0,j = cnt;
    int mid;
    while(i<j){
        mid = (i+j)>>1;
        if(dis[mid]<x){
            i = mid+1;
        }
        else{
            j = mid;
        }
    }
    return i;
}
// int main(){
//     string oper;
//     int x,y;
//     pair<int,int> value;
    
//     Solution solution;
//     while(cin>>n && n > 0){
        
//         //n  = 200000;

//         casecounter++;
//         printf("Case %d:\n",casecounter);
//         for(int i = 0; i < n; i ++){
//             cin>>oper>>Opers[i].x>>Opers[i].y;

//             // int o = rand() % 3;
//             // if(o==0){oper = "add";}
//             // else if(o == 1){oper = "remove";}
//             // else{oper="find";}
//             // Opers[i].x = rand() % 1000000000;
//             // Opers[i].y = rand() % 1000000000;
//             if(oper[0] == 'a'){
//                 Opers[i].flag = 0;
//             }
//             else if(oper[0] == 'r'){
//                 Opers[i].flag = 1;
//             }
//             else if(oper[0] == 'f'){
//                 Opers[i].flag = 2;
//             }
//         }

//         //离散化
//         initdis();

//         solution.init(cnt);

//         int xdis=0;
//         for(int i = 0; i < n; i ++){
//             x = getdis(Opers[i].x);
//             y = Opers[i].y;
//             if(Opers[i].flag == 0){
//                 solution.addelement(x,y);
//             }
//             else if(Opers[i].flag  == 1){
//                 solution.removeelement(x,y);
//             }
//             else if(Opers[i].flag == 2){
//                 value = solution.get(x,y);
//                 if(value.first == -1){
//                     printf("-1\n");
//                 }
//                 else{
//                     printf("%d %d\n",dis[value.first],value.second);
//                 }
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }