#include<iostream>
using namespace std;
int main(){
int key;
cin>>key;
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];

}
int count=0;
for(int i=0;i<n;i++){
    if(a[i]==key){
        count++;
    }
}
cout<<count;
return 0;

}