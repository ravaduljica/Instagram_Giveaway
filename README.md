# Instagram_Giveaway
A software in C made for instagram giveaways. This software read the names from a partecipants file and select a prefixed number of winners.

In this snippet, the SIZE is the number of partecipants in the giveaway. It can be modified iterating the file to count up the number of partecipants indipendently.
But all the elements allocated with SIZE, must be dinamically allocated

```ruby
#define SIZE 32

typedef struct Partecipanti {
    char* name;
    int extracted;
} Partecipanti;
```
Variable declaration: It's important to notice the variable numerocodici (codesNumber) that is the number of gifts you want to giveaway. There will be an extraction for every gift

```ruby
FILE* fp = NULL;
Partecipanti p[SIZE];
int pos = 0;
char* read;
int lower = 0;
int upper = SIZE - 1;
int correct = 0;
//Number of gifts to giveaway
int numerocodici = 30;
```

With the srand function we obtain a dynamic seed for the extraction. The seed is the clock time in seconds since the 1st January 1970.
In the while, for every correct extraction (or singular extraction, so no partecipant repeated in the extraction) a counter is incremented by 1 until it reaches the numerocodici soil.

If you want the possibility for a partecipant to win more gifts, just remove the if statement

The num variable is obtained with the writtend formula. It generates a number between 0 and SIZE - 1. Why? Because in IT the first number is zero, so a 32 spots array has positions from 0 to 31.

```ruby
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
```

Feel free to use this code as you wish
