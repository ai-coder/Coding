#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//code to swap two elements
//the * symbol means pointers which are needed to modify an element in a function
//***VERY IMPORTANT***
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//function to implement bubble sort
//notice the '&' operator used to call by reference
void bubbleSort(int arr[], int size_arr)
{
	int i, j;
	for(i=0;i<size_arr;i++)
		for(j=0;j<size_arr-i-1;j++)	//last i elements are already sorted
			if(arr[j]>arr[j+1])
				swap(&arr[j], &arr[j+1]);
}	


//The following code optimises bubblesort to work faster
//The moment there are no swaps in the array the loop exits
void bubbleSortOptimised(int arr[], int size_arr)
{
	int i, j;
	bool swaps = false;
	for(i=0;i<size_arr;i++)
	{
		swaps = false;
		for(j=0;j<size_arr-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				swaps = true;
			}
		}
		if(swaps==false)
		break;
	}
}
int main()
{
	//defining array with a maximum size of 1000
	//maximum input array size should be within the limit
	int arr[1000], size_arr, i;

	//taking input
	cout<<"Please enter the size of the array :  ";
	cin>>size_arr;
	cout<<"Enter elements of the array :  ";
	for(i=0;i<size_arr;i++)
		cin>>arr[i];
		
	//calling bubbleSort function
	//remove the "//" below to run simple bubble sort
	//bubbleSort(arr, size_arr);
	
	//this is the optimised bubble sort
	bubbleSortOptimised(arr, size_arr);
	
	//printing the elements of the array
	for(i=0;i<size_arr;i++)
		cout<<arr[i]<<"    ";
	return 0;
}
