#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <functional>
#include <numeric>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * (factorial(n - 1));
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int EuclideanAlgorithm(int a, int b)
{
    if (a == 0)
        return b;

    return EuclideanAlgorithm(b % a, a);
}

int Power(int a, int b)
{
    if (b == 0)
        return 1;

    return a * Power(a, b - 1);
}

int SumOfNatural(int n)
{
    if (n == 0)
        return 0;

    return n + SumOfNatural(n - 1);
}

int SumOfDigits(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + SumOfDigits(n / 10);
}

void ReverseTheString(string &s, int start, int end)
{
    if (start >= end)
        return;

    swap(s[start], s[end]);

    ReverseTheString(s, start + 1, end - 1);
}

int countOccurrences(string s, char c, int index)
{
    if (s[index] == '\0')
        return 0;

    int count = s[index] == c ? 1 : 0;

    return count + countOccurrences(s, c, index + 1);
}

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    return isSorted(arr + 1, size - 1);
}

int SumofElements(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return arr[0];
    }

    return arr[0] + SumofElements(arr + 1, size - 1);
}

bool linearSearch(int arr[], int key, int size)
{
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;

    return linearSearch(arr + 1, key, size - 1);
}

bool BinarySearch(int arr[], int s, int e, int key)
{
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
        return true;

    if (key > arr[mid])
    {
        return BinarySearch(arr, mid + 1, e, key);
    }
    else
        return BinarySearch(arr, s, mid - 1, key);
}

bool isPalindrome(string str, int s, int e)
{
    if (s > e)
    {
        return true;
    }

    if (str[s] != str[e])
        return false;

    return isPalindrome(str, s + 1, e - 1);
}

int lengthofString(string s, int index = 0)
{
    if (s[index] == '\0')
        return 0;

    return 1 + lengthofString(s, index + 1);
}

int Minimum(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    return min(arr[0], Minimum(arr + 1, n - 1));
}

int main()
{
    int arr[] = {8, 4, -4, 1, 2, 3, 4, 5};

    cout << Minimum(arr, sizeof(arr) / sizeof(int));

    return 0;
}