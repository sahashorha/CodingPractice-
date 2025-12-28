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

vector<vector<int>> preInPostTraversal(TreeNode* root){
      vector<vector<int>>ans;
      if(!root) return ans;
      vector<int> pre, in, post;

      stack<pair<TreeNode*, int >> st;
      st.push({root, 1});

      while(!st.empty()){
            auto it = st.top();
            st.pop();

            if(it.second == 1){                  
                  pre.push_back(it.first -> val);
                  it.second = 2;
                  st.push(it);

                  // it.first -> left 
                  if(it.first -> left) st.push({it.first -> left, 1});

            }
            else if(it.second == 2){
                  in.push_back(it.first -> val);
                  it.second = 3;
                  st.push(it);

                  // it.first -> right not equal to null 
                  if(it.first -> right ){
                        st.push({it.first -> right, 1});
                  }
            }
            else {
                  post.push_back(it.first -> val);
            }
      }
      ans.push_back(pre);
      ans.push_back(in);
      ans.push_back(post);

      return ans;
}


int main(){
      TreeNode* root = new TreeNode(1);
      root -> left =  new TreeNode(2);
      root -> right = new TreeNode(3);
      root-> left -> left =  new TreeNode(4);
      root -> left -> right = new TreeNode(5);
      root -> right -> left = new TreeNode(6);
      root -> right -> right = new TreeNode(7);
          vector<int> pre, in, post;
      vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;



      return 0;
}