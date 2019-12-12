// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(0, 0, inorder.size() - 1, preorder, inorder);
    }
    TreeNode* buildTree(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0;
        for (inIndex = inStart; inIndex <= inEnd; inIndex ++) {
            if (root->val == inorder[inIndex].val)
            {
                break;
            }
            
        }
        root->left = buildTree(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root->right = buildTree(preStart + inIndex + 1, inIndex + 1, inEnd, preorder, inorder);
        return root;
    }
};