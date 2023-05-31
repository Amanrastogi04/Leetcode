//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
          set<char> st;
          
          for(auto it:str){
              st.insert(it);
          }
          
          int l=0,r=0,ans=str.size();
          unordered_map<char,int> mp;
          
          for(;r<str.size();r++){
              mp[str[r]]++;
              
              if(mp.size()==st.size()){
                  while(mp[str[l]]>1){
                      mp[str[l]]--;
                      l++;
                  }
                  ans=min(ans,r-l+1);
              }
          }
          return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends