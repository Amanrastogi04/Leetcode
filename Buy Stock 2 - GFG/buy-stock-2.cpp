//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long solve(int index,int buy,vector<long long>&prices){
        if(index==prices.size()) return 0;
        
        long long profit=0;
        
        
        
        if(buy){
            profit=max(-prices[index]+solve(index+1,0,prices),solve(index+1,1,prices));
        }
        else{
            profit=max(prices[index]+solve(index+1,1,prices),solve(index+1,0,prices));
        }
        
        return profit;
        
    }
    
    
    long long solveMem(int index,int buy,vector<long long>&prices,vector<vector<int>> &dp){
        if(index==prices.size()) return 0;
        
        long long profit=0;
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        if(buy){
            profit=max(-prices[index]+solveMem(index+1,0,prices,dp),solveMem(index+1,1,prices,dp));
        }
        else{
            profit=max(prices[index]+solveMem(index+1,1,prices,dp),solveMem(index+1,0,prices,dp));
        }
        
        return dp[index][buy]=profit;
        
    }
    
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // return solve(0,1,prices);
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solveMem(0,1,prices,dp);
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