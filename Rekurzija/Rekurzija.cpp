#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100
*****************************************************************/
void funkcija1(int n) {
	if (n <= 10) {
		funkcija1(n + 1);
		printf("\n%d", n);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 100 do 1
*****************************************************************/
void funkcija2(int n) {
	if (n <= 10) {
		printf("\n%d", n);
		funkcija2(n + 1);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100 i 100 do 1 
*****************************************************************/
void funkcija3(int n) {
	// Ovdje napisati kod
	if (n <= 10) {
		printf("\n%d", n);
		funkcija3(n + 1);
		printf("\n%d", n);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od [a] do [b]
*****************************************************************/
void funkcija4(int a, int b) {
	// Ovdje napisati kod
	if(a<=b) {
		printf("\n%d", a);
		funkcija4(a + 1,b);
	}
}

/*****************************************************************
	Funkcija koja vraća sumu brojeva od od [a] do [b]
*****************************************************************/
int suma(int a, int b) {
	// Ovdje napisati kod
	if(a<=b)
	{
		int tmp=suma(a+1,b);
		return tmp+a;
	}
	return 0;
}


/*****************************************************************
	Funkcija koja znamenke broja u obrnutom redoslijedu
*****************************************************************/
void funkcija5(int n) {
	// Ovdje napisati kod
	if(n>0)
	{
	printf("%d",n%10);
	funkcija5(n/10);
	}
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto(char* niz, int d) {
	// Ovdje napisati kod
	if(d>=0)
	{
		printf("%c",*(niz+d));
		obrnuto(niz,d-1);
	}
	
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto2(char* niz){
	
	// Ovdje napisati kod
	  if (*niz)
   {
       obrnuto2(niz+1);
       printf("%c", *niz);
   }
}

int main() {
	char niz[] = "Strukture";
	int d=strlen(niz);
	printf("\nfunkcija1\n");
	funkcija1(1);
	printf("\nfunkcija2\n");
	funkcija2(1);
	printf("\nfunkcija3\n");
	funkcija3(1);
	printf("\nfunkcija4\n");
	funkcija4(5,9);
	printf("\nsuma\n");
	printf("Rezultat sume je %d",suma(5,9));
	printf("\nfunkcija5\n");
	funkcija5(876);
	printf("\nobrnuto\n");
	obrnuto(niz,d-1);
	printf("\nobrnuto2\n");
	obrnuto2(&niz[0]);
}