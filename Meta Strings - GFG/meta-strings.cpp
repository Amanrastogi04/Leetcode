//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string s1, string s2)
{
    if(s1.size()!=s2.size()){
        return false;
    }
    
    if(s1==s2){
        return false;
    }
    
    vector<int> diff;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            diff.push_back(i);
        }
    }
    
    if(diff.size()!=2){
        return false;
    }
    
    swap(s1[diff[0]],s1[diff[1]]);
    
    return s1==s2;
    
}