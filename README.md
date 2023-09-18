# Instagram_Giveaway
A software in C made for instagram giveaways. This software read the names from a partecipants file and select a prefixed number of winners.

This code comes in 2 different versions. dynamic_giveaway.c is a dynamic version that adapts to every combination of numbers of partecipants and gifts until the hardware memory allows it.
giveaway.c is a simplified and demonstration version. In this Read Me we will treat only the dynamic version, because the simplified one is just a subcase.

First of all, some directory indications. The partecipants file "partecipanti.txt" must be in the same directory as the source file, if not so, adjust the path as you wish.

Now we'll analyze some snippets of code to explain the functioning of the C program.

Here there is the global variables declaration. A struct defines a partecipant of the contest. An array of partecipants will be created to store all the contestants.
It has a name string and a variable extracted to avoid repetition, later we'll se some edits you can do to the code to allow repetitions instead.

Then there are standard variables for files, and counting variables. The variable size will store the amount of partecipants while upper and lower are used to regulate the random number extraction.
Instead numerocodici is the number of gifts you want to giveaway.

```ruby
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
```

This first while iteration is used to traverse the file and count all the partecipants, then the file will be reloaded to complete the storing operations

```ruby
while(fscanf(fp, "%s", read) != EOF)
{
  size++;
}
```

The second while instead, is for storing the partecipants datas into the array

```ruby
while(fscanf(fp, "%s", read) != EOF)
{
    p[pos].name = (char*)malloc(sizeof(char)*64);
    p[pos].name = strdup(read);
    p[pos].extracted = 0;
    pos++;
}
```

In this part the software asks how many gifts you want to giveaway, if the number is bigger of size, it returns in an error status. To allow repetitions, delete the if statement only if your gifts are effectively higher than the number of partecipants

```ruby
printf("Quanti gift vuoi regalare durante il tuo giveaway? ");
scanf("%d", &numerocodici);

if(numerocodici > size)
{
      printf("Stai selezionando un numero di gift maggiore di quello egli utenti, se non hai eliminato l'if statemet che garantisce la non ripetitività degli utenti estratti, elimina anche questo pezzo di     
      codice\n");
      return 1;
}
```

This is the extraction part. The srand(unsigned int) function uses the clock time in seconds since 1st January 1970 as seed to randomize the extraction.
In the while we then extract the random number using upper and lower as regulators. Upper is just size - 1 (In IT we count from 0, so if there are 30 array's sposts, the array's indexes are from 0 to 29).
If the partecipant stored in the array[extracted_index] hasn't already been extracted, we update his extraction counter and the correct counter.
To allow repetitions just delete the if statement and the p[num].extracted = 1

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

Just a few tips on the input file structure and the efficiency of the code. 

The input file has all the partecipants written one per line.
Example:
    Partecipant1
    Partecipant2
    Partecipant3
    ...

The code is just a demo snippet, so i didn't update any big data efficient version with trees, hashmaps and stuffs.
Also because at the time of the personal usage, i didn't need such an efficient structure.

If the dimensions of the pot of partecipants are over 10000 i suggest you to implement a tree to store the partecipants and an hashmap pointing the tree nodes to cross it rapidly without losing O(n/2) at every extraction.

Feel free to use this code as you wish, since it's free and open source
