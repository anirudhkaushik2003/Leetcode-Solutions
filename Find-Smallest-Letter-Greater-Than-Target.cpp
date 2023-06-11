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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();

        int l = 0;
        int r = n - 1;

        if(target >= letters[n-1]) return letters[0];

        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (letters[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return letters[l];
    }
};

int main()
{
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';
    char ans = s.nextGreatestLetter(letters, target);
    cout << ans << endl;

}