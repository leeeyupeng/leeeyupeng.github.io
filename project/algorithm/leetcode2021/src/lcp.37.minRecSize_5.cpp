#include"leetcode.h"

#define MAXK 10010
class Solution {
private:
    inline void intersection(int k1,int b1,int k2,int b2, pair<double,double> &ret){
       ret.first = 1.0 * (b2 - b1) / (k1 - k2);
       ret.second = 1.0 * k1 * (b2 - b1) / (k1 - k2) + b1;
    }
    inline void mergemin(pair<double,double> rect[2],pair<double,double> &point){
        if(point.first  < rect[0].first){
            rect[0].first = point.first;
        }

        if(point.second < rect[0].second){
            rect[0].second = point.second;
        }  }

    inline void mergemax(pair<double,double> rect[2],pair<double,double> &point){
        if(point.first > rect[1].first){
            rect[1].first = point.first;
        }

        if(point.second > rect[1].second){
            rect[1].second = point.second;
        }
    }

    inline double rectsize(pair<double,double> rect[2]){
        return abs(rect[1].first - rect[0].first) * abs(rect[1].second - rect[0].second);            
    }
public:
    double minRecSize(vector<vector<int>>& lines) {
        vector<pair<int,int>> v(MAXK,{INT_MAX,INT_MIN});
        int n = lines.size();
        int k;
        int b;
        int mink=INT_MAX,maxk=INT_MIN;
        vector<int> vv;
        for(int i = 0; i < n; i ++){
            k = lines[i][0];
            b = lines[i][1];
            if(v[k].first == INT_MAX){
                vv.push_back(k);
            }
            v[k].first = min(v[k].first,b);
            v[k].second = max(v[k].second,b);
            mink = min(mink,k);
            maxk = max(maxk,k);
        }
        sort(vv.begin(),vv.end());
        int vvn = vv.size();
        pair<double,double> point;
        pair<double,double> rect[2];
        bool firstpoint = true;
        int iminb,imaxb,jminb,jmaxb;
        int ik,jk;
        for(int i = 0; i < vvn;i++){  
            ik = vv[i]; 
            iminb = v[ik].first;
            imaxb = v[ik].second;   
            for(int j = i+1; j < vvn; j ++){
                jk = vv[j];
                jminb = v[jk].first;
                jmaxb = v[jk].second;
                                  
                intersection(ik,iminb,jk,jmaxb,point);
                if(firstpoint == true){rect[0] = point,rect[1] = point;firstpoint = false;}
                else{
                    mergemin(rect,point);
                }
                if(iminb == imaxb && jminb == jmaxb){
                    mergemax(rect,point);
                    continue;
                }
                intersection(ik,imaxb,jk,jminb,point);
                mergemax(rect,point);                
            }
        }
        if(firstpoint == true){return 0;}
        return rectsize(rect);
    }
};

// int main(){
//     vector<vector<int>> lines{

//     };

//     Solution solution;
//     auto ret = solution.minRecSize(lines);
//     return 0;
// }