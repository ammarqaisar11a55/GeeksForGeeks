//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q)
    {

        vector<int> FirstHalf, SecondHalf, Ans;
        int size = q.size();
        int mid = q.size() / 2;

        for (int i = 0; i < mid; i++)
        {
            FirstHalf.push_back(q.front());
            q.pop();
        }

        while (!q.empty())
        {
            SecondHalf.push_back(q.front());
            q.pop();
        }
        int i = 0;

        while (Ans.size() < size)
        {
            Ans.push_back(FirstHalf[i]);
            Ans.push_back(SecondHalf[i]);
            i++;
        }

        return Ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends