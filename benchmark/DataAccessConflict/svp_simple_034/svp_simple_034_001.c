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

typedef unsigned int uint;
typedef unsigned char uchar;
uint fgExecute;
uint svp_simple_034_001_global_var1;

void svp_simple_034_001_main() {
  while(1){
    ///
    ///
    if (fgExecute == 0x00) {
      svp_simple_034_001_global_var1 = 0;
    }
  }
}

void svp_simple_034_001_isr() {
  if (fgExecute >= 0x0a) {
    fgExecute = 0;
  } else {
    fgExecute++;
  }
}

// CHECK-DAG: Data_Access_Conflict : fgExecute, 22-32-22
// CHECK-DAG: detected Data_Access_Conflict bugs = 1