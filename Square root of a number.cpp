//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        int s = 0;
        int e = x;
        int ans = 0;

        while (s <= e)
        {

            long long int mid = s + (e - s) / 2;

            if (mid * mid == x)
            {
                return mid;
            }

            if (x < mid * mid)
            {

                e = mid - 1;
            }
            else
            {
                s = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends