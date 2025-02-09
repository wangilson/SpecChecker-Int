/*
 * racebench2.1_remarks
 * Filename:svp_simple_017_001
 * Template File:svp_simple_017
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_017_001_main
 * 中断入口:svp_simple_017_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 100
#define TRIGGER 50

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_017_001_isr_1() {
  idlerun();

  svp_simple_017_001_global_var = TRIGGER;

  svp_simple_017_001_local_array[TRIGGER] = 0;
}
//
//
//
//
//
//
//
//

//
//
//

//
//
//
//

// CHECK-DAG: Data_Access_Conflict : svp_simple_017_001_global_var, 29-39-29
// CHECK-DAG: Data_Access_Conflict : svp_simple_017_001_global_var, 29-39-32
// CHECK-DAG: Data_Access_Conflict : svp_simple_017_001_global_var, 32-39-30
// CHECK-DAG: Data_Access_Conflict : svp_simple_017_001_global_var, 30-39-29
// CHECK-DAG: Data_Access_Conflict : svp_simple_017_001_global_var, 30-39-30
// CHECK-DAG: detected bugs = 5
// CHECK-DAG: detected Data_Access_Conflict bugs = 5