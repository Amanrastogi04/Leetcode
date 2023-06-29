//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool ispossible(vector<int>&b,int day,int k,int m){
        
        int cnt=0,nofB=0;
        
        for(int i=0;i<b.size();i++){
            if(b[i]<=day){
                cnt++;
            }
            else{
                nofB+=(cnt/k);
                cnt=0;
            }
        }
        
        nofB+=(cnt/k);
        
        return nofB>=m;
        
        
    }
    
    
    int solve(int M, int k, vector<int> &b){
        long long int val=M*1LL*k*1LL;
        if(val>b.size()){
            return -1;
        }
        
       int st=INT_MAX,end=INT_MIN,ans=0;
       
       for(int i=0;i<b.size();i++){
           st=min(st,b[i]);
           end=max(end,b[i]);
       }
       
       ans=end;
       
       while(st<=end){
           int mid=(st+end)/2;
           
           if(ispossible(b,mid,k,M)){
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
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends