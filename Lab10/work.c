#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day, month, year;
} Date;


typedef struct {
  char firstname[50], lastname[50];
  int nr_pers;
  Date *birthday;
} InfoPers;


InfoPers *alloc_persons(int nr_persons)
{
  int i, j;
  InfoPers *p;

  p = malloc(nr_persons * sizeof(InfoPers));
  if (!p) {
    fprintf(stderr, "Eroare de alocare");
    return NULL;
  }

  for (i = 0; i < nr_persons; i++) {
    p[i].birthday = malloc(sizeof(Date));
    p[i].nr_pers = nr_persons;

    if (!p[i].birthday) {
      for (j = 0; j < i; j++) {
        free(p[j].birthday);
      }

      free(p);
      fprintf(stderr, "Eroare de alocare");
      return NULL;
    }
  }

  return p;
}


int check_verified(char (*verified_name)[50], char *name, int nr_verified)
{
  int i;

  for (i = 0; i < nr_verified; i++) {
    if (strcmp(verified_name[i], name) == 0) {
      return 1;
    }
  }

  return 0;
}



void free_persons(InfoPers **pers)
{
  int i;

  for (i = 0; i < (*pers)->nr_pers; i++) {
    free((*pers)[i].birthday);
  }

  free(*pers);

  *pers = NULL;
}


void read_persons(InfoPers *pers)
{
  int i;

  for (i = 0; i < pers->nr_pers; i++) {
    printf("FirstName ");
    fgets(pers[i].firstname, 50, stdin);
    printf("LastName ");
    fgets(pers[i].lastname, 50, stdin);
    printf("Birthday ");
    scanf("%d", &pers[i].birthday->day);
    scanf("%d", &pers[i].birthday->month);
    scanf("%d", &pers[i].birthday->year);
    getchar();
  }
}


void print_persons(InfoPers *pers)
{
  int i;

  printf("=========================\n");
  printf("Read persons\n");
  for (i = 0; i < pers->nr_pers; i++) {
    printf("FirstName: %s", pers[i].firstname);
    printf("LastName: %s", pers[i].lastname);
    printf("Birthday: %d/%d/%d\n", pers[i].birthday->day,
           pers[i].birthday->month, pers[i].birthday->year);
  }
}


void print_same_firstname(InfoPers *pers)
{
  int i, j;

  int nr_verified = 0;
  char verified_name[50][50];

  for (i = 0; i < pers->nr_pers; i++) {
    int count = 1;
    if (check_verified(verified_name, pers[i].firstname, nr_verified)) {
      continue;
    }

    for (j = i+1; j < pers->nr_pers; j++) {
      if (strcmp(pers[i].firstname, pers[j].firstname) == 0) {
        count++;
      }
    }

    strcpy(verified_name[nr_verified++], pers[i].firstname);
    printf("Persons with the name %s%d\n", pers[i].firstname, count);
  }

}

void print_same_birthday(InfoPers *pers)
{
	int i, j;

	int nr_verified = 0;
	int verified_year[50];
	char verified_name[50][50];
	int count = 1;
	for (i = 0; i < pers->nr_pers; i++)
	{
		if (check_verified(verified_name, pers[i].firstname, nr_verified))
		{
			continue;
		}

		for (j = i + 1; j < pers->nr_pers; j++)
		{
			if (pers[i].birthday -> year == pers[j].birthday -> year)
			{
				count++;
			}
		}

		verified_year[nr_verified++] = pers[i].birthday -> year;
	}

	printf("Numarul persoanelor nascute in %d este: %d\n", verifid, coverifidunt);
}

int check_year(int verified_year[50], int year, int nr_verified)
{
	int i;
	for (i = 0; i < nr_verified; i++)
	{
		if (verified_year[i] == year)
		{
			return 1;
		}
	}

	return 0;
}

void swap_pers(InfoPers *pers1, InfoPers *pers2)
{
	InfoPers aux;
	aux = *pers1;
	*pers1 = *pers2;
	*pers2 = aux;
}

void sort(InfoPers *pers)
{
	int i, j;
	for (i =0; i < pers -> nr_pers; i++)
	{
		for (j = 0; j < pers -> nr_pers; j++)
		{
			if (strcmp(pers[i].lastname, pers[j].lastname) == 0)
			{
				if(strcmp(pers[i].firstname, pers[j].firstname) < 0)
				{
					swap_pers(&pers[i], &pers[j]);
				}
			}
			else if (strcmp(pers[i].lastname, pers[j].lastname) < 0)
			{
				swap_pers(&pers[i], &pers[j]);	
			}
		}
	}
}

int main(void)
{
  int nr_persons, i;
  InfoPers *pers;

  printf("Nr Persons = ");
  scanf("%d", &nr_persons);
  getchar();

  pers = alloc_persons(nr_persons);
  read_persons(pers);

  print_same_birthday(pers);

  sort(pers);

  print_persons(pers);
  free_persons(&pers);

  return 0;
}