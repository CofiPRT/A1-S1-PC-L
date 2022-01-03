#include <stdio.h>

int main()
{
	FILE *infile, *outfile;
	infile = fopen("data.in", "r");
	outfile = fopen("data.out", "w");

	int v1[100], v2[100], no1, no2, i;

	fscanf(infile, "%d", &no1);

	for (i = 0; i < no1; i++)
	{
		fscanf(infile, "%d", &v1[i]);
	}

	fscanf(infile, "%d", &no2);

	for (i = 0; i < no2; i++)
	{
		fscanf(infile, "%d", &v2[i]);
	}

	fclose(infile);

	fprintf(outfile, "%d\n", no1 + no2);

	int index1 = 0, index2 = 0;

	while (index1 < no1 && index2 < no2)
	{
		if (v1[index1] >= v2[index2])
		{
			fprintf(outfile, "%d", v2[index2++]);
		}
		else
		{
			fprintf(outfile, "%d", v1[index1++]);
		}

		fprintf(outfile, " ");
	}

	while (index1 < no1)
	{
		fprintf(outfile, "%d", v1[index1++]);

		if (index1 < no1)
		{
			fprintf(outfile, " ");
		}
	}
	while (index2 < no2)
	{
		fprintf(outfile, "%d", v2[index2++]);

		if (index2 < no2)
		{
			fprintf(outfile, " ");
		}
	}

	fprintf(outfile, "\n");
	fclose(outfile);

	return 0;
}