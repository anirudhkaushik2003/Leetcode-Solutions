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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        int e = redEdges.size();
        // 2 alternating color paths from 0 to x -> red path (starting from red) and blue path (starting from blue)

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> shortestPath(n, -1);

        vector<vector<pii>> Graph(n, vector<pii>());

        for (int i = 0; i < redEdges.size(); i++)
        {
            Graph[redEdges[i][0]].pb(mp(redEdges[i][1], 0));
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            Graph[blueEdges[i][0]].pb(mp(blueEdges[i][1], 1));
        }
        // bfs from 0 to all nodes
        queue<vector<int>> q;
        visited[0][0] = true;
        visited[0][1] = true;
        q.push({0, 0, -1});
        shortestPath[0] = 0;

        while (!q.empty())
        {
            auto elem = q.front();
            int node = elem[0];
            int steps = elem[1];
            int prevColor = elem[2];
            q.pop();

            for (auto it : Graph[node])
            {
                if (!visited[it.first][it.second] && it.second != prevColor)
                {
                    visited[it.first][it.second] = true;
                    q.push({it.first, steps + 1, it.second});
                    if (shortestPath[it.first] == -1)
                        shortestPath[it.first] = steps + 1;
                }
            }
        }
        return shortestPath;
    }
};

int main()
{
    Solution s;
    vector<vi> redEdges = {{4, 1}, {3, 5}, {5, 2}, {1, 4}, {4, 2}, {0, 0}, {2, 0}, {1, 1}};
    vector<vi> blueEdges = {{5, 5}, {5, 0}, {4, 4}, {0, 3}, {1, 0}};

    vi ans = s.shortestAlternatingPaths(6, redEdges, blueEdges);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}