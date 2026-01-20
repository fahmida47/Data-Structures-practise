///Merge Sort
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right)
{
    int m = mid - left + 1;
    int n = right - mid;

    vector<int> L(m+1), R(n+1);

    for(int i = 0; i < m; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n; j++)
        R[j] = arr[mid + 1 + j];

    L[m] = INT_MAX;
    R[n] = INT_MAX;

    int i = 0, j = 0;
    for(int k = left; k <= right; k++)
    {
        if(L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
    }
}

void MergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;

    vector<int> arr(num);
    cout << "Enter elements: ";
    for(int i = 0; i < num; i++)
        cin >> arr[i];

    if(num > 0)
        MergeSort(arr, 0, num-1);

    cout << "Sorted array: ";
    for(int x : arr)
        cout << x << " ";

    return 0;
}


// Merge Sort Even odd

#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int m = mid - left + 1;
    int n = right - mid;

    int L[m + 1], R[n + 1];

    for (int i = 0; i < m; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n; j++)
        R[j] = arr[mid + 1 + j];

    // Add sentinels (large value at the end)
    L[m] = INT_MAX;
    R[n] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
    {
        if ((L[i] % 2 == 0 && R[j] % 2 != 0) ||
            (L[i] % 2 == R[j] % 2 && L[i] <= R[j]))
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main()
{
    cout << "Enter num: ";
    int num;
    cin >> num;

    int arr[num];
    cout << "Enter elements: ";
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, num - 1);

    cout << "Sorted (Even first, then Odd): ";
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


