#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int re, im;
} comp;

void change(comp *nr1, comp *nr2)
{
	comp aux;
	aux = *nr1;
	*nr1 = *nr2;
	*nr2 = aux;
}

comp *alloc_comp(int nr_complex)
{
	int i;
	comp *p;
	p = malloc(nr_complex * sizeof(comp));
	if (!p)
	{
		fprintf(stderr, "Eroare de alocare\n");
		return NULL;
	}
}

void sort(comp *c, int nr_complex)
{
	int i, j;
	for(i = 0; i < nr_complex; i++)
	{
		int abs1 = sqrt(powf(c[i].re, 2) + powf(c[i].im, 2));
		for (j = 0; j < nr_complex; j++)
		{
			int abs2 = sqrt(powf(c[j].re, 2) + powf(c[j].im, 2));
			if (abs1 == abs2)
			{
				if (c[i].im == c[j].im)
				{
					if (c[i].re < c[j].re)
					{
						change(&c[i], &c[j]);
					}
				}
				else if (c[i].im > c[j].im)
				{
					change(&c[i], &c[j]);
				}
			}
			else if (abs1 > abs2)
			{
				change(&c[i], &c[j]);
			}
		}
	}
}

int main()
{
	int nr_complex, i;
	char enter;
	comp var[50];
	scanf("%d", &nr_complex);
	for (i = 0; i <= nr_complex; i++)
	{
		scanf("(%d, %d)", &var[i].re, &var[i].im);
		scanf("%c", &enter);
	}
	sort(var, nr_complex);
	for (i = 1; i <= nr_complex; i++)
	{
		printf("(%d, %d)\n", var[i].re, var[i].im);
	}
}