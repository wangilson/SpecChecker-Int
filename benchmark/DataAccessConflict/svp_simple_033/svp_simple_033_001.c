//
// Created by root on 2027/5/24.
//
//
//
//

//
//
//
//
#include "../common.h"
typedef unsigned int uint;
typedef unsigned char uchar;
uchar svp_simple_033_001_fgExecute = 0;
uint svp_simple_033_001_powerA = 0;
uchar svp_simple_033_001_onoffnum;
uint svp_simple_033_001_global_var1;
uint svp_simple_033_001_global_var2;
void svp_simple_033_001_Init();
void svp_simple_033_001_Adjust();
void svp_simple_033_001_main() {
  svp_simple_033_001_Init();
  while(1){
    svp_simple_033_001_Adjust();
  }
}
void svp_simple_033_001_Init() {
  disable_isr(-1);
  svp_simple_033_001_global_var1 = 0;
  svp_simple_033_001_global_var2 = 0;
  svp_simple_033_001_onoffnum = rand();
  enable_isr(-1);
}
void svp_simple_033_001_Adjust(){
  if ((svp_simple_033_001_onoffnum > 0) && (svp_simple_033_001_fgExecute == 1)) {
    svp_simple_033_001_powerA = 0;
  } else if (svp_simple_033_001_fgExecute == 0) {
    svp_simple_033_001_powerA = 1;
  }
}

void svp_simple_033_001_isr() {
  svp_simple_033_001_fgExecute = 1;
}

// CHECK-DAG: Data_Access_Conflict : svp_simple_033_001_fgExecute, 36-44-38
// CHECK-DAG: Data_Access_Conflict : svp_simple_033_001_fgExecute, 38-44-38
// CHECK-DAG: Data_Access_Conflict : svp_simple_033_001_fgExecute, 36-44-36
//
// CHECK-DAG: Data_Access_Conflict : svp_simple_033_001_fgExecute, 38-44-36
// CHECK-DAG: detected bugs = 4
// CHECK-DAG: detected Data_Access_Conflict bugs = 4
