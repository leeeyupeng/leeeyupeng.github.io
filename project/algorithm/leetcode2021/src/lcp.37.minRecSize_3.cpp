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
        for(int i = 0; i < n; i ++){
            k = lines[i][0];
            b = lines[i][1];
            v[k].first = min(v[k].first,b);
            v[k].second = max(v[k].second,b);
        }
        pair<double,double> point;
        pair<double,double> rect[2];
        bool firstpoint = true;
        int iminb,imaxb,jminb,jmaxb;
        for(int iK = 0; iK < MAXK;iK++){   
            iminb = v[iK].first;
            if(iminb == INT_MAX){continue;}
            imaxb = v[iK].second;   
            for(int jK = iK+1; jK < MAXK; jK ++){
                jminb = v[jK].first;
                if(jminb == INT_MAX){continue;}
                jmaxb = v[jK].second;
                                  
                intersection(iK,iminb,jK,jmaxb,point);
                if(firstpoint == true){rect[0] = point,rect[1] = point;firstpoint = false;}
                else{
                    mergemin(rect,point);
                }
                if(iminb == imaxb && jminb == jmaxb){
                    mergemax(rect,point);
                    continue;
                }
                intersection(iK,imaxb,jK,jminb,point);
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