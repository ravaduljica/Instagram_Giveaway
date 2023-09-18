#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct Partecipanti {
    char* name;
    int extracted;
} Partecipanti;

FILE* fp = NULL;
Partecipanti* p;
int pos = 0;
char* read;
int lower = 0;
int upper = 0;
int correct = 0;
int size = 0;
//Number of gifts to giveaway
int numerocodici;

int main()
{
    //Opens the file with the contestants
    fp = fopen("partecipanti.txt", "r");

    //Alloca la variabile di lettura
    read = (char*)malloc(sizeof(char)* 64);

    printf("Carico il numero di partecipanti\n");

    while(fscanf(fp, "%s", read) != EOF)
    {
        size++;
    }

    printf("Ci sono in tutto %d partecipanti\n", size);

    printf("Caricamento lista\n");

    p = (Partecipanti*)malloc(sizeof(Partecipanti)*size);

    fclose(fp);
    fp = fopen("partecipanti.txt", "r");

    //Read and upload the values of the partecipants in the array
    while(fscanf(fp, "%s", read) != EOF)
    {
        p[pos].name = (char*)malloc(sizeof(char)*64);
        p[pos].name = strdup(read);
        p[pos].extracted = 0;
        pos++;
    }

    printf("%d partecipanti su %d caricati\n", pos--, size);

    upper = size - 1;

    printf("Quanti gift vuoi regalare durante il tuo giveaway? ");
    scanf("%d", &numerocodici);

    //Uses clock time as a random seed for the extraction
    srand ( time(NULL) );

    printf("Procedo all'estrazione\n");

    //Estrae i codici
    while(correct < numerocodici)
    {
        int num = (rand() % (upper - lower + 1)) + lower;

        //To avoid repetition, it checks if the particular partecipant has already been extracted
        if(p[num].extracted == 0)
        {
            printf("Vincitore estratto: %s\n", p[num].name);
            p[num].extracted = 1;
            correct++; 
        }
    }

    printf("\nEstratti %d vincitori su %d previsti\n", correct, numerocodici);

    return 0;
}