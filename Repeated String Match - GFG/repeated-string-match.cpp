//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{

    public:
    int repeatedStringMatch(string a, string b) 
    {
         string f=a;

        int n=b.size()/a.size();
        int cnt=1;

        for(int i=0;i<n+2;i++){
            if(a.find(b) != std::string::npos){
                return cnt;
            }

            else{
                a+=f;
                cnt++;
            }
        }
        return -1;
    }
  
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}

// } Driver Code Ends