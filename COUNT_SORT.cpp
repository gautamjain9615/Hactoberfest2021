#include<iostream>
using namespace std;

void fill(int a[],int n)
{
	for(int i=0;i<n;i++)
	cin>>a[i];
}

void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

int maximum(int a[],int n)
{
	int lar=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>lar)
		lar=a[i];
	}
	return lar;
}

void CountSort(int a[],int n)
{
	
	int max=maximum(a,n);
	int count[max+1]={0};
	int output[n];
	for(int i=0;i<n;i++)
	count[a[i]]++;
	
	for(int i=1;i<=max;i++)
	count[i]=count[i]+count[i-1];
	
	for(int i=n-1;i>=0;i--)
	output[--count[a[i]]]=a[i];
	display(output,n);
	
}

int main(void)
{
	int n;
	cout<<"\n enter size of array : ";
	cin>>n;
	int a[n];
	cout<<"\n enter elements in array : ";
	fill(a,n);
	cout<<"\n array before sorting : ";
	display(a,n);
	cout<<"\n array after sorting : ";
	CountSort(a,n);
return 0;
}
/* OUTPUT:
enter size of array : 6

 enter elements in array : 3 2 6 4 7 3

 array before sorting : 3 2 6 4 7 3
 array after sorting : 2 3 3 4 6 7
 */
