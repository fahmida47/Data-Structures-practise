/// Bubble Sort

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter num ";
    cin>>n;
    
    cout<<"Enter element ";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // Bubble Sort
    for (int i=0; i<=n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i<n-1)
            cout << ", ";
    }
    cout << endl;
}