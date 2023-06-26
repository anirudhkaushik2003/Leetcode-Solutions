#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void generateSubtree(vi left, vi right, TreeNode *root, vector<TreeNode *> &trees)
    {
        vi leftSub;
        vi rightSub = left;
        int to_append;
        int n = left.size();
        for (int i = 0; i < n; i++)
        {

            TreeNode node = TreeNode(left[i]);
            root->left = (TreeNode *)malloc(sizeof(TreeNode));
            *root->left = node;
            auto leftroot = root->left;

            if (i > 0)
            {
                leftSub.pb(left[i - 1]);
                rightSub.erase(rightSub.begin());
            }
            generateSubtree(leftSub, rightSub, leftroot, trees);
        }
        leftSub = vi();
        rightSub = right;
        n = right.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode node = TreeNode(right[i]);
            root->right = (TreeNode *)malloc(sizeof(TreeNode));
            *root->right = node;
            auto rightroot = root->right;
            if (i > 0)
            {
                leftSub.pb(left[i - 1]);
                rightSub.erase(rightSub.begin());
            }
            cout << rightSub.size() << endl;
            generateSubtree(leftSub, rightSub, rightroot, trees);
        }
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> trees(n+1);
        vi left;
        vi right(n - 1);
        for (int i = 2; i < n; i++)
        {
            right.pb(i);
        }

        for (int root = 1; root <= n; root++)
        {
            TreeNode node = TreeNode(root);
            trees[root] = (TreeNode *)malloc(sizeof(TreeNode));
            *trees[root] = node;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
            {
                left.pb(i - 1);
                right.erase(right.begin());
            }
            generateSubtree(left, right, trees[i], trees);
        }
        return trees;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    s.generateTrees(n);
}