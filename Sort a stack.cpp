//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}
// } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void SortedForm(stack<int> &s, int num)
{
    if (s.empty() || num > s.top())
    {
        s.push(num);
        return;
    }

    int top = s.top();
    s.pop();

    SortedForm(s, num);
    s.push(top);
}

void Solve(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }

    int topelement = S.top();
    S.pop();

    Solve(S);

    SortedForm(S, topelement);
}

void SortedStack ::sort()
{
    Solve(s);
}