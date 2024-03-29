//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--,cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1=0,cnt2=0;
        
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]) cnt1++;
            if(ele2==nums[i]) cnt2++;
        }
        
        int mini = int( nums.size()/ 3) + 1;
        
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        
        if(ans.size()!=0){
            return ans;
        }
        else{
            return {-1};
        }

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
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends