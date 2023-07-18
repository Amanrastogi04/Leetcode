//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


int solve(int index,int buy,vector<int>&price,int cap){
    if(cap==0) return 0;
    if(index==price.size()) return 0;
    
    int profit=0;
    
    if(buy){
        profit=max(-price[index]+solve(index+1,0,price,cap),solve(index+1,1,price,cap));
        
    }
    else{
        profit=max(price[index]+solve(index+1,1,price,cap-1),solve(index+1,0,price,cap));
    }
    
    return profit;
    
}


int solveMem(int index,int buy,vector<int>&price,int cap,vector<vector<vector<int>>> &dp){
    if(cap==0 || index==price.size()) return 0;

    
    
    
    if(dp[index][buy][cap]!=-1){
        return dp[index][buy][cap];
    }
    

    
    if(buy==1){
        return dp[index][buy][cap]= max(-price[index]+solveMem(index+1,0,price,cap,dp),solveMem(index+1,1,price,cap,dp));
        
    }
       
     return   dp[index][buy][cap]=max(price[index]+solveMem(index+1,1,price,cap-1,dp),solveMem(index+1,0,price,cap,dp));
    
}



int maxProfit(vector<int>&price){
    
    // return solve(0,1,price,2);
    int n=price.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solveMem(0,1,price,2,dp);
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends