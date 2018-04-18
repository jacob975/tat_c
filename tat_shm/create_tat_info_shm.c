#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "tat_info.h"

// create tat_info_shm.

int main()
{
    // initialize variable
    int tat_info_id;
    st_tat_info tat_info_shm = {0}, *tat_info_ptr;
    // allocate shm
    tat_info_id = shmget (KEY_TAT_INFO, sizeof(st_tat_info),
                            IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    printf("size of st_tat_info: %d\n", sizeof(st_tat_info));
    printf("size of int: %d\n", sizeof(tat_info_id));
    printf("allocate OK\n");
    // attach
    tat_info_ptr = (st_tat_info *) shmat(tat_info_id, 0, 0);
    printf("attach OK\n");
    tat_info_ptr = &tat_info_shm;
    printf("assign value OK\n");
    //print tat_info shm
    disp_dsp_info(&tat_info_ptr->dsp_info);
    disp_ccd_info(&tat_info_ptr->ccd_info);
    disp_ppc_info(&tat_info_ptr->ppc_info);
    disp_pwr_info(&tat_info_ptr->pwr_info);
    disp_ctl_info(&tat_info_ptr->ctl_info);
    disp_obs_info(&tat_info_ptr->obs_info);
    printf("reading OK\n");
    // deattach
    //shmdt(tat_info_ptr);
    return 0;
}
