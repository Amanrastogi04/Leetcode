//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    int count(int pages,int a[],int n){
        int sum=0;
        int stu=1;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=pages){
                sum+=a[i];
            }
            else{
                stu++;
                sum=a[i];
            }
        }
        
        return stu;
    }
    
    int findPages(int a[], int n, int m) 
    {
        if(m>n) return -1;
        int low=0,high=0;
        
        for(int i=0;i<n;i++){
            low=max(low,a[i]);
            high+=a[i];
        }
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int stu=count(mid,a,n);
            
            if(stu>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        
        return low;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends