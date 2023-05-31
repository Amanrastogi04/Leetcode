//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &c, int N, int k) {
        long long r=0,l=0,sum=0;
        
        for(int i=0;i<k;i++){
            sum+=c[i];
        }
        long long maxa=sum;
        
            for(l=k-1;l>=0;l--){
                sum+=c[N-k+l];
                sum-=c[l];
                maxa=max(sum,maxa);
            }
        
        return maxa;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends