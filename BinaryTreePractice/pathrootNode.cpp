#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
      int val;
      TreeNode* left;
      TreeNode * right;

      TreeNode(int val){
            this -> val  = val;
            left = NULL;
            right = NULL;
      }
};

void dfs(TreeNode * root , vector<int> &ans, TreeNode * node ){
      if(root == NULL) return;
      ans.push_back(root -> val);
      if(root == node) return;

      if(root -> left) dfs(root -> left, ans, node);
      if(root -> right) dfs(root -> right, ans, node);
      if(ans.back() != node -> val) ans.pop_back(); 
}

int main(){
 TreeNode * root = new TreeNode(1);
 root -> left = new TreeNode(2);
 root -> right = new TreeNode(3);
 root -> left -> left = new TreeNode(4);
 root -> left -> right = new TreeNode(5);
 root -> right -> left = new TreeNode(6);
 root -> right -> right = new TreeNode(7);

 TreeNode * node = new TreeNode(4);

 vector<int> ans;
 dfs(root, ans, node);
 for(int val : ans) cout<< val <<" ";

return 0;
}