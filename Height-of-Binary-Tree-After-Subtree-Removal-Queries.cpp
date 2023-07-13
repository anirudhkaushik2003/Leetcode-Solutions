#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
    unordered_map<int, int> heights;
    unordered_map<int, int> depths;

public:
    int dfs(TreeNode *node, unordered_map<int, int> &heights)
    {
        if (node == nullptr)
        {
            return -1;
        }
        if (node->left != nullptr)
        {
            depths[node->left->val] = 1 + depths[node->val];
        }
        if (node->right != nullptr)
        {
            depths[node->right->val] = 1 + depths[node->val];
        }
        heights[node->val] = 1 + max(dfs(node->left, heights), dfs(node->right, heights));
        return heights[node->val];
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {

        int m = queries.size();
        vi ans;
        depths[root->val] = 0;
        int root_height = dfs(root, heights);

        for (auto it : depths)
        {
            cout << it.first << " " << it.second << endl;
        }
        vector<vector<pii>> cousins(root_height + 1, vector<pii>());
        int val, d;
        for (auto it : depths)
        {
            val = it.first;
            d = it.second;
            cousins[d].push_back(mp(heights[val], val));
            sort(cousins[d].begin(), cousins[d].end(), greater<pii>());
            if (cousins[d].size() > 2)
                cousins[d].pop_back();
        }

        for (auto q : queries)
        {
            d = depths[q];
            if (cousins[d].size() == 1)
            {
                ans.pb(d - 1);
            }
            else if (cousins[d][0].second == q)
            {
                ans.pb(cousins[d][1].first + d);
            }
            else
            {
                ans.pb(root_height);
            }
        }

        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(2);
    root->right->left->right = new TreeNode(4);

    vi queries = {3, 5, 4, 2, 4};

    Solution s;
    vi ans = s.treeQueries(root, queries);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}