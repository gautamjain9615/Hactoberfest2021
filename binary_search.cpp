#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,num,i,flag=1;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>num;

    //binary search - sorted array needed

    int j,start=0 , end=n;
    while(start<end)
    {
        int mid=(start+end)/2;
        if (arr[mid]== num)
        {
            cout<<"The position of the number is:"<<mid+1;
            cout<<"\nThe number is:"<<num;
            break;
        }
        if (arr[mid] > num)
        end=mid-1;
        if (arr[mid] < num)
        start=mid+1;
    }
     
 return 0;
}
