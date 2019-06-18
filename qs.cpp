#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}

int partition(int arr[],int l,int h)
{
	int pivot=arr[l];
	int i=(l+1);
	for (int j=(l+1);j<=h;j++)
  	{
		if(arr[j]<pivot)
		{
			
			swap(arr[j],arr[i]);
			i++;
		}
  	}


	swap(arr[l], arr[i-1]);
	return (i-1);
} 


void quicksort(int arr[],int l,int h)
{
	if(l<h)
	{
		int p=partition(arr,l,h);
		quicksort (arr,l,p-1);
		quicksort (arr,p+1,h);
	}	
}

int main (){
	int n;
	cout<<"enter no of element:";
	cin>>n;
	int arr[n];
	cout<<"enter the array element:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
	}

	quicksort(arr,0,n-1);

	cout<<"after quicksort the arry is:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
