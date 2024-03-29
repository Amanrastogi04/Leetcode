//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    
    int solve(int a,int b){
        if(a==0 && b==0){
            return 1;
        }
        
        if(a<0 || b<0){
            return 0;
        }
        
        int up=solve(a-1,b);
        int left=solve(a,b-1);
        
        return up+left;
        
    }
    
    int solveMem(int a,int b,vector<vector<int>> &dp){
        if(a==0 && b==0){
            return 1;
        }
        
        if(a<0 || b<0){
            return 0;
        }
        
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        
        int up=solveMem(a-1,b,dp);
        int left=solveMem(a,b-1,dp);
        
        return dp[a][b]=up+left;
        
    }
    
    
    int NumberOfPath(int a, int b)
    {
        // return solve(a-1,b-1);
        // vector<vector<int>> dp(a,vector<int>(b,-1));
        // return solveMem(a-1,b-1,dp);
        
        vector<int> prev(b,0);
        
        for(int i=0;i<a;i++){
             vector<int> temp(b,0);
            for(int j=0;j<b;j++){
                if(i==0 && j==0) temp[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=temp[j-1];
                    }
                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        
        return prev[b-1];
        
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends