#include <stdio.h>
#include <string.h>

/*
    Dato il file CSV Pokemon.csv costituito da 3 campi: NUMERO,NOME,TIPO
    a) creare una struct POKE costituita da 3 campi : int number, char name[50], char type[50]
    b) leggere con un programma C il file csv caricando i dati in array VP di struct POKE lungo 100
    c) per verifica, stampare il contenuto di tutto l'array VP
    d) scansionare il vettore VP di struct e trovare il pokemon con il nome più lungo
*/

/*
    CVS:
        Numero ,Nome ,Tipo
        63,Abra,Psico
        359,Absol,Buio
        662,Fletchinder,Fuoco
        617,Accewlgor,Coleottero
        1009,Acquecrespe,Acqua
        681,Aegislash,Acciao
        306,Aggron,Roccia
        172,Pichu,Elettro
        25,Pikachu,Elettro
 */


int main(void) {

    struct Poke {
        int Number;
        char Name[50];
        char Type[50];
    };

    struct Poke PV[100];

    FILE *FilePoint = fopen("../pokemon.csv", "r");
    char Buffer[1000];

    if (FilePoint == NULL) {
        printf("Errore nell'apertura del file");
        return 1;
    }

    fgets(Buffer, 100, FilePoint);

    int i = 0;
    while (fgets(Buffer, 1000, FilePoint) != NULL && i < 100) {
        sscanf(Buffer, "%d,%[^,],%s", &PV[i].Number, PV[i].Name, PV[i].Type);
        i++;
    }

    fclose(FilePoint);

    i = 0;
    while (i < 100 && PV[i].Number != 0) {
        printf("Pokemon #%d:\n", i + 1);
        printf("Numero: %d\n", PV[i].Number);
        printf("Nome: %s\n", PV[i].Name);
        printf("Tipo: %s\n", PV[i].Type);
        i++;
    }

    int MaxLength = 0, MaxIndex = 0;
    char LongestName[50];
    i = 0;

    do {
        if (strlen(PV[i].Name) > MaxLength) {
            MaxLength = strlen(PV[i].Name);
            MaxIndex = i;
            strcpy(LongestName, PV[i].Name);
        }
        i++;
    }while(i < 100 && PV[i].Number != 0);

    printf("\nIl Pokemon con il nome piu' lungo e': %s", PV[MaxIndex].Name);

    return 0;
}
