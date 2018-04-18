#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "tat_info.h"

// load tat_info from shm and print it out.

int main(int argc, char** argv)
{
    // check argument
    if (argc != 2)
    {
        printf("Error!\n");
        printf("Usage: %s [kill or remain]\n", argv[0]);
        return 1;
    }
    // initialize variable
    int tat_info_id;
    st_tat_info *tat_info_ptr;
    // allocate shm
    tat_info_id = shmget (KEY_TAT_INFO, sizeof(st_tat_info),
                            S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    printf("size of st_tat_info: %d\n", sizeof(st_tat_info));
    printf("size of int: %d\n", sizeof(tat_info_id));
    printf("allocate OK\n");
    // attach
    tat_info_ptr = (void *) shmat(tat_info_id, 0, 0);
    printf("attach OK\n");
    //print tat_info shm
    disp_dsp_info(&tat_info_ptr->dsp_info);
    disp_ccd_info(&tat_info_ptr->ccd_info);
    disp_ppc_info(&tat_info_ptr->ppc_info);
    disp_pwr_info(&tat_info_ptr->pwr_info);
    disp_ctl_info(&tat_info_ptr->ctl_info);
    disp_obs_info(&tat_info_ptr->obs_info);
    printf("reading OK\n");
    /* Detach the shared memory segment. */
    shmdt(tat_info_ptr);
    if (!strcmp(argv[1], "kill"))
    {
        /* Deallocate the shared memory segment. */
        shmctl(tat_info_id, IPC_RMID, 0);
        printf("Shared memory is killed\n");
    }
    else
        printf("Shared memory is remained\n");    
    return 0;
    
}
