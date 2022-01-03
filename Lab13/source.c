#include <stdio.h>
#include <stdarg.h>

#define N 10

void insert_elements(void *v, int n, char type, ...)
{
	int count = 0;

	va_list args;
	va_start(args, type);

	if (type == 'c')
	{
		char elem = (char)va_arg(args, int);

		while (elem > 0 && count < n)
		{
			((char *)v)[count++] = elem;
			elem = (char)va_arg(args, int);
		}

		while (count < n)
		{
			((char *)v)[count++] = 'a';
		}
	}

	if (type == 'd')
	{
		int elem = va_arg(args, int);

		while (elem > 0 && count < n)
		{
			((int *)v)[count++] = elem;
			elem = va_arg(args, int);
		}

		while (count < n)
		{
			((int *)v)[count++] = 0;
		}
	}
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x > y ? y : x;
}

int (*f(int (*a) (int, int))) (int, int)
{
	return a;
}

int main()
{
	int v[N];
	int i;

	int elem = f(max)(3, 4);

	printf("Elem: %d\n", elem);

	elem = f(min)(3, 4);

	printf("Elem: %d\n", elem);

	insert_elements(v, N, 'd', 1, 2, 3, 4, -1);

	for (i = 0; i < N; i++)
	{
		printf("%d ", v[i]);
	}

	printf("\n");
	char v2[N];

	insert_elements(v2, N, 'c', 'x', 'y', '\0');

	for (i = 0; i < N; i++)
	{
		printf("%c ", v2[i]);
	}
	
	return 0;
}