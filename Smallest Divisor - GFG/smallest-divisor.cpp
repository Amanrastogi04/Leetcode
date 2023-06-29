//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    
    bool ischeck(vector<int> &nums,int num,int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+ceil((double)nums[i]/(double)num);
        }
        
        return sum<=k;
    }
    
    
    int smallestDivisor(vector<int>& nums, int K) {

        int st=1,end=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }
        
        while(st<=end){
            int mid=(st+end)/2;
            
            if(ischeck(nums,mid,K)){
                ans=mid;
                end=mid-1;
            }
            
            else{
                st=mid+1;
            }
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends