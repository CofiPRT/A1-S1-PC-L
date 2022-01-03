#include <stdio.h>

int main()
{
	FILE *f;
	f = fopen("date.int", rw);
	fb = fopen("binary.int", rwb);

	if (f == NULL && fb == NULL)
	{
		printf("Eroare la deschiderea fisierului\n");
		exit(1);
	}

	int n, i, v[100];

	fscanf(f, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(f, "%d", &v[i]);
	}

	int nb, *vb;

	vb = (int *)malloc(n * sizeof(int));

	fread(&n, sizeof(int), 1, fb);
	fread(vb, sizeof(int), n, fb);

	if (v == NULL)
	{
		printf("Err\n");
		exit(1);
	}
	
	return 0;
}