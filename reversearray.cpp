#include<iostream>
using namespace std;
int main()
{
int start=1,end,n,A[100];
cout<<"enter the value of n:";
cin>>n;
end=n;
for(start=1;start<=n;start++)
{
    cin>>A[start];
}
cout<<"element are:::";
for(start=1;start<=n;start++)
{
    cout<<A[end]<<",";
    end=end-1;
}
return 0;

}