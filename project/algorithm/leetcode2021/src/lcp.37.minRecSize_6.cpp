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
        if(vvn==1){return 0;}
        pair<double,double> point;
        pair<double,double> rect[2];
        bool firstpoint = true;
        int iminb,imaxb,jminb,jmaxb;
        int ik,jk;
        double minx,maxx;
        double miny,maxy;
        for(int i = 0; i < vvn-1;i++){  
            ik = vv[i]; 
            iminb = v[ik].first;
            imaxb = v[ik].second;
            jk = vv[i+1];
            jminb = v[jk].first;
            jmaxb = v[jk].second;
            minx = 1.0 * (jmaxb - iminb) / (ik - jk);
            maxx = 1.0*(jminb - imaxb) / (ik - jk);
            for(int j = i+2; j < vvn; j ++){
                jk = vv[j];
                jminb = v[jk].first;
                jmaxb = v[jk].second;
                minx = min(minx,1.0 * (jmaxb - iminb) / (ik - jk));
                maxx = max(maxx,1.0*(jminb - imaxb) / (ik - jk));
            }
            miny = ik * minx + iminb;
            maxy = ik * maxx + imaxb;
            if(firstpoint == true){rect[0] = {minx,miny},rect[1] = {maxx,maxy};firstpoint = false;}
            else{
                rect[0].first = min(rect[0].first,minx);
                rect[0].second = min(rect[0].second,miny);
                rect[1].first = max(rect[1].first,maxx);
                rect[1].second = max(rect[1].second,maxy);
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