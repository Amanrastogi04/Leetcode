//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int solve(int index,int buy,int cap,int n,int a[]){
        if(cap==0 || index==n){
            return 0;
        }
        
        if(buy==1){
            return max(-a[index]+solve(index+1,0,cap,n,a),solve(index+1,1,cap,n,a));
        }
        
        return max(a[index]+solve(index+1,1,cap-1,n,a),solve(index+1,0,cap,n,a));
        
    }
    
    
    int solveMem(int index,int buy,int cap,int n,int a[],vector<vector<vector<int>>> &dp){
        if(cap==0 || index==n){
            return 0;
        }
        
        if(dp[index][buy][cap]!=-1){
            return dp[index][buy][cap];
        }
        
        if(buy==1){
            return dp[index][buy][cap]=max(-a[index]+solveMem(index+1,0,cap,n,a,dp),solveMem(index+1,1,cap,n,a,dp));
        }
        
        return dp[index][buy][cap]=max(a[index]+solveMem(index+1,1,cap-1,n,a,dp),solveMem(index+1,0,cap,n,a,dp));
        
    }
    
    
    int maxProfit(int K, int N, int A[]) {
        // return solve(0,1,K,N,A);
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solveMem(0,1,K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends