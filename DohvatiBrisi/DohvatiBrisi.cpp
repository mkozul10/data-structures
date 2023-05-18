#include <stdio.h>
#include <conio.h>

struct zapis {
	int mbr;
	char ime[40 + 1];
	char spol[1 + 1];
};

/*****************************************************************
	Funkcija vraća i briše zapis s zadanim [mbr] iz direktne
	datoteke.
*****************************************************************/
struct zapis dohvati_brisi(FILE* direktna, int mbr) {
	struct zapis z {}, z1{};

	// Ovdje pisati kod
	fseek(direktna,mbr*sizeof(zapis),SEEK_SET);//postavljamo kursor na poziciju preko mbr-a
	fread(&z,sizeof(zapis),1,direktna);//stavljamo u strukturu z podatak koji cemo brisat da ga mozemo vratiti u main
	int a=0;
	fwrite(&a,sizeof(int),1,direktna);//brisanje podatka
		
	return z;
}

int main() {
	struct zapis z;
	int mbr, i;
	FILE* slijedna, * direktna;
	if (!(slijedna = fopen("studenti.txt", "r"))) {
		printf("\nNema ulazne dateke studenti.txt\n");
		return 1;
	}
	// Stvaranje direktne neformatirane datoteke iz slijedne formatirane 
	if (!(direktna = fopen("studenti.dat", "w+b"))) {
		printf("\nNe mogu otvoriti direkltnu datoteku studenti.dat\n");
		fclose(slijedna);
		return 1;
	}

	// Pražnjenje direktne datoteke
	z.mbr = 0;
	for (i = 0; i <= 999; i++) fwrite(&z, sizeof(z), 1, direktna);

	// Prijepis iz slijedne formatirane u direktnu neformatiranu
	while (fscanf(slijedna, "%3d%s%s", &z.mbr, z.ime, z.spol) != EOF) {

		printf("Procitan zapis %d %s %s\n", z.mbr, z.ime, z.spol);

		fseek(direktna, z.mbr * sizeof(struct zapis), SEEK_SET);

		fwrite(&z, sizeof(z), 1, direktna);
	}

	// Dohvat i brisanje
	while (1) {
		printf("\nUpisite mbr >");
		scanf("%d", &mbr);
		z = dohvati_brisi(direktna, mbr);
		if (z.mbr) {
			printf("Izbrisan zapis: %d %s %s", z.mbr, z.ime, z.spol);
		}
		else {
			printf("\nNema zapisa s mbr = %d\n", mbr);
			break;
		}
	}

	getch();
	return 0;
}
