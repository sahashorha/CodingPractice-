#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

     TreeNode(int val){
        this -> val = val;
        left = NULL;
        right = NULL;
     }
};

// level Order Traversal -> space complexiety -> 0(N)
vector<vector<int>> levelOrderTraversal(TreeNode * root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode * node = q.front();
            level.push_back(node -> val);
            q.pop();
            if(node -> left)   q.push(node -> left);
            if(node -> right)   q.push(node -> right);
        }
        ans.push_back(level);
    }
return ans;
}


int main() {

    TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    
    root -> right -> right = new TreeNode(7);
    vector<vector<int>> result = levelOrderTraversal(root);
    for(auto &level : result){
        cout<<level[0]<<" ";
    }
    return 0;
}