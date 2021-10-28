#include"leetcode.h"

#define MAXK 10010
class Solution {
private:
    inline void intersection(int k1,int b1,int k2,int b2, pair<pair<long long,long long>,pair<long long,long long>> &ret){
       ret.first.first = b2 - b1;
       ret.first.second = k1 - k2;
       ret.second.first = ret.first.first * k1 + b1 * ret.first.second;
       ret.second.second = k1 - k2;
    }
    inline void mergemin(pair<pair<long long,long long>,pair<long long,long long>> rect[2],pair<pair<long long,long long>,pair<long long,long long>> &point){
        if(point.first.first * rect[0].first.second < rect[0].first.first * point.first.second){
            rect[0].first.first = point.first.first;
            rect[0].first.second = point.first.second;
        }

        if(point.second.first * rect[0].second.second < rect[0].second.first * point.second.second){
            rect[0].second.first = point.second.first;
            rect[0].second.second = point.second.second;
        }

        if(point.first.first * rect[1].first.second > rect[1].first.first * point.first.second){
            rect[1].first.first = point.first.first;
            rect[1].first.second = point.first.second;
        }

        if(point.second.first * rect[1].second.second > rect[1].second.first * point.second.second){
            rect[1].second.first = point.second.first;
            rect[1].second.second = point.second.second;
        }
    }

    inline void mergemax(pair<pair<long long,long long>,pair<long long,long long>> rect[2],pair<pair<long long,long long>,pair<long long,long long>> &point){
        if(point.first.first * rect[0].first.second < rect[0].first.first * point.first.second){
            rect[0].first.first = point.first.first;
            rect[0].first.second = point.first.second;
        }

        if(point.second.first * rect[0].second.second < rect[0].second.first * point.second.second){
            rect[0].second.first = point.second.first;
            rect[0].second.second = point.second.second;
        }

        if(point.first.first * rect[1].first.second > rect[1].first.first * point.first.second){
            rect[1].first.first = point.first.first;
            rect[1].first.second = point.first.second;
        }

        if(point.second.first * rect[1].second.second > rect[1].second.first * point.second.second){
            rect[1].second.first = point.second.first;
            rect[1].second.second = point.second.second;
        }
    }

    inline double rectsize(pair<pair<long long,long long>,pair<long long,long long>> rect[2]){
        double first1 = abs(rect[0].first.first * rect[1].first.second - rect[1].first.first * rect[0].first.second);
        double first2 = abs(rect[0].second.first * rect[1].second.second - rect[1].second.first * rect[0].second.second);
        double ret = first1 * first2 / double(rect[0].second.second * rect[1].second.second * rect[0].first.second * rect[1].first.second);
        return ret;            
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
        pair<pair<long long,long long>,pair<long long,long long>> point;
        pair<pair<long long,long long>,pair<long long,long long>> rect[2];
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