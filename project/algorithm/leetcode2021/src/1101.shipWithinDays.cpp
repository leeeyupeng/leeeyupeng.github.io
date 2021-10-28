#include"leetcode.h"

class Solution {
private:
    bool check(vector<int>& weights, int D,int c){
        int n = weights.size();
        int i = 0;
        int weight = 0;
        int counter = 0;
        while(i<n){
            if(weights[i]>c){
                return false;
            }
            else if(weight + weights[i] <= c){
                weight += weights[i];
                i ++;
            }
            else{
                counter ++;
                weight = 0;
            }
        }
        if(weight!=0){
            counter++;
        }
        return D >= counter;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int sums = 0;
        int wmax = 0;
        for(int i = 0; i < n; i ++){
            sums+= weights[i];
            wmax = max(wmax,weights[i]);
        }
        int i = 1,j = 50000*500 + 1;
        i = max(sums/D,wmax);
        j = sums;
        int mid;
        while(i<j){
            mid = (i+j)>>1;
            if(check(weights,D,mid)){
                j = mid;
            }
            else{
                i = mid+1;
            }
        }
        return i;
    }
};

// int main(){
//     Solution solution;
//     vector<int> weights{1,2,3,4,5,6,7,8,9,10};
//     int D = 5;
//     auto ret = solution.shipWithinDays(weights,D);
//     return 0;
// } 