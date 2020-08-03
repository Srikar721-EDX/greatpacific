#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9


int preferences[MAX_VOTERS][MAX_CANDIDATES];


typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


candidate candidates[MAX_CANDIDATES];


int voter_count;
int candidate_count;


bool vote(int water, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    
    
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    
    
    for (int i = 0; i < voter_count; i++)
    {
        
        
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            
            
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        
        printf("\n");
    }
    
    
    while (true)
    {
       
       tabulate();
       
       
       bool won = print_winner();
       if (won)
       {
           break;
       }
       
       
       int min = find_min();
       bool tie = is_tie(min);
       
       
       if (tie)
       {
           for (int i = 0; i < candidate_count; i++)
           {
               if (!candidates[i].eliminated)
               {
                   printf("%s\n", candidates[i].name);
               }
           }
           break;
       }
       
       
       eliminate(min);
       
       
       for (int i = 0; i < candidate_count; i++)
       {
           candidates[i].votes = 0;
       }
    }
    return 0;
}

int get_index(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(candidates[i].name, name) == 0)
            return i;
    return -1;
}


bool vote(int voter, int rank, string name)
{
    
    int index = get_index(name);
    if (index != -1)
    {
        preferences[voter][rank] = index;
        return true;
    }
    return false;
}


void tabulate(void)
{
    
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }    
        }
    }
}


bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}


int find_min(void)
{
    
    int min = 0;
    bool have_found_first = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (!have_found_first)
            {
                min = candidates[i].votes;
                have_found_first = true;
            }
            else if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }
    return min;
}


bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
            if (candidates[i].votes != min)
                return false;
    }
    return true;
}


void eliminate(int min)
{
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes == min)
                candidates[i].eliminated = true;
        }
    }
    
}
