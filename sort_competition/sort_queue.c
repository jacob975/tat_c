#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define LENGTH  1000

int init_array(int* array);
int print_array(int* array);
int swap(int* a, int* b);
int binary_sort(int* array, int ini, int fin);
int bubble_sort(int* array, int len);
int select_sort(int* array, int len);
void* binary_sort_run(void* array);
void* bubble_sort_run(void* array);
void* select_sort_run(void* array);

int main()
{
    // initialize variables
    int i, failure;
    int array_1[LENGTH], array_2[LENGTH], array_3[LENGTH];
    struct timeval tval_before, tval_after, tval_result;
    srand(time(NULL));   // should only be called once
    
    //initialize timer
    gettimeofday(&tval_before, NULL);
    
    // initialize lists
    init_array(array_1);
    init_array(array_2);
    init_array(array_3);
    // sort queue
    bubble_sort_run(array_1);
    select_sort_run(array_2);
    binary_sort_run(array_3);
    
    // check timer
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    return 0;
}

int init_array(int* array)
{
    int i = 0;
    for (i;i<LENGTH;i++)
    {
        array[i] = rand();
    }
    return 0;
}

int print_array(int* array)
{
    int i = 0;
    for (i;i<LENGTH;i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
    return 0;
}

int swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
    return 0;
}

int binary_sort(int* inp, int ini, int fin)
{
    //printf("init: %d, final: %d\n", ini, fin);
    //end point
    if (fin - ini <= 2)          return 0;
    // initialize variables
    int i, count = 0, mid;
    for(i=ini ;i<fin;i++)
    {
        // if smaller than reference value, swap to front list.
        if (inp[i] < inp[fin-1])
        {
            swap(&inp[i], &inp[ini+count]);
            count++;
        }
    }
    mid = ini + count;
    swap(&inp[mid], &inp[fin-1]);
    // print array
    //iteration
    binary_sort(inp, ini, mid);
    binary_sort(inp, mid, fin);
    return 0;
}

int bubble_sort(int* inp, int len)
{
    // initialize variables
    int i, j;
    for (i=0;i < len-1;i++)
    {
        for (j=0;j < len-i-1;j++)
        {
            if (inp[j] > inp[j+1])
            {
                swap(&inp[j], &inp[j+1]);
            }
        }
    }
    return 0;
}

int select_sort(int* inp, int len)
{
    // initialize the variables
    int i, j, miniindex;
    for (i = 0; i < len-1; i++)
    {
        miniindex = i;
        for (j = i+1; j < len; j++)
        {
            if (inp[j] < inp[miniindex])
                miniindex = j;
        }
        if (miniindex != i)
            swap(&inp[i], &inp[miniindex]);
    }
    return 0;
}

void* binary_sort_run(void* array)
{
    //initialize variables
    struct timeval tval_before, tval_after, tval_result;
    int *arr_ptr = (int *) array;
    gettimeofday(&tval_before, NULL);
    binary_sort(arr_ptr, 0, LENGTH);
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Binary sort: Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    //print_array(arr_ptr);
    return NULL;
}
void* bubble_sort_run(void* array)
{
    //initialize variables
    struct timeval tval_before, tval_after, tval_result;
    int *arr_ptr = (int *) array;
    gettimeofday(&tval_before, NULL);
    bubble_sort(arr_ptr, LENGTH);
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Bubble sort: Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    //print_array(arr_ptr);
    return NULL;
}
void* select_sort_run(void* array)
{
    //initialize variables
    struct timeval tval_before, tval_after, tval_result;
    int *arr_ptr = (int *) array;
    gettimeofday(&tval_before, NULL);
    select_sort(arr_ptr, LENGTH);
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("Select sort: Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    //print_array(arr_ptr);
    return NULL;
}
