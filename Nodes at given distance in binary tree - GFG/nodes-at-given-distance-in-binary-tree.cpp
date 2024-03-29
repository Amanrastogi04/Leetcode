//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    Node* node;
    void makeparent(Node* root,int target,unordered_map<Node*,Node*> &parent){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->data==target){
                node=it;
            }
            if(it->left!=NULL){
                parent[it->left]=it;
                q.push(it->left);
            }
            if(it->right!=NULL){
                parent[it->right]=it;
                q.push(it->right);
            }
        }
    }
        
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent;
        makeparent(root,target,parent);
        
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(node);
        vis[node]=true;
        int cnt=0;
        vector<int>ans;
        
        while(!q.empty()){
            int sz=q.size();

            if(cnt++==k){
                break;
            }
            
            for(int i=0;i<sz;i++){
                
                auto it=q.front();
                q.pop();
                
                if(it->left!=NULL && !vis[it->left]){
                    q.push(it->left);
                    vis[it->left]=true;
                    
                }
                
                if(it->right!=NULL && !vis[it->right]){
                    q.push(it->right);
                    vis[it->right]=true;
                    
                }
                
                if(parent[it] && !vis[parent[it]]){
                    q.push(parent[it]);
                    vis[parent[it]]=true;
                    
                }
                
            }

            
        }
        
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends