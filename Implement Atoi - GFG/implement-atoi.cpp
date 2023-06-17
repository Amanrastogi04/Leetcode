//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans=0;
        
        bool flag=true;
        
        // for handling negative number
        if(s[0]=='-'){
            for(int i=1;i<s.size();i++){
                if(s[i]>=48 && s[i]<=57){
                    ans=ans*10+(s[i]-48);
                }
                else{
                    flag=false;
                }
            }
            ans=ans*(-1);
        }
            
            // for handeling positive
            
            else{
                for(int i=0;i<s.size();i++){
                    if(s[i]>=48 && s[i]<=57){
                        ans=ans*10+(s[i]-48);
                    }
                    else{
                        flag=false;
                    }
                }
                
            }
            
            return (flag==false)?-1:ans;
                
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends