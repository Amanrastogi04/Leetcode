//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int index,int w,int wt[],int val[]){
        if(index==0){
            if(wt[index]<=w) return val[0];
            else return 0;
        }
        
        int nottake=solve(index-1,w,wt,val);
        int take=INT_MIN;
        if(wt[index]<=w){
            take=val[index]+solve(index-1,w-wt[index],wt,val);
        }
        
        return max(take,nottake);
    }
    
    
    int solveMem(int index,int w,int wt[],int val[],vector<vector<int>> &dp){
        if(index==0){
            if(wt[index]<=w) return val[0];
            else return 0;
        }
        
        if(dp[index][w]!=-1){
            return dp[index][w];
        }
        
        int nottake=solveMem(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(wt[index]<=w){
            take=val[index]+solveMem(index-1,w-wt[index],wt,val,dp);
        }
        
        return dp[index][w]=max(take,nottake);
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //  return solve(n-1,W,wt,val);
        
        // vector<vector<int>> dp(n,vector<int>(W+1,-1));
        // return solveMem(n-1,W,wt,val,dp);
        
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int nottake=dp[i-1][w];
                int take=INT_MIN;
                if(wt[i]<=w){
                    take=val[i]+dp[i-1][w-wt[i]];
                }
                
                dp[i][w]=max(take,nottake);
            }
        }
        
        return dp[n-1][W];
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends