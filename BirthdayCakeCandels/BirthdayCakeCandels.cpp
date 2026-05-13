#include <iostream>
#include <list>
#include <algorithm>

using namespace std;



int birthdayCakeCandles1(int n, int candles[])
{
	int max = 0, count = -1;
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


//main function

int main()
{
	int candles[] = { 3,1,2,3,3 };

	int n = sizeof(candles)/sizeof(int);

	int result = birthdayCakeCandles1(n, candles);
	cout <<"\nThe child will be able to blow "<< result << " Candles" << endl;
	return 0;
}
