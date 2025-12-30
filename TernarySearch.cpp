/// Ternary Search 

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
      
    int target;
    cout << "Enter value to search: ";
    cin >> target;

    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            cout << "Found at index " << mid1 << endl;
            found = true;
            break;
        }
        else if (arr[mid2] == target) {
            cout << "Found at index " << mid2 << endl;
            found = true;
            break;
        }
        else if (target < arr[mid1]) {
            right = mid1 - 1;
        }
        else if (target > arr[mid2]) {
            left = mid2 + 1;
        }
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    if (!found) {
        cout << "Not found in the array." << endl;
    }

    return 0;
}