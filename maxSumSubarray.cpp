#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int maxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}

int main() 
{
    int arr[] = {1,5,3,8,12};
    cout << maxSum(arr,5);
    return 0;
}