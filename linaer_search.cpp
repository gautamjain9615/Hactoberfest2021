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
    // lineswr search

    for (i = 0; i < n; i++)
    {
        if(num==arr[i]){
            cout<<"The position of the element is:"<<i+1<<"\n";
            cout<<"And the the number is"<<num;
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<"No result found";
    }
