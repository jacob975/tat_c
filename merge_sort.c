#include <stdio.h>
#include <stdlib.h>
int quick_sort(int* inp, int* follower, int ini, int fin);
int swap(int* a, int* b);

int main(int argc, char* argv[] )
{
    // check arguments
    if (argc != 3)      printf("### Usage: %s inp follower", argv[0]);
    // initialize variables
    int inp[65535], follower[65535], f_length;
    FILE *fp;
    char outp_name[255];
    // load data
    fp = fopen(argv[1], "r");
    int i = 0;
    while(fscanf(fp, "%d", &inp[i]) != EOF)
    {
        i++;
    }
    f_length = i;
    fclose(fp);
    // load follower
    fp = fopen(argv[2], "r");
    i = 0;
    while(fscanf(fp, "%d", &follower[i])  != EOF)
    {
        i++;
    }
    fclose(fp);
    // quick sort
    quick_sort(inp, follower, 0, f_length);
    int j;
    for(j = 0; j < f_length; j++)
    {
        printf("%d, ", inp[j]);
    }
    printf("\n");
    // save result
    fp = fopen("result.txt", "w");
    i = 0;
    for (;i<f_length;i++)
    {
        fprintf(fp, "%d\t%d\n", inp[i], follower[i]);
    }
    return 0;
}
// swap two element
int swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
    return 0;
}

int quick_sort(int* inp, int* follower, int ini, int fin)
{
    printf("init: %d, final: %d\n", ini, fin);
    //end point
    if (fin - ini <= 2)          return 0;
    // initialize variables
    int i, count = 0, mid, ref = inp[fin-1];
    for(i=ini ;i<fin-1;i++)
    {
        // if smaller than reference value, swap to front list.
        if (inp[i] < ref)
        {
            swap(&inp[i], &inp[ini+count]);
            swap(&follower[i], &follower[ini+count]);
            count++;
        }
    }
    mid = ini + count;
    swap(&inp[mid], &inp[fin-1]);
    swap(&follower[mid], &follower[fin-1]);
    // print array
    int j;
    for(j = ini; j < fin; j++) 
    {
        printf("%d, ", inp[j]);
    }
    printf("\n");
    for(j = ini; j < fin; j++) 
    {
        printf("%d, ", follower[j]);
    }
    printf("\n");
    //iteration
    quick_sort(inp, follower, ini, mid);
    quick_sort(inp, follower, mid, fin);
    return 0;
}
