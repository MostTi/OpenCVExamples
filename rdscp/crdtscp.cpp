#include "crdtscp.h"

void rdtscp_init(struct rdtscp_data* pd, int nummeas)
{
   pd->sum=0;  pd->sum2=0;  pd->min=-1;  pd->max=0;
   pd->avg=0;  pd->stdev=0; 
   pd->nummeas=nummeas;
   pd->tcorrval=0;            

   pd->tstart= (uint64_t*) malloc(pd->nummeas* sizeof(uint64_t));   
   if (pd->tstart==0)
   {
    printf("RDTSCP: %s line %d: malloc error -> ... exit\n", __FILE__, __LINE__);
    exit(1);  
   }  
   pd->tend= (uint64_t*) malloc(pd->nummeas* sizeof(uint64_t));   
   if (pd->tend==0)
   {
    printf("RDTSCP: %s line %d: malloc error -> ... exit\n", __FILE__, __LINE__);
    exit(1);  
   }
   pd->tdiff= (uint64_t*) malloc(pd->nummeas* sizeof(uint64_t));   
   if (pd->tdiff==0)
   {
    printf("RDTSCP: %s line %d: malloc error -> ... exit\n", __FILE__, __LINE__);
    exit(1);  
   }  
}

void rdtscp_free(struct rdtscp_data* pd)
{
  free(pd->tstart);
  free(pd->tend);
  free(pd->tdiff);
}

void rdtscp_calc_helper(struct rdtscp_data* pd)
{
   for (int i = 0; i < pd->nummeas; ++i) {
     pd->sum    += pd->tdiff[i];
     pd->sum2   += (pd->tdiff[i] * pd->tdiff[i]);
     if (pd->tdiff[i] > pd->max) pd->max = pd->tdiff[i];
     if ((pd->min == -1) || (pd->tdiff[i] < pd->min)) pd->min = pd->tdiff[i];
   }
   pd->avg = pd->sum / pd->nummeas;
   //stddev = sqrt(N*s2 -s^2)/N^2
   pd->stdev =  sqrt((pd->nummeas  * pd->sum2 - (pd->sum * pd->sum)) / (pd->nummeas * pd->nummeas));
}

void rdtscp_eval(struct rdtscp_data* pd)
{
   for (int i = 0; i < pd->nummeas; ++i) {
     pd->tdiff[i] = pd->tend[i] - pd->tstart[i];
   }

   rdtscp_calc_helper(pd);
}


void rdtscp_print(struct rdtscp_data* pd, const char* name)
{
  printf("%-8s %-8s %-8s %-8s %-8s %-8s\n","Meas", "samples", "min", "max", "avg", "stdev");  
  printf("%-8s %-8.2d %-8.2e %-8.2e %-8.2e %-8.2e\n", name, pd->nummeas, pd->min, pd->max, pd->avg, pd->stdev);
}



void rdtscp_init_corr(struct rdtscp_data* pd)
{
  struct rdtscp_data corrdata; 
  rdtscp_init(&corrdata, RDTSCPCORNUMMEAS);

  for (int i = 0; i < RDTSCPCORDUMMY; ++i) {  
    rdtscp(); //dummy calls to warm up
  }

  for (int i = 0; i < corrdata.nummeas; ++i) {
    corrdata.tstart[i] = rdtscp();    
    corrdata.tend[i] = rdtscp();
  }
  
  rdtscp_eval(&corrdata);
  pd->tcorrval=corrdata.avg; 

  rdtscp_print(&corrdata, "CORRDATA");

  rdtscp_free(&corrdata);
}


void rdtscp_eval_wcorr(struct rdtscp_data* pd)
{
   for (int i = 0; i < pd->nummeas; ++i) {
     pd->tdiff[i] = pd->tend[i] - pd->tstart[i]; 
     if (pd->tdiff[i] < pd->tcorrval) //should not happen!
       pd->tdiff[i]=0;
     else
       pd->tdiff[i] - pd->tcorrval;
   }

   rdtscp_calc_helper(pd);
}
