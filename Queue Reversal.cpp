//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> S;

        while (!q.empty())
        {
            S.push(q.front());
            q.pop();
        }

        while (!S.empty())
        {
            q.push(S.top());
            S.pop();
        }

        return q;
    }
};


//Approach 2: using recursion: 

void ReverseQueue(queue<int>&Q)
{
    if(Q.empty())
    {
        return;
    }

    int front = Q.front();
    Q.pop();

    ReverseQueue(Q);

    Q.push(front);
}

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends