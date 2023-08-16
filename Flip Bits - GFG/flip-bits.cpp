//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int zero=0,res=0,ans=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zero++;
                res=max(res,zero);
            }
            else{
                zero--;
                if(zero<0){
                    zero=0;
                }
                ans++;
            }
        }
        
        return ans+res;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends