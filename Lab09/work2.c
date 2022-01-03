#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int *matrix = (int *) malloc(n * n *sizeof(int));
	int **pointers = (int **) malloc(n * sizeof(int *));

	int i;
	for (i = 0; i < n * n; i++)
	{
		matrix[i] = i;
	}

	for (i = 0; i < n; i++)
	{
		pointers[i]=&matrix[i*n];
	}

	int j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", pointer[j][i]);
		}
	}

	printf("\n");

	return 0;
	 

}