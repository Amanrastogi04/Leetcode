//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long solve(int index,int buy,int n,vector<long long>&prices){
        
        if(index>=n){
            return 0;
        }
        
        if(buy==1){
            return max(-prices[index]+solve(index+1,0,n,prices),solve(index+1,1,n,prices));
        }
        
        return max(prices[index]+solve(index+2,1,n,prices),solve(index+1,0,n,prices));
        
    }
    
    
    long long solveMem(int index,int buy,int n,vector<long long>&prices,vector<vector<long long>> &dp){
        
        if(index>=n){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        long long p=0;
        
        if(buy==1){
            p=max(-prices[index]+solveMem(index+1,0,n,prices,dp),solveMem(index+1,1,n,prices,dp));
        }
        else{
        
        p=max(prices[index]+solveMem(index+2,1,n,prices,dp),solveMem(index+1,0,n,prices,dp));
        }
        
        return dp[index][buy]=p;
    }
    
    
    long long maximumProfit(vector<long long>&prices, int n) {
        
        // return solve(0,1,n,prices);
        // vector<vector<long long>> dp(n,vector<long long>(2,-1));
        
        // return solveMem(0,1,n,prices,dp);
        
        vector<vector<long long>> dp(n+2,vector<long long>(2,0));
        
        for(int index=n-1;index>=0;index--){
            
            dp[index][1]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);

        
        dp[index][0]=max(prices[index]+dp[index+2][1],dp[index+1][0]);
    
            
            
        }
        
        return dp[0][1];
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends