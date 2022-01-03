#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push_back(int **v, int *len, int *capacity, int nr)
{
	if (*len == *capacity)
	{
		*capacity *= 2;
		int *p = realloc(*v, (*capacity) * sizeof(int));
		if (p != NULL)
		{
			*v = p;
		}
	}

	(*v)[*len] = nr;
	(*len)++;
}

int main()
{
	int len = 0, capacity = 1, nr, i;
	int *v = (int *) malloc(sizeof(int));

	for(;;)
	{
		scanf("%d", &nr);
		if (nr < 0)
		{
			break;
		}
		push_back(&v, &len, &capacity, nr);
		for (i = 0; i < len; i++)
		{
			printf("%d ", v[i]);
		}
		printf("\n");
	}

	return 0;
}