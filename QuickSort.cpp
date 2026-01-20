topic-01
//-----------------------------------Basic Code----------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p - 1);   // left part
        QuickSort(arr, p + 1, high);  // right part
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

Topic-02
//-----------------------------Online Ques Solve---------------------------//
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    char name[50];
    double cgpa;
};

int Partition(Student SA[], int l, int r )
{
    double pivot = SA[r].cgpa;
    int i=l-1;

    for (int j=l; j<r; j++)
    {
        if (SA[j].cgpa<pivot)
        {
            i++;
            Student temp = SA[i];
            SA[i] = SA[j];
            SA[j] = temp;
        }
    }
    Student temp = SA[i+1];
    SA[i+1] = SA[r];
    SA[r] = temp;

    return i + 1;
}

void quickSort(Student SA[], int l, int r)
{
    if (l<r)
    {
        int q=Partition(SA,l,r);
        quickSort(SA,l,q-1);
        quickSort(SA,q+1,r);
    }
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student SA[n];

    for (int i=0; i<n; i++)
    {
        cout << "Enter details for student " <<i+1<< ":\n";
        cout << "ID: ";
        cin >> SA[i].id;
        cin.ignore();
        cout << "Name: ";
        cin.getline(SA[i].name, 50);
        cout << "CGPA: ";
        cin >> SA[i].cgpa;
    }

    quickSort(SA,0,n-1);
    cout << "\nAfter Sorting:" << endl;

    for (int i=0; i<n; i++)
    {
        cout << "ID: " << SA[i].id << ", Name: " << SA[i].name
             << ", CGPA: " << SA[i].cgpa << endl;
    }

    return 0;
}

