#include"leetcode.h"

class Solution {
private:
    int offset[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int length;
    vector<vector<vector<char>>> dp;
    vector<vector<char>> visit;
    bool dfs(vector<vector<char>>& board,string& word,int i,int j,int index){   
        if(visit[i][j] == 1){return false;}   
        if(board[i][j] != word[index]){return false;}
        if(index == length-1){return true;}
        visit[i][j] = 1;
        //if(dp[i][j][index] != 0){return dp[i][j][index] == 1?true:false;}        
        int ii,jj;
        int ret = false;
        for(int k = 0; k < 4; k ++){
            ii = i + offset[k][0];
            jj = j + offset[k][1];
            if(ii >= 0 && ii < m && jj >= 0 && jj < n){
                ret |= dfs(board,word,ii,jj,index+1);
                if(ret){break;}
            }
        }
        visit[i][j] = 0;
        //dp[i][j][index] = ret?1:2;
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->length = word.length();
        //dp = vector<vector<vector<char>>>(m,vector<vector<char>>(n,vector<char>(length,0)));
        visit = vector<vector<char>>(m,vector<char>(n,false));
        bool ret = false;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                ret |= dfs(board,word,i,j,0);
                if(ret){return ret;}
            }
        }
        return ret;
    }
};