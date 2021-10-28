#include"leetcode.h"


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
private:
    int dfs(unordered_map<int,Employee*> &um,int id){
        int ret = um[id]->importance;
        for(int i = 0; i < um[id]->subordinates.size();i++){
            ret+=dfs(um,um[id]->subordinates[i]);
        }
        return ret;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,Employee*> um;
        Employee* employee;
        for(int i = 0; i < n; i ++){
            employee = employees[i];
            um.insert({employee->id,employee});
        }
        int ret = dfs(um,id);
        return ret;
    }
};