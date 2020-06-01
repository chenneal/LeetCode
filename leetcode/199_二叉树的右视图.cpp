/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if (!root)
            return result;
        
        result.push_back(root->val);

        if (!root->left && !root->right) {
            return result;
        }
        
        queue<TreeNode*> queue_former, queue_cur;
        queue_former.push(root);
        
        while (!queue_former.empty()) {
            //遍历完一层，子节点存储在queue_cur
            while (!queue_former.empty()) {
                TreeNode* temp = queue_former.front();
                if (temp->left) {
                    queue_cur.push(temp->left);
                }
                if (temp->right) {
                    queue_cur.push(temp->right);
                }
                queue_former.pop();
            }
            //将最后入队的节点存在结果里
            if (!queue_cur.empty()) {
                result.push_back(queue_cur.back()->val);
            }
            //更新父节点并清空子节点队列
            queue_former.swap(queue_cur);
        }
        
        return result;
    }
};

