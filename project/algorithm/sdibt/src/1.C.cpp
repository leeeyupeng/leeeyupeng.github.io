#include <iostream>
#include <vector>
#include<string>
using namespace std;

#define MAXN 305
class Solution{
private:
    bool isdirection(pair<int,int> a,pair<int,int> b,pair<int,int> c){
        int ab = (a.first * b.first + a.second * b.second);
        int bc = (b.first * c.first + b.second*c.second);
        if(ab * bc< 0){return false;}
        return ab * ab * (c.first * c.first + c.second * c.second)
        ==bc * bc * (a.first * a.first + a.second * a.second);
    }
    bool getdirection(pair<int,int> a,pair<int,int> b){
        int abcross = a.first*b.second - a.second * b.first;
        if(abcross>0){return true;}
        else if(abcross == 0){
            if(a.first*b.first + a.second+b.second > 0){return true;}
        }
        return false;
    }
    int getbeads(int n,pair<int,int> vec[MAXN],int x,int y,int z){
        pair<int,int> a{vec[y].first - vec[x].first,vec[y].second - vec[x].second};
        pair<int,int> b{vec[z].first - vec[y].first,vec[z].second - vec[y].second};
        pair<int,int> c;
        int ret = 0;
        for(int i = z+1;i < n; i ++){
            if(n-i<=ret){break;}
            c={vec[i].first - vec[z].first,vec[i].second - vec[z].second};
            if(isdirection(a,b,c)){
                ret = max(ret,1+getbeads(n,vec,y,z,i));
            }
        }
        return ret;
    }
public:
    void Solve(int n,pair<int,int> vec[MAXN]){
        int ret = -1;
        bool dir = true;
        int temp;
        for(int i = 0; i < n; i ++){
            if(n-i-1+3<=ret+3){break;}
            for(int j = i+1;j < n;j++){
                if(n-j-1+3<=ret+3){break;}
                for(int z = j + 1;z<n;z++){
                    if(n-z-1+3<=ret+3){break;}
                    {
                        temp = getbeads(n,vec,i,j,z);
                        if(temp>ret){
                            ret = temp;
                            dir = getdirection({vec[j].first - vec[i].first,vec[j].second - vec[i].second},{vec[z].first - vec[j].first,vec[z].second - vec[j].second});
                        }
                    }
                }
            }
        }

        if(ret + 3== n){
            cout<<(dir?"C":"CC")<<endl;
        }
        else{
            printf("Remove %d bead(s), %s\n",n - (ret+3),(dir?"C":"CC"));
        }
        cout<<endl;
    }
};

// int main(){
//     int n = 0;  
//     pair<int,int> vec[MAXN];
//     Solution solution;
//     while(cin>>n && n > 0){
//         //n = 300;
//         for(int i = 0; i < n; i ++){
//             cin>>vec[i].first>>vec[i].second;
//             // vec[i].first = rand()%10000;
//             // vec[i].second = rand()%10000;
//         }

//         solution.Solve(n,vec);
//     } 
//     return 0;
// }