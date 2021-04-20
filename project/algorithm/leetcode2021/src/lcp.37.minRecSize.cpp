#include"leetcode.h"

class Solution {
private:
    inline pair<pair<long long,long long>,pair<long long,long long>> intersection(vector<int> &a,vector<int> &b){
       pair<pair<long long,long long>,pair<long long,long long>> ret;
       ret.first.first = b[1] - a[1];
       ret.first.second = a[0] - b[0];
       ret.second.first = ret.first.first * a[0] + a[1] * ret.first.second;
       ret.second.second = a[0] - b[0];
       return ret;
    }
    inline void merge(pair<pair<long long,long long>,pair<long long,long long>> rect[2],pair<pair<long long,long long>,pair<long long,long long>> &point){
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
        int n = lines.size();
        sort(lines.begin(),lines.end(),[](vector<int> &a,vector<int> &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<int> v;
        v.push_back(0);
        for(int i = 1;  i < n; i ++){
            if(lines[i][0] == lines[i-1][0]){

            }
            else{
                if(v.back()!=i-1){
                    v.push_back(i-1);
                }
                v.push_back(i);
            }
        }
        if(v.back()!=n-1){
            v.push_back(n-1);
        }
        int vn = v.size();
        pair<pair<long long,long long>,pair<long long,long long>> point;
        pair<pair<long long,long long>,pair<long long,long long>> rect[2];
        bool firstpoint = true;
        for(int i = 0; i < vn;i++){
            for(int j = i+1; j < vn; j ++){
                if(lines[v[i]][0] != lines[v[j]][0]){                    
                    point = intersection(lines[v[i]],lines[v[j]]);
                    if(firstpoint == true){rect[0] = point,rect[1] = point;firstpoint = false;}
                    else{
                        merge(rect,point);
                    }
                }
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