/*
 * racebench2.1_remarks
 * Filename:svp_simple_005_001
 * Template File:svp_simple_005
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_005_001_main
 * 中断入口:svp_simple_005_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

#define MAX_LENGTH 10000
#define TRIGGER 9999
#define TRIGGER1 1000

volatile int svp_simple_005_001_global_condition = 0;

volatile int svp_simple_005_001_global_var;

void svp_simple_005_001_main() {
  init();
  for (int i = 0; i < MAX_LENGTH; i++) {
    for (int j = 0; j < MAX_LENGTH; j++) {
      if ((i == TRIGGER) && (j == TRIGGER1))
        svp_simple_005_001_global_var = 0x01;
    }
  }

  if (svp_simple_005_001_global_condition ==
      1)
    svp_simple_005_001_global_var = 0x09;

  svp_simple_005_001_global_var = 0x05;
}

void svp_simple_005_001_isr_1() {
  idlerun();
  int reader;
  reader = svp_simple_005_001_global_var;
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


// CHECK-DAG: Data_Access_Conflict : svp_simple_005_001_global_var, 32-46-40
// CHECK-DAG: detected bugs = 1