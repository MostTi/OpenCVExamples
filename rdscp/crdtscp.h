#ifndef CRDTSCP
#define CRDTSCP

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//#define RDTSCPNUMMEAS 100 //for data: number of measurements (now via fn argument)
#define RDTSCPCORDUMMY 3 //for corr data: number of dummy measurements (to be ignored)
#define RDTSCPCORNUMMEAS 4 //for corr data: number of measurements 

struct rdtscp_data{ 
   int nummeas;  
   double sum;
   double sum2;
   double min;
   double max;
   double avg;   
   double stdev;   

   uint64_t tcorrval;
   uint64_t* tstart;
   uint64_t* tend;
   uint64_t* tdiff;

};


/** TODO shortdecription 
* @return TODO shortdecription
*/
#define rdtscp() ({ \
  uint32_t lo, hi; \
  uint64_t result; \
  __asm__ __volatile__ ( \
     "rdtscp" \
   : "=a"(lo), "=d"(hi) \
   : "a"(0) \
   : "%ebx", "%ecx" \
  ); \
  result=((uint64_t)lo) | (((uint64_t)hi) << 32);\
  result; })
/*
static inline int64_t rdtscp() {
  uint32_t lo, hi;
  __asm__ __volatile__ (
     "rdtscp"
   : "=a"(lo), "=d"(hi) //outputs 
   : "a"(0)             // inputs 
   : "%ebx"             //overwrites  
  );
  return ((uint64_t)lo) | (((uint64_t)hi) << 32);  
}
*/


/** allocates and inits the main data structure 
* @param the main data structure.
* @param the number of measurements.
* @return nothing
*/
void rdtscp_init(struct rdtscp_data* pd, int nummeas);

/** TODO shortdecription
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_init_corr(struct rdtscp_data* pd);

/** TODO shortdecription 
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_free(struct rdtscp_data* pd);



/** TODO shortdecription
* TODO shortdecription
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_eval(struct rdtscp_data* pd);

/** TODO shortdecription
* TODO shortdecription
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_eval_wcorr(struct rdtscp_data* pd);

/** TODO shortdecription
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_calc_helper(struct rdtscp_data* pd);

/** TODO shortdecription
* @param TODO shortdecription
* @param TODO shortdecription
* @return TODO shortdecription
*/
void rdtscp_print(struct rdtscp_data* pd, const char* name);


#endif 


