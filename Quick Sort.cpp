//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;

        int partitionIndex = partition(arr, low, high);

        // Sort Left of Array
        quickSort(arr, low, partitionIndex - 1);

        // Sort Right Part of Array
        quickSort(arr, partitionIndex + 1, high);
    }

public:
    int partition(int arr[], int s, int e)
    {
        int Pivot = arr[s];

        int cnt = 0;

        for (int i = s + 1; i <= e; i++)
        {
            if (arr[i] <= Pivot)
                cnt++;
        }

        int PivotIndex = s + cnt;
        swap(arr[PivotIndex], arr[s]);

        int i = s;
        int j = e;

        while (i < PivotIndex && j > PivotIndex)
        {
            while (arr[i] <= Pivot)
                i++;

            while (arr[j] > Pivot)
                j--;

            if (i < PivotIndex && j > PivotIndex)
                swap(arr[i++], arr[j--]);
        }

        return PivotIndex;
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000], n, T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        Solution ob;
        ob.quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends