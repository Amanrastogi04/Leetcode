//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    
      priority_queue<int> maxa;// minimum element
      priority_queue<int,vector<int>,greater<int>> mini;//maximum element
        
    void insertHeap(int &x)
    {
      
        
        if(maxa.size()==0){
            maxa.push(x);
            return;
        }
        
        if(maxa.size()>mini.size()){
            if(maxa.top()>x){
                mini.push(maxa.top());
                maxa.pop();
                maxa.push(x);
            }
            else{
                mini.push(x);
            }
        }
        
        else{
            if(x<maxa.top()){
                maxa.push(x);
            }
            else{
                mini.push(x);
                maxa.push(mini.top());
                mini.pop();
            }
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxa.size()==mini.size()){
            return ((double)maxa.top()+mini.top())/2.0;
        }
        else{
            return maxa.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends