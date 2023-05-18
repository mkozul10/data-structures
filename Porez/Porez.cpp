#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct element {
	char	JMBG[13 + 1];
	char	ImePrezime[40 + 1];
	float	Prihod;
	float	PlatitiPorez;
};
typedef struct element zapis;//definiranje tipa podataka

// služi samo da bi se dobili podaci za testiranje
int prepisi(char* filenameIn, char* filenameOut) {//filenameIn=.txt, filenameOut=.dat
	FILE* fin, * fout;
	zapis z;
	int Br;

	fin = fopen(filenameIn, "r");
	fout = fopen(filenameOut, "w");

	if (fin == NULL || fout == NULL) {
		printf("pogreška prilikom prepisivanja podataka");
		return 0;
	}

	fscanf(fin, "%d\n", &Br);
	fwrite(&Br, sizeof(Br), 1, fout);

	while (fscanf(fin, "%s %[^\n] %f %f", z.JMBG, z.ImePrezime, &(z.Prihod), &(z.PlatitiPorez)) > 0) {
		fwrite(&z, sizeof(z), 1, fout);
	}

	fclose(fin);
	fclose(fout);
	return 1;
}

//1. Zadatak
zapis* Ucitaj(char* FileName, int* BrElem) {//Filename=.dat BrElem nije potreban al nam treba u drugom zad pa cemo ga zapisati preko ref
	int	Br;
	FILE* fp;
	zapis* Polje = NULL;
	fp = fopen(FileName, "r");
	// Ovdje pisati kod
	fread(&Br,sizeof(int),1,fp);
	*BrElem=Br;//treba nam u 2.zadatku, zato ga zapisujemo preko reference
	Polje=(zapis*)malloc(sizeof(zapis)*Br);
	for(int i=0;i<Br;i++)
	{
		fread(&Polje[i],sizeof(zapis),1,fp);
	}
	return Polje;
}

//2. Zadatak
int	MaxPorez(zapis* Polje, int BrElem) {
	int	MaxInd = 0;
	float Max;

	if (BrElem <= 0)
		return -1;

	// Ovdje pisati kod
	Max=Polje[0].PlatitiPorez;
	for(int i=1;i<BrElem;i++)
	{
		if(Polje[i].PlatitiPorez>Max)
		{
			Max=Polje[i].PlatitiPorez;
			MaxInd=i;
		}
	}
	return MaxInd;
}

int main() {
	int	BrElem, MaxInd; //lokalne varijable
	char fout[40] = "podaci.dat";
	char fin[40] = "podaci.txt";//stringovi imena datoteka
	zapis* Polje;

	// Prepiši podatke
	prepisi(fin, fout);

	// Učitaj u memoriju
	Polje = Ucitaj(fout, &BrElem);

	// Pronađi tko treba platiti najviše poreza
	if (Polje != NULL) {
		MaxInd = MaxPorez(Polje, BrElem);
		printf("Najvise poreza treba platiti %s, u iznosu od %f", Polje[MaxInd].ImePrezime,
			Polje[MaxInd].PlatitiPorez);
	}

	free(Polje);
	getch();
	return 0;
}
