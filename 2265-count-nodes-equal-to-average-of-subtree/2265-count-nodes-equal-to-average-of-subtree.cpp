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

    vector<int> f(int subtreeSum, int subtreeCount, TreeNode* root) {
        if(root == NULL) {
            return {0, 0};
        }

        vector<int> left = f(0, 0, root -> left);
        vector<int> right = f(0, 0, root -> right);

        subtreeSum = left[0] + right[0] + root -> val;
        subtreeCount = left[1] + right[1] + 1;

        if(subtreeSum / subtreeCount == root -> val) {
            ans += 1;
        }

        return {subtreeSum, subtreeCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int subtreeSum = 0;
        int subtreeCount = 0;

        f(subtreeSum, subtreeCount, root);

        return ans;
    }
};