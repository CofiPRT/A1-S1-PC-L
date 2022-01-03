#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *infile, *outfile;
	int *x, n;

	infile = fopen("data.in", "rb");
	outfile = fopen("data.out", "w");

	if (infile == NULL || outfile == NULL)
	{
		printf("Eroare\n");
		exit(1);
	}

	//while (fread(&v[i++], sizeof(int), 1, infile) == 1);
	fseek(infile, 0, SEEK_END);
	n = ftell(infile) / sizeof(int);

	rewind(infile);

	

	x = (int *) malloc(n * sizeof(int));
	if (x == NULL)
	{
		printf("Eroare\n");
		exit(1);
	}

	fread(x, sizeof(int), n, infile);

	if (x == NULL)
	{
		printf("Eroare\n");
		exit(1);
	}

	int i, s = 0;
	for (i = 0; i < n; i++)
	{
		s += x[i];
	}

	fprintf(outfile, "%d\n", s);

	fclose(infile);
	fclose(outfile);
	free(x);
	return 0;
}