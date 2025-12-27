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
