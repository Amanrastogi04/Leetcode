//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(vector<int> &arr, int N, int k){
        //  unordered_map<int,int> mp;
        int l=0,ans=0,cnt=0;
        vector<int> mp(N+1,0);
       
        
        for(int r=0;r<N;r++){
            if(mp[arr[r]]==0) cnt++;
            mp[arr[r]]++;
            
            while(cnt>k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    cnt--;
                }
                l++;
            }
            
            ans+=r-l+1;
        }
        return ans;
    }
    
    int subarrayCount(vector<int> &arr, int N, int k) {
        return solve(arr,N,k)-solve(arr,N,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends