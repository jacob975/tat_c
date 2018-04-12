#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include"key.h"

int main()
{
    // initialize variables and constants
    int test_segid;
    char* shared_memory;
    struct shmid_ds shmbuffer;          // [struct type] [ struct name] [ variable name]
    int segment_size;
    const int shared_segment_size = 0x6400;

    /* Reattach the shared memory segment, at a different address. */
    test_segid = shmget (TEST_KEY, shared_segment_size,
                        S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    shared_memory = (char*) shmat(test_segid, (void*) 0x5000000, 0);
    printf("shared memory reattached at address %p\n", shared_memory);
    /* Prin out the string from shared memory. */
    printf ("%s\n", shared_memory);
    /* Detach the shared memory segment. */
    shmdt(shared_memory);

    /* Deallocate the shared memory segment. */
    shmctl(test_segid, IPC_RMID, 0);

    return 0;
}
