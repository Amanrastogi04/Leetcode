//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int index,int w,int wt[],int val[]){
        
        if(index==0){
           return (w/wt[index])*val[index];

        }
        
        int nottake=solve(index-1,w,wt,val);
        int take=-1e8;
        if(wt[index]<=w) take=val[index]+solve(index,w-wt[index],wt,val);
        
        return max(take,nottake);
        
    }
    
    
    int solveMem(int index,int w,int wt[],int val[],vector<vector<int>>&dp){
        
        if(index==0){
           return (w/wt[index])*val[index];

        }
        
        if(dp[index][w]!=-1){
            return dp[index][w];
        }
        
        int nottake=solveMem(index-1,w,wt,val,dp);
        int take=-1e8;
        if(wt[index]<=w) take=val[index]+solveMem(index,w-wt[index],wt,val,dp);
        
        return dp[index][w]=max(take,nottake);
        
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // return solve(N-1,W,wt,val);
        
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solveMem(N-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends