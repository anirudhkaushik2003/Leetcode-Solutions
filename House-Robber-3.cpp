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
    int rob2(TreeNode *root, map<TreeNode *, int> &m)
    {
        if(root == nullptr) return 0;
        if (m.count(root) > 0)
            return m[root];

        int val = 0;
        if (root->left)
            val += rob2(root->left->left, m) + rob2(root->left->right, m);
        if (root->right)
            val += rob2(root->right->left, m) + rob2(root->right->right, m);

        m[root] = max(val+root->val, rob2(root->left, m) + rob2(root->right, m));
        return m[root];
    }
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        map<TreeNode *, int> m;
        return rob2(root, m);
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    Solution s;
    cout << s.rob(root) << endl;
}