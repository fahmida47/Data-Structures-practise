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
/// Unsorted array & find the index of 1st occurance of the target value {5,2,9,1,7,3},target-7, output-4

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;

    cout<<"Enter elements ";
    int arr[n];

    for(int i=0;i<=n-1;i++)
    {
       cin>>arr[i];
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == target){
            cout << "Target found at index: " << i << endl;
            return 1;
        }
    }

    cout << "Target not found." << endl;
    return -1;
}

/// Binary search {1,3,5,7,10,12},target-7, output-3

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter num: ";
    cin>>n;
    
    cout<<"Enter elements: ";
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;
    cout<<"Enter target ";
    cin>>target;

    int left=0;
    int right=n-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(arr[mid] == target){
            cout << "Target found at index: " << mid << endl;
            return mid;
        }

        else if(arr[mid]<target){
            left = mid+1;
        }

        else {
            right = mid-1;
        }
    }
    
    cout << "Target not found." << endl;
    return -1;
}

/// 1st Occurance of Binary search {1,7,7,7,10,12},target-7, output-1

// 1st & last 
#include<bits/stdc++.h>
using namespace std;
int firstoccurence(vector<int>&W,int len,int t){
    int low=0;
    int high=len-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(W[mid]==t){
            ans=mid;
            high=mid-1;
        }
        else if(W[mid]<t){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans!=-1){
        return ans;
    }
}
int lastoccurence(vector<int>&W,int len,int t){
    int low=0;
    int high=len-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(W[mid]==t){
            ans=mid;
            low=mid+1;
        }
        else if(W[mid]<t){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans!=-1){
        return ans;
    }
}
int main()
{
  int s;
  cout<<"Enter the size:"<<endl;
  cin>>s;
  vector<int>a(s);
  for(int i=0;i<s;i++){
    cin>>a[i];
  }
  int target;
  cout<<"Enter the value to search:"<<endl;
  cin>>target;
  int first=firstoccurence(a,s,target);
  int last=lastoccurence(a,s,target);

  cout<<first<<endl;
  cout<<last<<endl;
  int count1=(last-first);
  cout<<"For found:"<<count1<<endl;
}


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

/// Random Search 

// With Replacement

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[] = {5, 12, 7, 19, 25, 30};  // Input array
    int n = 6;                         // Size of array
    int x = 19;                        // Target value

    srand(time(0));  // Random seed

    int i;  // index

    // 1. Do
    do {
        // 2. i = Random_Select()
        i = rand() % n;

        // 3. IF A[i] == x
        if (A[i] == x) {
            // 4. return i
            cout << "Found at index: " << i << endl;
            return 0;
        }

        // 5. End IF
        // 6. While A[i] != x
    } while (A[i] != x);

    return 0;
}

///Merge Sort

#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int m = mid - left + 1;
    int n = right - mid;

    int L[m+1], R[n+1]; 

    for (int i = 0; i < m; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n; j++)
        R[j] = arr[mid + 1 + j];
        
    L[m] = INT_MAX;
    R[n] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);     // বাম দিক
        MergeSort(arr, mid + 1, right); // ডান দিক
        Merge(arr, left, mid, right);   // Merge
    }
}
int main() {
    

    cout<<"Enter num: ";
    int num;
    cin>>num;

    cout<<"Enter Element: ";
    int arr[num];

    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }

    MergeSort(arr,0,num-1);

    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
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


















