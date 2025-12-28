#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int val){
            this -> val = val;
            left = NULL;
            right = NULL;
      }
};

vector<int> TopView(TreeNode * root){
      // vector ans -> store the result
      // queue pair -> node and line means vertical position {Node*, value}
      // map to store the line -> map <int, int> -> vertical index , node value
      
      vector<int> ans;
      if(!root) return ans;

      unordered_map<int, int> mp;
      queue<pair<TreeNode*, int>>  q;
      q.push({root, 0});
      while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* nodeVal = it.first;
            int line = it.second;
            // 
        
            // if the position is first time inserted 
            if(mp.find(line) == mp.end()){
                  mp[line] = nodeVal -> val;
            }

            if(nodeVal -> left) q.push({nodeVal -> left, line -1});
            if(nodeVal -> right) q.push({nodeVal -> right, line + 1});
      }

      for(auto it : mp){
            ans.push_back(it.second);
      }
}                       

 int main(){
      TreeNode* root = new TreeNode(1);
      root -> left =  new TreeNode(2);
      root -> right = new TreeNode(3);
      root-> left -> left =  new TreeNode(4);
      root -> left -> right = new TreeNode(5);
      root -> right -> left = new TreeNode(6);
      root -> right -> right = new TreeNode(7);
      vector<int> ans =  TopView(root);
      for(int i = 0; i< ans.size(); i++){
            cout<<ans[i]<<" ";
      } 
      return 0;
 }