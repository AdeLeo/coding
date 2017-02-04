#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_VALUE (~(1<<((sizeof(int)*sizeof(char))-1)))
#define MIN(a, b) ((a)>(b)?(b):(a))

int minCoinsl(int *arr, int len, int aim)
{
	assert(arr != NULL && len >= 0 && aim >=0);

	int max = MAX_VALUE;

	int dp[n][aim+1];

	int j = 1;
	for(j = 1; j < aim; j++)
	{
		dp[0][j] = max;
		if(j - arr[0] >= 0 && dp[0][j-arr[0]] != max)
			dp[0][j] = dp[0][j-arr[0]] + 1;
	}
	int left = 0;
	int i = 0;
	for(i = 1; i < n; i++)
	{
		for(j = 1; j <= aim; j++)
		{
			left = max;
			if(j-arr[i] >= 0 && dp[i][j-arr[i]] != max)
				left = dp[i][j-arr[i]] + 1;
			dp[i][j] = MIN(left, dp[i-1][j]);
		}
	}

	return dp[n-1][aim] != max ? dp[n-1][aim]:-1;
}
