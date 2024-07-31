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
    void merge(int arr[], int l, int m, int r)
    {
        int mid = l + (r - l) / 2;

        int length1 = mid - l + 1;
        int length2 = r - mid;

        int *first = new int[length1];
        int *second = new int[length2];

        // Copying First Half:
        int MainArray = l;

        for (int i = 0; i < length1; i++)
            first[i] = arr[MainArray++];

        // Copying Second Half:
        MainArray = mid + 1;

        for (int i = 0; i < length2; i++)
            second[i] = arr[MainArray++];

        // Merge 2 Sorted Half Arrays:
        int index1 = 0;
        int index2 = 0;
        MainArray = l;

        while (index1 < length1 && index2 < length2)
        {
            if (first[index1] < second[index2])
            {
                arr[MainArray++] = first[index1++];
            }
            else
            {
                arr[MainArray++] = second[index2++];
            }
        }

        while (index1 < length1)
        {
            arr[MainArray++] = first[index1++];
        }

        while (index2 < length2)
        {
            arr[MainArray++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r)
            return;

        // Mid of the array:
        int mid = l + (r - l) / 2;

        // Left Part:
        mergeSort(arr, l, mid);

        // Right Part:
        mergeSort(arr, mid + 1, r);

        // Merge Left & Right:
        merge(arr, l, mid, r);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends