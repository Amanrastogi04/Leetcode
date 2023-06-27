//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int st=0,end=n-1,f=n,l=n;
    
    while(st<=end){
        int mid=(st+end)/2;
        
        if(arr[mid]>=x){
            f=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    
    st=0,end=n-1;
    
    while(st<=end){
        int mid=(st+end)/2;
        
        if(arr[mid]>x){
            l=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
    
    if(f==n || arr[f]!=x){
        return {-1,-1};
    }
    
    return {f,l-1};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends