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



int birthdayCakeCandles3(int n, int arr[],int max = -1)
{	
	if (max == -1)
	{
		max = *max_element(arr, arr + n);
	}
	if (n <=0)
	{
		return 0;
	}
	return arr[n-1] == max ? 1 + birthdayCakeCandles3(n - 1, arr, max) : birthdayCakeCandles3(n - 1, arr, max);
	
}




int main()
{
	list<int> candles = {1,5,4,4,3,5,4};
	int arr[] = { 1,1,2,3,3 };
	
	int n= candles.size();
	
	int result = birthdayCakeCandles1(sizeof(arr)/sizeof(int), arr);
	cout <<"\nThe child will be able to blow "<< result << " Candles" << endl;
	return 0;
}
