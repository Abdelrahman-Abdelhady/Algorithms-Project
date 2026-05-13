#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/*--------------------------------------Algorithm 1 Non-Recursive--------------------------------------*/

int birthdayCakeCandles1(int n, int candles[])
{
	int max = 0, count = 0;
	for (int i = 0; i< n; i++)
	{
		
		
			if (max < candles[i])
			{
				max = candles[i];
				count = 0;
			}

	}
	for (int i = 0; i < n ; i++)
	{
		if (max == candles[i])
		{
			count++;
		}
	}
	return count;
}

/*--------------------------------------Algorithm 2 Recursive--------------------------------------*/


int maxElement(int n , int arr[])
{
	int max = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}

	return max;
}

int birthdayCakeCandles2(int n, int arr[],int max = -1)
{
	if (max == -1)
	{
		max = maxElement(n,arr);
	}
	if (n <=0)
	{
		return 0;
	}

	return arr[n-1] == max ? 1 + birthdayCakeCandles2(n - 1, arr, max) : birthdayCakeCandles2(n - 1, arr, max);

}

/*--------------------------------------Algorithm 3 Recursive(merge Sort)--------------------------------------*/

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int tempSize = right - left + 1;
    int* temp = new int[tempSize]; // temporary array to set sorted element
    
    int i = left;
    int j = mid + 1;
    int k = 0;// used in temporary array
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            //add element in temp and incerement i
        temp[k++] = arr[i++];
        else
           //add element in temp and incerement j
        temp[k++] = arr[j++];
    }
    //
    while (i <= mid) {
    temp[k++] = arr[i++];//add remaining elements from left half
    }
    while (j <= right) {
        temp[k++] = arr[j++];//add remaining elements from right half
    }
    // Copy back to original array
    for (int index = 0; index < tempSize; index++) {
        arr[left + index] = temp[index];
    }
    
    delete[] temp; // delete temporary array
}

// this func sorted array
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
     return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid); //sort left half
    mergeSort(arr, mid + 1, right);//sort right half
    merge(arr, left, mid, right);
}

// Birthday Cake Candles function
int birthdayCakeCandles3( int size,int candles[]) {
    if (size == 0)
     return 0; 
    
    mergeSort(candles, 0, size - 1);
    
    int max = candles[size - 1]; // after sorting max in the last index
    int count = 0;
    
    for (int i = size - 1; i >= 0; i--) {
        if (candles[i] == max)
            count++;
        else
            break;
    }
    return count;
}

//main function

int main()
{
	int candles[] = { 3,1,2,3,3 };

	int n = sizeof(candles)/sizeof(int);

	int result = birthdayCakeCandles1(n, candles);
	cout <<"\nThe child will be able to blow "<< result << " Candles" << endl;
	return 0;
}
