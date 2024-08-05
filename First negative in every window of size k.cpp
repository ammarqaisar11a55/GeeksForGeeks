//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    deque<int> WindowIndices;

    for (int i = 0; i < K; i++)
        if (A[i] < 0)
            WindowIndices.push_back(i);

    if (WindowIndices.size() > 0)
    {
        ans.push_back(A[WindowIndices.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = K; i < N; i++)
    {
        if (!WindowIndices.empty() && i - WindowIndices.front() >= K)
            WindowIndices.pop_front();

        // Addition:
        if (A[i] < 0)
            WindowIndices.push_back(i);

        if (WindowIndices.size() > 0)
        {
            ans.push_back(A[WindowIndices.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}