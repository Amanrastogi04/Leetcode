//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int totalho(vector<int> &piles,int hou){
        int totalH=0;
        
        for(int i=0;i<piles.size();i++){
            totalH+=ceil((double)piles[i]/(double)hou);
        }
        return totalH;
    }
    
    
    int Solve(int N, vector<int>& piles, int H) {
        int st=1,end=INT_MIN;
        for(int i=0;i<piles.size();i++){
            end=max(end,piles[i]);
        }
        
        while(st<=end){
            int mid=(st+end)/2;
            
            int totalH=totalho(piles,mid);
            
            if(totalH<=H){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        
        return st;
        
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends