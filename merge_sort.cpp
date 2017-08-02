#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//merge function
//divided the array into two == l to m and m+1 to r
void merge(int arr[], int l, int m, int r)
{
	int index_L=0, index_R=0, index_arr=l, i;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1],R[n2];
	
	//copy the subarrays - making separate arrays l to m and m+1 to r
	for(i=0;i<n1;i++)
		L[i] = arr[l+i];
	for(i=0;i<n2;i++)
		R[i] = arr[m+1+i];
	
	//copy the smaller of the first value of the two subarrays to the main array
	//and continue copying the smaller one to the main array
	//by the time program control reaches here the two subarrays will be sorted
	while(index_L<n1 && index_R<n2)
	{
		L[index_L]<=R[index_R]? arr[index_arr] = L[index_L] : arr[index_arr] = R[index_R];
		L[index_L]<=R[index_R]? index_L++ : index_R++;
		index_arr++;
	}
	
	//copying the either of the two subarrays elements left
	while(index_L<n1)
	{
		arr[index_arr] = L[index_L];
		index_arr++;
		index_L++;
	}
	while(index_R<n2)
	{
		arr[index_arr] = R[index_R];
		index_arr++;
		index_R++;
	}
}

//mergeSort function - l and r are the left and right index
//first it is separated in two subarrays then merged
void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid = l+(r-l)/2;
		mergeSort(arr,l, mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main()
{
	int arr[1000], size_arr, i;
	//taking input
	cout<<"Enter the size of the array : ";
	cin>>size_arr;
	cout<<"Enter the elements of the array : ";
	for(i=0;i<size_arr;i++)
		cin>>arr[i];
		
	//calling the driver function
	mergeSort(arr,0,size_arr-1);
	
	//Displaying the output
	for(i=0;i<size_arr;i++)
		cout<<arr[i]<<"   ";
	return 0;
}
