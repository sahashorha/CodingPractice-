#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode(int val)
      {
            this->val = val;
            left = NULL;
            right = NULL;
      }
};

vector<vector<int>> VerticalOrdertraversal(TreeNode *root)
{
      vector<vector<int>> ans;
      if (!root)
            return ans;
      map<int, map<int, multiset<int>>> mp;
      // vertcal -> x and horizental -> y and last wala Treenode value
      queue<pair<TreeNode *, pair<int, int>>> q;

      q.push({root, {0, 0}});
      // x -> vertical and y -> horizental

      while (!q.empty())
      {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(node->val);

            if (node->left)
                  q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                  q.push({node->right, {x + 1, y + 1}});
      }

      for (auto p : mp)
      {
            vector<int> col;

            for (auto q : p.second)
            {
                  col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
      }
      return ans;
}

int main()
{
      TreeNode *root = new TreeNode(1);
      root->left = new TreeNode(2);
      root->left->left = new TreeNode(4);
      root->left->right = new TreeNode(10);
      root->left->left->right = new TreeNode(5);
      root->left->left->right->right = new TreeNode(6);
      root->right = new TreeNode(3);
      root->right->right = new TreeNode(10);
      root->right->left = new TreeNode(9);
      vector<vector<int>> verticalTraversal = VerticalOrdertraversal(root);
      for (auto level : verticalTraversal)
      {
            for (auto Treenode : level)
            {
                  cout << Treenode << " ";
            }
            cout << endl;
      }
      cout << endl;
      return 0;
}