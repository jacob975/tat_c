#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include"key.h"

int main(int argc, char **argv[])
{
    // initialize variables and constants
    int test_segid;
    char* shared_memory;
    const int shared_segment_size = 0x6400;
    
    // check arguments
    
    if (argc != 2)
    {
        printf("Usage: %s [remain or kill the shm]\n", argv[0]);
        return 1;
    }

    /* Reallocate the shared memory */
    test_segid = shmget (TEST_KEY, shared_segment_size,
                        S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    // Reattach shared memory
    shared_memory = (char*) shmat(test_segid, 0, 0);
    printf("shared memory reattached at address %p\n", shared_memory);
    /* Prin out the string from shared memory. */
    printf ("before:\t%s\n", shared_memory);
    sprintf(shared_memory, "%s %s", shared_memory, "XD");
    printf ("after:\t%s\n", shared_memory);
    
    if (!strcmp(argv[1], "kill"))
    {
        /* Detach the shared memory segment. */
        shmdt(shared_memory);
        /* Deallocate the shared memory segment. */
        shmctl(test_segid, IPC_RMID, 0);
        printf("Shared memory is killed\n");
    }
    else
        printf("Shared memory is remained\n");
    
    return 0;
}
