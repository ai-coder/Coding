#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Swap function
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//This function takes the rightmost element as pivot as places the smaller elements to the left and larger to the right. It returns the current index of the pivot.
int partition(int arr[], int left, int right)
{
	//rightmost element is set as pivot
	int pivot = arr[right];
	//i is first set to -1
	int i = left - 1, j;
	
	//for array this loops traverses from left to right and swaps elements smaller than pivot to the ith i.e. left elements and larger elements to the right
	for(j = left; j<=right-1;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	//swapping the pivot to the middle
	swap(&arr[i+1], &arr[right]);
	//returns pivot index
	return i+1;
}

//Quicksort function
//Makes recursive call to the array
void quickSort(int arr[], int left, int right)
{
	if (left<right)
	{
		int pi = partition(arr, left, right);
		quickSort(arr, left, pi-1);
		quickSort(arr, pi+1, right);
	}
}

int main()
{
	int N, arr[1000];
	//input and initialization
	//N is the size of the array
	cout<<"Enter the size of the array : ";
	cin>>N;
	cout<<"Enter elements with space : ";
	for(int i=0;i<N;i++)
		cin>>arr[i];
	
	//function call by passing the left and the right index
	quickSort(arr, 0, N-1);
	
	for(int j=0;j<N;j++)
		cout<<arr[j]<<"  ";
	return 0;
}
