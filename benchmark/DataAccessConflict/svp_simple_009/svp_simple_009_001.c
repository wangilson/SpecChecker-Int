/*
 * racebench2.1_remarks
 * Filename:svp_simple_009_001
 * Template File:svp_simple_009
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_009_001_main
 * 中断入口:svp_simple_009_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int *svp_simple_009_001_p;
volatile int *svp_simple_009_001_q;

volatile int *svp_simple_009_001_m;

void svp_simple_009_001_main() {
  init();
  int svp_simple_009_001_local_var1 = 0x01;
  int svp_simple_009_001_local_var2 = 0x09;

  svp_simple_009_001_p = &svp_simple_009_001_local_var1;
  svp_simple_009_001_q = &svp_simple_009_001_local_var1;

  *svp_simple_009_001_p = 0x02;
  *svp_simple_009_001_q = 0x03;

  svp_simple_009_001_m = &svp_simple_009_001_local_var2;

  *svp_simple_009_001_m = 0x06;
  *svp_simple_009_001_m = 0x06;
}

void svp_simple_009_001_isr_1() {
  int reader1, reader2;
  idlerun();
  reader1 = *svp_simple_009_001_p;
  int svp_simple_009_001_local_var3 = 0x08;
  svp_simple_009_001_m = &svp_simple_009_001_local_var3;
  reader2 = *svp_simple_009_001_m;
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

// CHECK-DAG: Data_Access_Conflict : svp_simple_009_001_m, 37-46-38
// false negative
// Data_Access_Conflict : svp_simple_009_001_local_var1, 32-44-33
// CHECK-DAG: Data_Access_Conflict : svp_simple_009_001_m, 35-46-37
// CHECK-DAG: detected bugs = 2
// CHECK-DAG: detected Data_Access_Conflict bugs = 2