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


// 1st & last Occurance
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