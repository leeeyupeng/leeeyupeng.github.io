//http://poj.org/problem?id=2926

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define MAXN 100010
#define MAXD 5
class Solution{
    
private:
    int n,d;
    double arr[MAXN][MAXD];
    inline double getsums(double a[],int dd){
        double sums = 0;
        for(int i = 0; i < d;i ++){
            if(((dd>>i)&0x1)==0x0){
                sums += a[i];
            }
            else{
                sums -= a[i];
            }
        }
        return sums;
    }
public:
    void init(int _n,int _d){
        this->n = _n;
        this->d = _d;
    }
    void insert(int nindex,int dindex,double value){
        arr[nindex][dindex] = value;
    }

    double solve(){
        {
            pair<double,double> minmax[1<<MAXD];
            double value=0;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < (1<<d);j++){
                    value = getsums(arr[i],j);
                    if(i==0){minmax[j]={value,value};}
                    else{
                        minmax[j].first = max(minmax[j].first,value);
                        minmax[j].second = min(minmax[j].second,value);
                    }
                }
            }

            double ret = 0;
            for(int j = 0; j < (1<<d);j ++){
                ret = max(ret,minmax[j].first - minmax[j].second);
            }
            return ret;
        }
    }
};
// int main(){
//     int testcases=1;
//     //cin>>testcases;
//     Solution solution;
//     int n;
//     int d=5;
//     double value;
//     while(cin>>n){
//         //cin>>n;//>>d;
//         solution.init(n,d);
//         for(int j = 0; j < n; j ++){
//             for(int id = 0; id < d; id ++){
//                 scanf("%lf",&value);
//                 //cin>>value;
//                 solution.insert(j,id,value);
//             }
//         }

//         double ret = solution.solve();
//         printf("%.2f\n",ret);
//         // cout<<setiosflags(ios::fixed)<<setprecision(2);
//         // cout<<ret<<endl;
//     }
//     return 0;
// }