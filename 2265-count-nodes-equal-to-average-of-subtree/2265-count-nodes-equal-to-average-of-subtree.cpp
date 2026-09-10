/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;

    pair<int, int> f(TreeNode* root) {
        if(root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = f(root -> left);
        pair<int, int> right = f(root -> right);

        int subtreeSum = left.first + right.first + root -> val;
        int subtreeCount = left.second + right.second + 1;

        if(subtreeSum / subtreeCount == root -> val) {
            ans += 1;
        }

        return {subtreeSum, subtreeCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};