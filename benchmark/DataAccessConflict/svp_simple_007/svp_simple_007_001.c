/*
 * racebench2.1_remarks
 * Filename:svp_simple_007_001
 * Template File:svp_simple_007
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_007_001_main
 * 中断入口:svp_simple_007_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999

volatile int svp_simple_007_001_global_var;

volatile int svp_simple_007_001_global_array[5];

void svp_simple_007_001_main() {
  init();
  int reader1, reader2;

  

  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x01;

  reader2 = svp_simple_007_001_global_array[svp_simple_007_001_global_var];

  int i = rand();
  if (i == 2)
    svp_simple_007_001_global_array[i] = 0x02;
  else
    svp_simple_007_001_global_array[i] = 0x09;

  reader1 = svp_simple_007_001_global_array[2];
}

void svp_simple_007_001_isr_1() {
  idlerun();
  svp_simple_007_001_global_array[2] = 0x09;

  svp_simple_007_001_global_var += 1;
  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x09;
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

// CHECK-DAG: Data_Access_Conflict : svp_simple_007_001_global_var, 32-49-34
// CHECK-DAG: Data_Access_Conflict : svp_simple_007_001_global_array, 38-47-42
// CHECK-DAG: detected Data_Access_Conflict bugs = 2