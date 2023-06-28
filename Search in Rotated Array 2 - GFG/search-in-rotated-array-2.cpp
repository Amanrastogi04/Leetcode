//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int key) {
        
        int st=0,end=N-1;
        
        while(st<=end){
            
            int mid=(st+end)/2;
            
            
            if(arr[mid]==key){
                return 1;
            }
            
            if(arr[st]==arr[mid] && arr[mid]==arr[end]){
                st++;
                end--;
                continue;
            }
            
            if(arr[st]<=arr[mid]){
                
                if(arr[st]<=key && key<=arr[mid]){
                    end=mid-1;
                }
                
                else{
                    st=mid+1;
                }
                
            }
            
            else{
                
                if(arr[mid]<=key && key<=arr[end]){
                    st=mid+1;
                }
                
                else{
                    end=mid-1;
                }
                
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends