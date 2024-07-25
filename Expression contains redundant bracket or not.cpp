//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<int> Material;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+')
            {
                Material.push(s[i]);
            }
            else if (s[i] == ')')
            {
                bool IsRedundancythere = true;
                while (Material.top() != '(')
                {
                    if (Material.top() == '*' || Material.top() == '/' || Material.top() == '-' || Material.top() == '+')
                        IsRedundancythere = false;
                    Material.pop();
                }
                if (IsRedundancythere)
                    return 1;
                Material.pop();
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends