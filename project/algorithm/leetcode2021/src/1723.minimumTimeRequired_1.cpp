#include"leetcode.h"

class Solution {
private:
    bool check(vector<int>& jobs, int k,int value){
        int n = jobs.size();
        vector<int> visit(n,0);
        map<int,int> um;
        unordered_map<int,int> temp;
        int kk = k;
        int vvalue;
        while(kk>0){
            um.clear();
            for(int i = 0; i < n; i ++){
                if(visit[i]==1){continue;}
                if(jobs[i]>value){continue;}
                
                temp.insert({jobs[i],i});
                for(map<int,int>::iterator ite = um.begin();ite!=um.end();ite++){
                    vvalue = ite->first + jobs[i];
                    if(vvalue <= value){
                        if(um.find(vvalue)==um.end() && temp.find(vvalue)==temp.end()){
                            temp.insert({vvalue,i});
                        }
                        //else{break;}
                    }
                    else{
                        break;
                    }
                }
            

                for(unordered_map<int,int>::iterator ite = temp.begin();ite!=temp.end();ite++){
                    um.insert({ite->first,ite->second});
                }
                temp.clear();                
            }
            if(um.empty()){break;}
            map<int,int>::iterator ite = um.end();
            ite--;
            int j = ite->first;
            while(j!=0){
                visit[um[j]] = 1;
                j = j - jobs[um[j]];
            }
            kk --;
        }

        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                return false;
            }
        }
        return true;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(),greater<int>());
        int minvalue = jobs[0],maxvalue;
        int sumsvalue = 0;
        for(int i = 0; i < n; i ++){
            sumsvalue += jobs[i];
            minvalue = max(minvalue,jobs[i]);
        }
        maxvalue = sumsvalue;
        minvalue = max(minvalue,(int)ceil(1.0f * sumsvalue/k));
        int mid;
        while(minvalue<maxvalue){
            mid = (minvalue + maxvalue)>>1;
            if(check(jobs,k,mid)){
                maxvalue = mid;
            }
            else{
                minvalue = mid+1;
            }
        }
        return minvalue;
    }
};

// int main(){
//     Solution solution;
//     vector<int> jobs{3,4,5,6,7,8,9,6,14,11,12,13};
//     int k= 5;
//     auto ret = solution.minimumTimeRequired(jobs,k);
//     return 0;
// }