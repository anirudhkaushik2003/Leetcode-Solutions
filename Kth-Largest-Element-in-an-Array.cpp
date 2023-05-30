#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq; // 
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }

        for(int i = 0; i< k-1; i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};
int main()
{
    vi nums;
    int k;
    Solution s;
    int ans = s.findKthLargest(nums, k);
    cout << ans << endl;
}