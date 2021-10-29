//https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    void dfs(map<int,vector<int>>&g,vector<bool>&v,int src, int &count) {
         v[src] = true ; 
         count++ ; 
         for (int i : g[src]) {
             if (!v[i]) {
                 v[i] = true ; 
                 dfs(g,v,i,count) ; 
             }
         }
        return ; 
    }
    
    int minSwapsCouples(vector<int>& row) {
        map<int,int>m ; 
        int j = 0 ; 
        for (int i=0; i<row.size(); i+=2) {
            m[row[i]] = j ;
            m[row[i+1]] = j ; 
            j++ ; 
        }
        map<int,vector<int>>g ; 
        for (int i=0; i<row.size(); i+=2) {
            if (m[i] != m[i+1]) {
            g[m[i]].push_back(m[i+1]) ; 
            g[m[i+1]].push_back(m[i]) ;
            }
        }
        int swap = 0 ; 
        vector<bool>v (60,false) ; 
        for (int i=0; i<row.size(); i++) {
            int count = 0 ; 
            if (!v[i]) {
                dfs(g,v,i,count) ;
                swap += (count - 1) ; 
            }
        }
        return swap ; 
    }
};
