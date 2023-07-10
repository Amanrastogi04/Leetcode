//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int solve(int i,int j,int n,vector<vector<int>>& t){
        if(i==n-1){
            return t[n-1][j];
        }
        
        int down=t[i][j]+solve(i+1,j,n,t);
        int dg=t[i][j]+solve(i+1,j+1,n,t);
        
        return min(down,dg);
        
    }
    
    int solveMem(int i,int j,int n,vector<vector<int>>& t,vector<vector<int>>&dp){
        if(i==n-1){
            return t[n-1][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down=t[i][j]+solveMem(i+1,j,n,t,dp);
        int dg=t[i][j]+solveMem(i+1,j+1,n,t,dp);
        
        return dp[i][j]=min(down,dg);
        
    }
    
    
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        
        // return solve(0,0,n,triangle);
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solveMem(0,0,n,triangle,dp);
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,dg);
            }
            
        }
        
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends