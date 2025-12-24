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

vector<vector<int>> LevelOrderTraversal(TreeNode * root){
    vector<vector<int>>ans;
    
    // intialize queue
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i<size ; i++){
            TreeNode* node = q.front();
            level.push_back(node -> val);
            q.pop();
            if(node -> left) q.push(node -> left);
            if(node -> right)q.push(node -> right);
        }
        ans.push_back(level);
    }
    return ans;
}
// Level Order Traversal
int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(5);
    vector<vector<int>> result = LevelOrderTraversal(root);
    for(auto &level : result){
        for(int val : level){
            cout <<val <<" ";
        }
        cout<<endl;
    }
    return 0;
}