#include <stdio.h>
#include <stdlib.h>
#include "tat_info.h"

void disp_dsp_info( st_dsp_info* dsp_info)
{
    printf("#####################\n");
    printf("dsp_info: \n");
    printf("int\ttime_count: %d\n", dsp_info->time_count);
    printf("ra: \n");
    disp_tel_info(&dsp_info->ra);
    printf("dec: \n");
    disp_tel_info(&dsp_info->dec);
    printf("rot: \n");
    disp_mx_info(&dsp_info->rot);
    printf("tran: \n");
    disp_mx_info(&dsp_info->tran);
    printf("wheel: \n");
    disp_mx_info(&dsp_info->wheel);
    printf("enc: \n");
    disp_enc_info(&dsp_info->enc);
    printf("latch: \n");
    disp_latch_info(&dsp_info->latch);
    return;
}

void disp_tel_info( st_tel_info* tel_info)
{
    printf("\tint\treg: %d\n", tel_info->reg);
    printf("\tint\tpulse: %d\n", tel_info->pulse);
    printf("\tchar\tdir: %c\n", tel_info->dir);
    printf("\tchar\tstatus: %c\n", tel_info->status);
    printf("\tchar\tpulsectl: %c\n", tel_info->pulsectl);
    printf("\tint\trefpulse: %d\n", tel_info->refpulse);
    printf("\tint\tpurpulse: %d\n", tel_info->purpulse);
    printf("\tchar\torigin: %c\n", tel_info->origin);
    return;
}
void disp_mx_info( st_mx_info* mx_info)
{
    printf("\tint\tmove: %d\n", mx_info->move);
    printf("\tchar\tmode: %c\n", mx_info->mode);
    return;
}
void disp_enc_info( st_enc_info* enc_info)
{
    printf("\tchar\topen: %c\n", enc_info->open);
    printf("\tchar\tclose: %c\n", enc_info->close);
    printf("\tchar\ttime: %c\n", enc_info->time);
    return;
}
void disp_latch_info( st_latch_info* latch_info)
{
    printf("\tchar\tlock: %c\n", latch_info->lock);
    printf("\tchar\tunlock: %c\n", latch_info->unlock);
    printf("\tchar\ttime: %c\n", latch_info->time);
    return;
}

void disp_ccd_info( st_ccd_info* ccd_info)
{
    printf("#####################\n");
    printf("ccd_info:\n");
    
    printf("float\tcurr_point: %f\n", ccd_info->curr_point);
    printf("float\tset_point: %f\n", ccd_info->set_point);
    printf("int\tcamera_status: %d\n", ccd_info->camera_status);
    printf("int\tserver_connected: %d\n", ccd_info->server_connected);
    printf("int\tccd_locked: %d\n", ccd_info->ccd_locked);
    printf("int\tcooler_status: %d\n", ccd_info->cooler_status);
    printf("int\tcooler_mode: %d\n", ccd_info->cooler_mode);
    printf("int\tfan_status: %d\n", ccd_info->fan_status);
    printf("int\tpresent: %d\n", ccd_info->present);
    return;
}
void disp_ppc_info( st_ppc_info* ppc_info)
{
    printf("#####################\n");
    printf("ppc_info:\n");
    
    printf("char\tcontrol: %c\n", ppc_info->control);
    printf("char\tdata: %c\n", ppc_info->data);
    printf("char\tstatus: %c\n", ppc_info->status);
    return;
}
void disp_pwr_info( st_ppc_info* ppc_info)
{
    printf("#####################\n");
    printf("pwr_info:\n");
    
    printf("char\tcontrol: %c\n", ppc_info->control);
    printf("char\tdata: %c\n", ppc_info->data);
    printf("char\tstatus: %c\n", ppc_info->status);
    return;
}
void disp_ctl_info( st_ctl_info* ctl_info)
{
    printf("#####################\n");
    printf("ctl_info:\n");
    printf("int\tdspd: %d\n", ctl_info->dspd);
    printf("int\tccdd: %d\n", ctl_info->ccdd);
    printf("int\tppcd: %d\n", ctl_info->ppcd);
    printf("int\tpwrd: %d\n", ctl_info->pwrd);
    printf("int\tflid: %d\n", ctl_info->flid);
    printf("int\taobs: %d\n", ctl_info->aobs);
    return;
}
void disp_obs_info( st_obs_info* obs_info)
{
    printf("#####################\n");
    printf("obs_info:\n");
    printf("time_t: begin_time: %lld, end_time: %lld\n", obs_info->begin_time, obs_info->end_time);
    printf("int\tauto_observing: %d\n", obs_info->auto_observing);
    printf("char\tstatus: %c\n", obs_info->status);
    printf("float\tcurr_ra: %f\n", obs_info->curr_ra);
    printf("float\tcurr_dec: %f\n", obs_info->curr_dec);
    printf("float\tdest_ra: %f\n", obs_info->dest_ra);
    printf("float\tdest_dec: %f\n", obs_info->dest_dec);
    printf("char\tflat_start: %s\n", obs_info->flat_start);
    printf("int\tccd_status: %d\n", obs_info->ccd_status);
    printf("int\tcycle_time: %d\n", obs_info->cycle_time);
    printf("int\tcycle_number: %d\n", obs_info->cycle_number);
    printf("float\texpose_time: %f\n", obs_info->expose_time);
    printf("char\trecent_image: %s\n", obs_info->recent_image);
    printf("float\tRA: %f, DEC: %f\n", obs_info->RA, obs_info->DEC);
    printf("int\tFOV: %d, exp_time_changed: %d\n", obs_info->FOV, obs_info->exp_time_changed);
    printf("int\tN_filters: %d, current_filter: %d\n", obs_info->N_filters, obs_info->current_filter);
    int i=0;
    printf("int\tfilter_seq\tfilter_exp_time\tfilter_obs_time\n");
    for(i;i<6;i++)
    {
        printf("\t%d\t\t%d\t\t%d\n", obs_info->filter_seq[i], obs_info->filter_exp_time[i], obs_info->filter_obs_time[i]);
    }
    printf("char\tfilter_type: %c\n", obs_info->filter_type);
    return;
}

