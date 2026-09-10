/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int sumf(TreeNode* root, int& cnt) {
        if (!root) return 0;

        cnt++;
        int left = sumf(root->left, cnt);
        int right = sumf(root->right, cnt);

        return left + right + root->val;
    }

    void funx(TreeNode* root) {
        if (!root) return;
        int cnt = 0;

        int sum = sumf(root, cnt);
        if (root->val == sum / cnt) res++;

        funx(root->left);
        funx(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        funx(root);
        return res;
    }
};