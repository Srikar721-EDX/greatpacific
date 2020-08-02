#include <cs50.h>
#include <stdio.h>
# include <string.h>


#define MAX 9


typedef struct
{
    string name;
    int votes;
}
canidate;


canidate canidates[MAX];


int canidate_count;


bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    
    if (argc < 2)
    {
        printf("Usage: plurality [canidate ...]\n");
        return 1;
    }
    
    
    canidate_count = argc - 1;
    if (canidate_count > MAX)
    {
        printf("Maximum number of canidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < canidate_count; i++)
    {
        canidates[i].name = argv[i + 1];
        canidates[i].votes = 0;
    }
    
    int voter_count = get_int("Number of voters: ");
    
    
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        
        
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    
    
    print_winner();
}

int get_index(string name)
{
    for (int i = 0; i < canidate_count; i++)
        if (strcmp(name, canidates[i].name) == 0)
            return i; 
            
    return -1;
}


bool vote(string name)
{
    int canidate_index = get_index(name);
    if (canidate_index != -1)
    {
        canidates[canidate_index].votes++;
        return true; 
    }
    return false;
}

int get_max(void)
{
    int max_votes = canidates[0].votes;
    for (int i = 1; i < canidate_count; i++)
        if (canidates[i].votes > max_votes)
            max_votes = canidates[i].votes;
            
    return max_votes;
}


void print_winner(void)
{
    int max_votes = get_max();
    
    for (int i = 0; i < canidate_count; i++)
    {
        if (canidates[i].votes == max_votes)
            printf("%s\n", canidates[i].name);
    }
}
