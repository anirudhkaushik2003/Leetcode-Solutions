#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), compare);

        // priority_queue <pii, vector<pii>, greater<pii>> meets;
        priority_queue<pll, vector<pll>, greater<pll>> engaged;
        priority_queue<int, vi, greater<int>> unused;

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[i] = 0;
            unused.push(i);
        }

        int m = meetings.size(), room, start_time, ans = 101, max_freq = 0;
        for (int i = 0; i < m; i++)
        {
            start_time = meetings[i][0];

            while (!engaged.empty() && engaged.top().first <= start_time)
            {
                room = engaged.top().second;
                engaged.pop();
                unused.push(room);
            }
            if (!unused.empty())
            {
                room = unused.top();
                freq[room] += 1;

                unused.pop();
                engaged.push(mp(meetings[i][1], room));
            }
            else
            {
                // waiting
                auto it = engaged.top();

                engaged.pop();
                room = it.second;
                freq[room] += 1;

                engaged.push(mp((long long)((meetings[i][1] - start_time) + it.first), room));
            }
            if (freq[room] == max_freq && room < ans)
            {
                ans = room;
                max_freq = freq[room];
            }
            else if (freq[room] > max_freq)
            {
                ans = room;
                max_freq = freq[room];
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 3;
    // [[1,20],[2,10],[3,5],[4,9],[6,8]]
    vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    int ans = s.mostBooked(n, meetings);
    cout << ans << endl;
}