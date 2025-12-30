/// Selection Sort

#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
    cout<<"Enter num ";
    cin>>n;
    
    cout<<"Enter element ";
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    // Selection Sort logic
    for (int i=0; i<=n-2; i++) {
        int min = i;
        for (int j=i+1; j<=n-1; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap 
        if(min!=i){
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    }

    // Print sorted array
    cout << "Sorted array in Ascending Order:\n";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

///Selection sort diye max min value find

#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
    cout<<"Enter num ";
    cin>>n;
    
    cout<<"Enter element ";
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for (int i=0; i<=n-2; i++) {
        int min=i;
        for (int j=i+1; j<=n-1; j++) {
            if (arr[j]<arr[min]) {
                min=j;
            }
        }

        if(min!=0){
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        }
    }
    cout << "Sorted array in Ascending Order:\n";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    // Min value
    cout << "Minimum value : " << arr[0] << endl;
    // Max value
    cout << "Maximum value: " << arr[n - 1] << endl;
    return 0;
}

///  Sort an array of integers based on their last digit using Selection Sort.
/*Sample Input:
Array Size: 5
Elements: 12, 45, 32, 90, 51

Sample Output:
Sorted array: 90, 51, 32, 12, 45 */
/// Selection sort[Last digit]

#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
    cout<<"Enter num ";
    cin>>n;
    
    cout<<"Enter element ";
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for (int i=0; i<=n-2; i++) {
        int min = i;
        for (int j=i+1; j<=n-1; j++) {
            if (arr[j]%10 < arr[min]%10) {
                min = j;
            }
        }

        if(min!=i){
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        }
    }
    
    cout << "Sorted array in Ascending Order:\n";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
