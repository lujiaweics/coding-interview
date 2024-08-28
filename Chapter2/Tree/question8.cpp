#include <iostream>
#include <vector>

struct TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent = nullptr;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *GetNext(TreeNode *pNode) {
  if (pNode == nullptr) {
    return nullptr;
  }
  TreeNode *pNext = nullptr;
  if (pNode->right != nullptr) {
    pNext = pNode->right;
    while(pNext->left != nullptr) {
      pNext = pNext->left;
    }
    return pNext;
  } else if (pNode->parent != nullptr && pNode->parent->left == pNode) {
    return pNode->parent;
  } else {
    if (pNode->parent != nullptr) {
      pNext = pNode->parent;
    } else {
      return nullptr;
    }
    while (pNext->parent != nullptr) {
      if (pNext->parent->left == pNext) {
        return pNext->parent;
      } else {
        pNext = pNext->parent;
      }
    }
  }
  return nullptr;
}

int main() {
  TreeNode *a = new TreeNode(0);
  TreeNode *b = new TreeNode(1);
  TreeNode *c = new TreeNode(2);
  TreeNode *d = new TreeNode(3);
  TreeNode *e = new TreeNode(4);
  TreeNode *f = new TreeNode(5);
  TreeNode *g = new TreeNode(6);
  TreeNode *h = new TreeNode(7);
  TreeNode *i = new TreeNode(8);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  b->parent = a;
  c->left = f;
  c->right = g;
  c->parent = a;
  d->parent = b;
  e->left = h;
  e->right = i;
  e->parent = b;
  f->parent = c;
  g->parent = c;
  h->parent = e;
  i->parent = e;

  for (TreeNode *it : {a, b, c, d, e, f, g, h, i}) {
    TreeNode *next = GetNext(it);
    if (next != nullptr) {
      std::cout << (char)(next->val + 'a') << std::endl;
    } else {
      std::cout << "nullptr" << std::endl;
    }
  }

  return 0;
}