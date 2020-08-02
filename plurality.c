#include <cs50.h>
#include <stdio.h>
# include <string.h>


#define MAX 9


typedef struct
{
    string name;
    int votes;
}
candidate;


candidate candidates[MAX];


int candidate_count;


bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    
    
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
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
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(name, candidates[i].name) == 0)
            return i; 
            
    return -1;
}


bool vote(string name)
{
    int candidate_index = get_index(name);
    if (candidate_index != -1)
    {
        candidates[candidate_index].votes++;
        return true; 
    }
    return false;
}

int get_max(void)
{
    int max_votes = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
        if (candidates[i].votes > max_votes)
            max_votes = candidates[i].votes;
            
    return max_votes;
}


void print_winner(void)
{
    int max_votes = get_max();
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
            printf("%s\n", candidates[i].name);
    }
}
