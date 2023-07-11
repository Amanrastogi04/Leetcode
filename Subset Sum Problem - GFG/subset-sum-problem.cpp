//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool solve(int index,int sum,vector<int>& arr){
        if(sum==0) return true;
        
        if(index==0){
            return arr[0]==sum;
        }
        
        bool nottake=solve(index-1,sum,arr);
        bool take=false;
        
        if(sum>=arr[index]){
            take=solve(index-1,sum-arr[index],arr);
        }
        
        return take||nottake;
    }
    
    bool solveMem(int index,int sum,vector<int>& arr,vector<vector<int>>&dp){
        if(sum==0) return true;
        
        if(index==0){
            return arr[0]==sum;
        }
        
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
    
    
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n=arr.size();
        // return solve(n-1,sum,arr);
        
        // vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        // return solveMem(n-1,sum,arr,dp);
        
        vector<bool> prev(sum+1,false),curr(sum+1,false);
        
        prev[0]=curr[0]=true;
        
        if(arr[0]<=sum){
        prev[arr[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=prev[j];
                bool take=false;
                
                if(arr[i]<=j){
                    take=prev[j-arr[i]];
                }
                
                curr[j]=take|nottake;
            }
            prev=curr;
        }
        
        return prev[sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends