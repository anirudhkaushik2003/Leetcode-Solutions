#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution
{
public:
    bool dfs(int node, vector<vi> &graph, vector<bool> &visited, vector<bool> &is_safe, vi &safe_nodes)
    {
        if (!visited[node])
        {
            visited[node] = true;
            bool temp = true;
            for (auto it : graph[node])
            {
                temp = temp && dfs(it, graph, visited, is_safe, safe_nodes);
                if (!temp)
                    break;
            }
            is_safe[node] = temp;
            if (is_safe[node])
                safe_nodes.pb(node);
        }
        return is_safe[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<bool> visited(n, false);
        vector<bool> is_safe(n, false);

        vector<int> safe_nodes;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited, is_safe, safe_nodes);
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};