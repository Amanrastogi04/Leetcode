//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        
        int cnt=0;
        string f="";
        
        for(int i=0;i<k;i++){
            f+=str[i];
        }
        
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<k;j++){
                s+=arr[i][j];
            }
            if(s==f){
                cnt++;
            }
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends