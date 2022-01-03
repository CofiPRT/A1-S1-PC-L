#include <stdio.h>

typedef struct
{
	char CNP[14];
	char numeElev[100];
	float medieElev;
}TElev;

typedef struct 
{
	short numeScoala;
	char numeDirector[100];
	float medieScoala;
	int nrElevi;
	TElev *elevi;
}TScoala;

typedef struct
{
	int nrScoli;
	TScoala **scoli;
}TScoli;

TScoala *alocaScoala(int nrElevi)
{
	TScoala *sc = (TScoala *) malloc(sizeof(TScoala));
	if (sc)
	{
		sc -> nrElevi = nrElevi;
		sc -> numeScoala = 0;
		sc -> medieScoala = 0;
		strcpy(sc -> numeDirector, "\0");
		sc -> elevi = (TElev *) malloc(nrElevi * sizeof(TElev));

		if (sc -> elevi)
		{
			for (i = 0; i < nrElevi; i++)
			{
				strcpy(sc -> elevi[i].CNP, "\0");
				strpcy(sc -> elevi[i].numeElev, "\0");
				sc -> elevi[i].medieElev = 0;
			}
		}
		else
		{
			free(sc);
			sc = NULL;
		}
	}
	return sc;
}

TScoala **alocaScoli(int nrScoli)
{
	int i, j;
	TScoala **scoli = (TScoala **) malloc(sizeof(TScoala *) * nrScoli);
	if (scoli)
	{
		int i;
		for (i = 0; i < nrScoli; i++)
		{
			scoli[i] = alocaScoala(100);
			if (!scoli[i])
			{
				int j;
				for (j = 0; j < i; j++)
				{
					free(scoli[j]);
				}
				free(scoli);
				scoli = NULL;
			}
		}
	}
	return scoli;
}

void dezalocaScoala(TScoala *sc)
{
	if (sc)
	{
		if(sc -> elevi)
		{
			free(sc -> elevi);
		}
		free(sc);
		sc = NULL;
	}
}

void dezalocaScoli(TScoala **scoli, int nrScoli)
{
	int i;
	if (scoli)
	{
		for (i = 0; i < nrScoli; i++)
		{
			free(scoli[i]);
		}
		free(scoli);
		scoli = NULL;
	}
}

void writeToFile(FILE *fout)
{
	int nrScoli, i;
	scanf("%d", &nrScoli);
	fwrite(&nrScoli, sizeof(int), 1, fout);

	for (i = 0; i < nrScoli; i++)
	{
		scanf("%hd", &numeScoala);
		fwrite(&numeScoala, sizeof(short int), 1, fout);
	}
}

TScoli readFromFile(FILE *fin)
{
	TScoli t;
	int i;
	fread(&t.nrScoli, sizeof(int), 1, fin);
	t.scoli = alocaScoli(t.nrScoli);
	if (t.scoli)
	{
		for (i = 0; i < t.nrScoli; i++)
		{
			fread(&t.scoli[i] -> numeScoala, sizeof(short int), 1, fin);
		}
	}
	return t;
}

void sorteazaScoliFetePromovate(TScoala **scoli, int nrScoli)
{

}

int main()
{

}