//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int K) {
        int l=0,r=0,ans=0,cnt=INT_MIN;
        vector<int> v(26);
        
        for(;r<s.size();r++){
            
            v[s[r]-'A']++;
            cnt=max(cnt,v[s[r]-'A']);
            
            for(;r-l+1-cnt>K;l++){
                v[s[l]-'A']--;
                
            }
            
            ans=max(ans,r-l+1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends