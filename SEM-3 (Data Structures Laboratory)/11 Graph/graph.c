#include <stdio.h>
#include <stdlib.h>
#define size 20

void bfs(int amat[][size], int visited[], int src, int n);

void main()
{
	int n, amat[size][size], source, visited[size], i, j;
	printf("Enter the no. of cities\n");
	scanf("%d", &n);
	printf("Enter the Coef. Adjacency Matrix\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &amat[i][j]);
	printf("Enter Source\n");
	scanf("%d", &source);
	for (i = 0; i < n; i++)
		visited[i] = 0;
	bfs(amat, visited, source, n);
	for (i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			printf("%d is not reachable\n", i);
		else
			printf("%d is reachable\n", i);
	}
}

void bfs(int amat[][size], int visited[], int src, int n)
{
	int Q[size], r = 0, f = 0, u, v;
	visited[src] = 1;
	Q[r] = src;
	while (f <= r)
	{
		u = Q[f++];
		for (v = 0; v < n; v++)
		{
			if ((amat[u][v] == 1) && (visited[v] == 0))
			{
				Q[++r] = v;
				visited[v] = 1;
			}
		}
	}
}
