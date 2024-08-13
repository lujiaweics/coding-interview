#include <iostream>
#include <vector>

struct TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
      return nullptr;
    }
    int current_number = preorder[0];
    TreeNode *node = new TreeNode(current_number);
    int size = preorder.size();
    if (size == 1) {
      return node;
    }
    size_t idx = 0;
    for (; idx < inorder.size(); ++idx) {
      if (inorder[idx] == current_number) {
        break;
      }
    }
    if (idx >= inorder.size()) {
      delete node;
      return nullptr;
    } else if (idx == 0) {
      // left is nullptr
      auto it = preorder.begin() + 1;
      std::vector<int> new_preorder(it, preorder.end());
      auto it_inorder = inorder.begin() + 1;
      std::vector<int> new_inorder(it_inorder, inorder.end());
      node->right = buildTree(new_preorder, new_inorder);
    } else if (idx == inorder.size() - 1) {
      auto it = preorder.begin() + 1;
      std::vector<int> new_preorder(it, preorder.end());
      auto it_inorder = inorder.end() - 1;
      std::vector<int> new_inorder(inorder.begin(), it_inorder);
      node->left = buildTree(new_preorder, new_inorder);
      // right is nullptr
    } else {
      // left tree
      auto preorder_begin = preorder.begin() + 1;
      auto preorder_end = preorder.begin() + 1 + idx;
      std::vector<int> new_preorder_left(preorder_begin, preorder_end);
      auto inorder_begin = inorder.begin();
      auto inorder_end = inorder.begin() + idx;
      std::vector<int> new_inorder_left(inorder_begin, inorder_end);
      node->left = buildTree(new_preorder_left, new_inorder_left);
      // right tree
      preorder_begin = preorder.begin() + 1 + idx;
      std::vector<int> new_preorder_right(preorder_begin, preorder.end());
      inorder_begin = inorder.begin() + 1 + idx;
      std::vector<int> new_inorder_right(inorder_begin, inorder.end());
      node->right = buildTree(new_preorder_right, new_inorder_right);
    }

    return node;
  }
};

int main() {
  std::vector<int> preorder{3, 9, 20, 15, 7};
  std::vector<int> inorder{9, 3, 15, 20, 7};
  Solution solution;
}