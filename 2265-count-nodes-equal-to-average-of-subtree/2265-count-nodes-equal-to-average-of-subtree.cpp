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
    pair<int, int> funx(TreeNode* root) { // < sum, cnt >
        if (!root) return {0, 0}; // first go to last child and traverse child ->parent
        int cnt = 0;

        auto p1 = funx(root->left);
        auto p2 = funx(root->right);

        int sum = p1.first + p2.first + root->val; // 
        int tcnt = p1.second + p2.second + 1;

        if (root->val == (sum / tcnt)) res++;
        return {sum, tcnt}; // reutrn to parent root with sum and cnt 
    }

    int averageOfSubtree(TreeNode* root) {
        funx(root);
        return res;
    }
};
