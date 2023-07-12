//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int>prev(W+1,0);
        
        for(int i=0;i<=W;i++){
            prev[i]=((int)(i/wt[0]))*val[0];
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int nottake=prev[j];
                int take=-1e8;
                if(wt[i]<=j) take=val[i]+prev[j-wt[i]];
                
                prev[j]=max(take,nottake);
            }
        }
        
        return prev[W];
        
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