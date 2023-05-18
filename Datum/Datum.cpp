#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*****************************************************************
	Funkcija fraća datum u obliku DD.MM.GG
*****************************************************************/
char* datum(char* jmbg) //DD.MM.GG.
{
	// Ovdje pisati kod

	return NULL;
}

int kontrola(char* jmbg)
{
	char p[12 + 1] = "765432765431";

	int ZZZ = 0, OST, RAZ, K;
	K = jmbg[12] - '0';
	for (int i = 0; i < 12; i++)
		ZZZ += (jmbg[i] - '0') * (p[i] - '0');
	OST = ZZZ % 11;
	RAZ = 11 - OST;

	if (OST == 1)
		return 0;
	else if (OST == 0 && K == 0)
		return 1;
	else if (OST > 1 && OST < 11 && K == RAZ)
		return 1;
	else
		return 0;
}

int main()
{
	//Datum
	printf("Pretvorba datuma:\n");
	char jmbg[14] = "2903002152638"; //0318964384002

	int  p = kontrola(&jmbg[0]);

	if (p == 0) {
		printf("Maticni broj je pogresan");
		return -1;
	}

	char* pom = datum(jmbg);
	printf("%s", pom);

	getch();

	return 1;
}