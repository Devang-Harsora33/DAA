#include <stdio.h>

#define MAX 1000000

int dist[5][5] = {
	{ 0, 0, 0, 0, 0 },
    { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, 
    { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[5][1 << 5];

int fun(int i, int mask)
{
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	for (int j = 1; j <= 4; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = (res > fun(j, mask & (~(1 << i))) + dist[j][i]) ? (res = fun(j, mask & (~(1 << i))) + dist[j][i]) : res;
	return memo[i][mask] = res;
}

int main()
{
	int ans = MAX;
	for (int i = 1; i <= 4; i++)
		ans = (ans > fun(i, (1 << 5) - 1) + dist[i][1]) ? (ans = fun(i, (1 << 5) - 1) + dist[i][1]) : ans;

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}