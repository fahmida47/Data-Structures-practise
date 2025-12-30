/// Binary Insertion Sort

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

    for (int i=1; i<=n-1; i++) {
        int temp = arr[i];
        int left = 0;
        int right = i - 1;

        // Binary search to find correct position for key
        while (left <= right) {
            int mid = (left + right) / 2;
            if (temp < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Move elements to make room for key
        for (int j=i-1; j>=left; j--) {
            arr[j + 1] = arr[j];
        }

        // Insert key at correct position
        arr[left] = temp;
    }

    // Print sorted array
    cout << "Sorted array using Binary Insertion Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/// Rescue Boat Evacuation
/*Sample Input:
Number of people: 4
Weights of these people: 3 2 2 1
Limit: 3
Sample Output:
3
Explanation:

A group of people is stranded on a small island. Rescue boats are being sent to evacuate them.

Each person has a specific weight.

Can carry at most two people at a time.

Has a weight limit, meaning the total weight of the two passengers must not exceed this limit.

There are unlimited boats and everyone must be rescued.

Your mission is to figure out the minimum number of boats needed to evacuate all the people.*/

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

    int limit;
    cout<<"Limit" ;
    cin>>limit;

    for (int i=1; i<=n-1; i++) {
        int temp = arr[i];
        int left = 0;
        int right = i - 1;

        // Binary search to find correct position for key
        while (left <= right) {
            int mid = (left + right) / 2;
            if (temp < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Move elements to make room for key
        for (int j=i-1; j>=left; j--) {
            arr[j + 1] = arr[j];
        }

        // Insert key at correct position
        arr[left] = temp;
    }

    int light = 0, heavy = n - 1;
    int Boats = 0;

    while (light <= heavy) {
    if (arr[light] + arr[heavy] <= limit) {
        light++;    
    }
    heavy--;        
    Boats++;   
    }
    cout <<Boats<< endl;
    return 0;
}
