#include <stdio.h>

int trazi(int trazeni)
{
    FILE* f = fopen("brojevi.dat", "r");

    bool pronadjen = false;
    int br;
    int sredina;
    int poc = 0;

    fseek(f, 0, SEEK_END);
    int kraj = ftell(f) / sizeof(int);

    do {
        // Ovdje pisati kod
        sredina=(poc+kraj)/2;
        fseek(f,sizeof(int)*sredina,SEEK_SET);
        fread(&br,sizeof(int),1,f);
        printf("\nTrazim u a[%2d:%2d], a[%2d]=%2d", poc, kraj, sredina, br);
        if(trazeni>br)
        {
        	poc=sredina+1;
		}
		else if(trazeni<br)
		{
			kraj=sredina-1;
		}
		else
		{
			pronadjen=true;
			break;
		}

    } while (poc <= kraj);

    return pronadjen ? 1 : 0;
}

int main() {

    FILE* f, * fb;
    int br;
    f = fopen("brojevi.txt", "r");
    fb = fopen("brojevi.dat", "w+");

    // Ovdje napisati kod
    while(fscanf(f,"%d",&br)!=EOF)
    {
    	printf("%d ",br);
    	fwrite(&br,sizeof(int),1,fb);
	}

    fclose(f);
    fclose(fb);

    printf("\nPronadjen = %d", trazi(5));
}