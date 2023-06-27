//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
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
	        return 0;
	    }
	    
	    if(l-1==f){
	        return 1;
	    }
	    
	    return l-f;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends