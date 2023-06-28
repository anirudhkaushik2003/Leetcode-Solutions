#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode*> generateSubtrees(int start, int end)
    {
        vector<TreeNode*> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftSubtrees = generateSubtrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = generateSubtrees(i + 1, end);

            for (TreeNode* left : leftSubtrees)
            {
                for (TreeNode* right : rightSubtrees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode*>();

        return generateSubtrees(1, n);
    }
};

