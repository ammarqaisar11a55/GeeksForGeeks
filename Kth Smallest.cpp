class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {

        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
    }
};