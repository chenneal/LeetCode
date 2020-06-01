#include <iostream>
#include <stack>
#include <queue>

/* 二叉树的各种遍历，递归OR非递归 */
using namespace std;

typedef struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  char data;
  TreeNode(char data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
} TreeNode;

// 自己模拟这棵树长啥样
TreeNode* CreateTree(void) {
  TreeNode* A = new TreeNode('A');
  TreeNode* B = new TreeNode('B');
  TreeNode* C = new TreeNode('C');
  TreeNode* D = new TreeNode('D');
  TreeNode* E = new TreeNode('E');
  TreeNode* F = new TreeNode('F');
  TreeNode* G = new TreeNode('G');
  
  A->left = B;
  A->right = C;
  B->left = D;
  B->right = E;
  D->left = F;
  E->right = G;
  
  return A;
}

// 前序遍历，递归
void PreOrder(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  cout << tree->data << " ";
  PreOrder(tree->left);
  PreOrder(tree->right);
}

// 前序遍历，非递归
void PreOrderNonRecur(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  stack<TreeNode*> stack_node;
  TreeNode* cur = tree;
  
  while(cur || !stack_node.empty()) {
    // 走到最左侧
    while (cur) {
      cout << cur->data << " ";
      stack_node.push(cur);
      cur = cur->left;
    }
    
    if (!stack_node.empty()) {
      cur = stack_node.top();
      stack_node.pop();
      cur = cur->right;
    }
  }
}

// 前序遍历，递归
void InOrder(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  InOrder(tree->left);
  cout << tree->data << " ";
  InOrder(tree->right);
}

// 中序遍历，非递归
void InOrderNonRecur(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  stack<TreeNode*> stack_node;
  TreeNode* cur = tree;
  
  while(cur || !stack_node.empty()) {
    // 走到最左侧
    while (cur) {
      stack_node.push(cur);
      cur = cur->left;
    }
    
    if (!stack_node.empty()) {
      cur = stack_node.top();
      cout << cur->data << " ";
      stack_node.pop();
      cur = cur->right;
    }
  }
}

// 后序遍历，递归
void PostOrder(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  PostOrder(tree->left);
  PostOrder(tree->right);
  cout << tree->data << " ";
}

// 后序遍历，非递归
void PostOrderNonRecur(TreeNode* tree) {
  if (!tree) {
    return;
  }
  
  stack<TreeNode*> stack_node;
  TreeNode* cur = tree;
  TreeNode* pre = nullptr;
  
  while(cur || !stack_node.empty()) {
    // 走到最左侧
    while (cur) {
      stack_node.push(cur);
      cur = cur->left;
    }
    
    if (!stack_node.empty()) {
      cur = stack_node.top();
      if (!cur->right || (pre == cur->right)) {
        cout << cur->data << " ";
        stack_node.pop();
        pre = cur;
        cur = nullptr;
      } else {
        cur = cur->right;
      }
    }
  }
}

// 层次遍历
void LevelOrder(TreeNode* tree) {
  queue<TreeNode*> queue_node;
  queue_node.push(tree);
  while (!queue_node.empty()) {
    TreeNode* cur = queue_node.front();
    cout << cur->data << " ";
    
    if (cur->left)
      queue_node.push(cur->left);
    if (cur->right)
      queue_node.push(cur->right);
    
    queue_node.pop();
  }
}

// 层次遍历并加上层次信息
void LevelInfoOrder(TreeNode* tree) {
  queue<TreeNode*> queue_node;
  queue<TreeNode*> queue_level;
  queue_node.push(tree);
  while (!queue_node.empty() || !queue_level.empty()) {
    
    // 先遍历这个层，下一层的节点存在临时队列里
    while (!queue_node.empty()) {
      TreeNode* cur = queue_node.front();
      cout << cur->data << " ";
      if (cur->left)
        queue_level.push(cur->left);
      if (cur->right)
        queue_level.push(cur->right);
      queue_node.pop();
    }
    
    // 交换两个队列的数据
    queue_node.swap(queue_level);
    cout << "*" << " ";
  }
}

int main() {
  TreeNode* tree = CreateTree();
  
  cout << "前序递归的结果：" << endl;
  PreOrder(tree);
  cout << endl;
  
  cout << "前序非递归的结果：" << endl;
  PreOrderNonRecur(tree);
  cout << endl;
  
  cout << "中序递归的结果：" << endl;
  InOrder(tree);
  cout << endl;
  
  cout << "中序非递归的结果：" << endl;
  InOrderNonRecur(tree);
  cout << endl;
  
  cout << "后序递归的结果：" << endl;
  PostOrder(tree);
  cout << endl;
  
  cout << "后序非递归的结果：" << endl;
  PostOrderNonRecur(tree);
  cout << endl;
  
  cout << "层次遍历的结果：" << endl;
  LevelOrder(tree);
  cout << endl;
  
  cout << "层次遍历的结果(带层次信息)：" << endl;
  LevelInfoOrder(tree);
  cout << endl;
  
  return 0;
}

