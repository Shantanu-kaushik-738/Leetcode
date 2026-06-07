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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> ichild;

        for (auto& vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            bool lft = vec[2];

            if (mpp.find(parent) == mpp.end()) {
                mpp[parent] = new TreeNode(parent);
            }

            if (mpp.find(child) == mpp.end()) {
                mpp[child] = new TreeNode(child);
            }

            if (lft) {
                mpp[parent]->left = mpp[child];
            } else {
                mpp[parent]->right = mpp[child];
            }

            ichild.insert(child);
        }

        for (auto& vec : descriptions) {
            int parent = vec[0];

            if (ichild.find(parent) == ichild.end()) {
                return mpp[parent];
            }
        }
        return NULL;
    }
};