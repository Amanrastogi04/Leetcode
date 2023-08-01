//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>>vis(N,vector<int>(M,0));
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        
        int st=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int step=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            st=max(st,step);
            if(row==X && col==Y){
                return st;
            }
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<N && ncol<M && A[nrow][ncol]==1
                && vis[nrow][ncol]==0){
                    q.push({step+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
            
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends