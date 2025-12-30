/// Insertion Sort

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter num ";
    cin>>n;
    
    cout<<"Enter element ";
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    // Insertion Sort logic
    for (int i=1; i<=n-1; i++) {
        int temp = arr[i];
        int j = i-1;

        // Move elements that are greater than key
        while (j>=0 && arr[j]>temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    // Print sorted array
    cout << "Sorted array in Ascending Order:\n";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
