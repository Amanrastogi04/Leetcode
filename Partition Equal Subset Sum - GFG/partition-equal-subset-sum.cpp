//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solve(int index,int sum,int arr[]){
        if(sum==0) return 1;
        
        if(index==0) return arr[0]==sum;
        
        bool nottake=solve(index-1,sum,arr);
        bool take=false;
        if(sum>=arr[index]){
            take=solve(index-1,sum-arr[index],arr);
        }
        
        return take|nottake;
    }
    
    bool solveMem(int index,int sum,int arr[],vector<vector<int>> &dp){
        if(sum==0) return 1;
        
        if(index==0) return arr[0]==sum;
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        bool nottake=solveMem(index-1,sum,arr,dp);
        bool take=false;
        if(sum>=arr[index]){
            take=solveMem(index-1,sum-arr[index],arr,dp);
        }
        
        return dp[index][sum]=take|nottake;
    }
    
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2){
            return false;
        }
        
        int totsum=sum/2;
        
        // return solve(N,totsum,arr);
        
        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        return solveMem(N-1,totsum,arr,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends