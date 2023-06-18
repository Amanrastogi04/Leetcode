//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		
		void solve(int index,string s,vector<string> &ans,string f,int n){

		    if(index==n) {
		        if(f!=""){
		        ans.push_back(f);
		        }
		        return;
		    }
		    

		    solve(index+1,s,ans,f+s[index],n);
		    solve(index+1,s,ans,f,n);
		    
		}
		
		vector<string> AllPossibleStrings(string s){
		    string f="";
		    vector<string> ans;
		    solve(0,s,ans,f,s.length());
		    
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends