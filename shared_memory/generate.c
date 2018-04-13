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

    /* Allocate a shared memory segment. */
    test_segid = shmget (TEST_KEY, shared_segment_size, 
                        IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    /* Attach the shared meory segment.*/
    shared_memory = (char*) shmat (test_segid, 0, 0);
    printf("shared memory attached at address %p\n", shared_memory);
    /* Show the segment's size. */
    shmctl (test_segid, IPC_STAT, &shmbuffer);
    segment_size = shmbuffer.shm_segsz;
    printf("segment size:%d\n", segment_size);
    /* Write a string to the shared memory segment. */
    sprintf(shared_memory, "Hello, world.");
    /* Detach the shared memory segment. */
    shmdt(shared_memory);
    return 0;
}
