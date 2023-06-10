//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        
        vector<int> v(26);
        int maxa=0;
        
        for(auto it:tasks){
            v[it-'A']++;
            
            maxa=max(maxa,v[it-'A']);
            
        }
        
        
        
        
        
        int res=(maxa-1)*(k+1);
        
        for(auto it:v){
            if(maxa==it)
            res++;
        }
        
        return max(res,N);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends