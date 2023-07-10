//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int n,int m,int s,vector<vector<int>> &matrix){
        if(m<0 || m>=s){
            return -1e8;
        }
        
        if(n==0){
            return matrix[0][m];
        }
        
        int up=matrix[n][m]+solve(n-1,m,s,matrix);
        int right=matrix[n][m]+solve(n-1,m+1,s,matrix);
        int left=matrix[n][m]+solve(n-1,m-1,s,matrix);
        
        return max(up,max(right,left));
        
    }
    
    int solveMem(int n,int m,int s,vector<vector<int>> &matrix,vector<vector<int>>&dp){
        if(m<0 || m>=s){
            return -1e8;
        }
        
        if(n==0){
            return matrix[0][m];
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        int up=matrix[n][m]+solveMem(n-1,m,s,matrix,dp);
        int right=matrix[n][m]+solveMem(n-1,m+1,s,matrix,dp);
        int left=matrix[n][m]+solveMem(n-1,m-1,s,matrix,dp);
        
        return dp[n][m]=max(up,max(right,left));
        
    }
    
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // int ans=-1e8;
        // for(int i=0;i<N;i++){
        //     ans=max(ans,solve(N-1,i,N,Matrix));
        // }
        
        // return ans;
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        int ans=-1e8;
        for(int i=0;i<N;i++){
            ans=max(ans,solveMem(N-1,i,N,Matrix,dp));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends