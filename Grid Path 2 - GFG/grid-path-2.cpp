//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int solve(int n,int m,vector<vector<int>>& grid){
        
        int M=1e9+7;
        
        if(n>=0 && m>=0 && grid[n][m]==1){
            return 0;
        }
        
        if(n==0 && m==0){
            return 1;
        }
        
        if(n<0 || m<0){
            return 0;
        }
        
        
        
        int up=solve(n-1,m,grid);
        int left=solve(n,m-1,grid);
        
        return (up+left)%M;
    }
    
    int solveMem(int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        
        int M=1e9+7;
        
        if(n>=0 && m>=0 && grid[n][m]==1){
            return 0;
        }
        
        if(n==0 && m==0){
            return 1;
        }
        
        if(n<0 || m<0){
            return 0;
        }
        
        
        if(dp[n][m]!=-1){
            return dp[n][m]%M;
        }
        
        int up=solveMem(n-1,m,grid,dp);
        int left=solveMem(n,m-1,grid,dp);
        
        return dp[n][m]=(up+left)%M;
    }
    
    
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // return solve(n-1,m-1,grid);
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solveMem(n-1,m-1,grid,dp);
        
        int M=1e9+7;
        
        vector<int>prev(m,0);
        
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1) curr[j]=0;
                
                else if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=curr[j-1];
                    }
                    curr[j]=(up+left)%M;
                }
            }
            prev=curr;
        }
        
        return prev[m-1];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends