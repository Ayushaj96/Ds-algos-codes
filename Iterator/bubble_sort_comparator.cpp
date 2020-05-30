#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

void bubble_sort(int *arr, int n , bool (&cmp)(int a, int b))
{
	for(int it = 0; it < n - 1; it++)
	{
		for(int j = 0; j < n - it - 1; j++){
			if(compare(arr[j],arr[j+1]))
			{	
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

int main()
{
	int arr[] = {5,3,3,2,3};
	int n = sizeof(arr)/sizeof(int);
	
	bubble_sort(arr,n,compare);
	
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<endl;
}
