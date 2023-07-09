//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int solve(int *arr,int index){
	    if(index==0) return arr[index];
	    
	    if(index<0) return 0;
	    
	    int pick=arr[index]+solve(arr,index-2);
	    int notpick=solve(arr,index-1);
	    
	    return max(pick,notpick);
	}
	
	int solveMem(int *arr,int index,vector<int> &dp){
	    if(index==0) return arr[index];
	    
	    if(index<0) return 0;
	    
	    if(dp[index]!=-1){
	        return dp[index];
	    }
	    
	    int pick=arr[index]+solveMem(arr,index-2,dp);
	    int notpick=solveMem(arr,index-1,dp);
	    
	    return dp[index]=max(pick,notpick);
	}
	
	
	
	int findMaxSum(int *arr, int n) {
	   // return solve(arr,n-1);
	   vector<int> dp(n+1,-1);
	   return solveMem(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends