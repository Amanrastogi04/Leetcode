//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int solve(int index,int n,int price []){
        
        if(index==0){
            return n*price[index];
        }
        
        
        int nottake=solve(index-1,n,price);
        int take=-1e8;
        int rodlen=index+1;
        if(rodlen<=n){
            take=price[index]+solve(index,n-rodlen,price);
        }
        
        return max(take,nottake);
    }
    
    
    int solveMem(int index,int n,int price [],vector<vector<int>> &dp){
        
        if(index==0){
            return n*price[index];
        }
        
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
        
        
        int nottake=solveMem(index-1,n,price,dp);
        int take=-1e8;
        int rodlen=index+1;
        if(rodlen<=n){
            take=price[index]+solveMem(index,n-rodlen,price,dp);
        }
        
        return dp[index][n]=max(take,nottake);
    }
    
    
    int cutRod(int price[], int n) {
        // solve(n-1,n,price);
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solveMem(n-1,n,price,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends