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
    int binarySearch(vector<pii> &start_indices, int target, int l, int r)
    {

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (start_indices[mid].first == target)
                return start_indices[mid].second;

            if (start_indices[mid].first < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (l >= start_indices.size())
        {
            return -1;
        }
        return start_indices[l].second;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        // if(n == 1)
        // {
        // return {-1};
        // }
        vector<pii> start_indices;
        for (int i = 0; i < n; i++)
        {
            start_indices.pb(mp(intervals[i][0], i));
        }
        sort(start_indices.begin(), start_indices.end());
        vi ans(n);
        int l = 0;
        int r = n - 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = binarySearch(start_indices, intervals[i][1], l, r);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 2}};
    vi ans = s.findRightInterval(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
