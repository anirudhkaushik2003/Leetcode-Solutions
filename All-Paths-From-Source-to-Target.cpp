#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
// all paths by dfs
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<vi> paths;
        vector<bool> visited(n, false);

        stack<vi> s;
        s.push({0});
        while (!s.empty())
        {
            auto elem = s.top();
            int node = elem.back();
            vi path = elem;
            if (node == n - 1)
            {
                paths.pb(path);
            }
            s.pop();

            for (auto it : graph[node])
            {
                // push path upto this node i.e. path + node
                path.pb(it);
                s.push(path);
                path.pop_back();
            }
        }
        return paths;
    }
};

int main()
{
    Solution s;
    vector<vi> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<vi> paths = s.allPathsSourceTarget(graph);
    for (auto path : paths)
    {
        for (auto node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}