/*
 * racebench2.1_remarks
 * Filename:svp_simple_025_001
 * Template File:svp_simple_025
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_025_001_main
 * 中断入口:svp_simple_025_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_025_001_global_var;
volatile int *svp_simple_025_001_global_array[100];
void svp_simple_025_001_func_1(int *array);
void svp_simple_025_001_init();

void svp_simple_025_001_main() {
  svp_simple_025_001_init();
  svp_simple_025_001_func_1(&svp_simple_025_001_global_var);
}
void svp_simple_025_001_init() {
  disable_isr(-1);
  svp_simple_025_001_global_var = rand();
  init();
  enable_isr(-1);
}
void svp_simple_025_001_func_1(int *ptr_var) {
  *ptr_var = *ptr_var + 1;  
}
void svp_simple_025_001_isr_1() {
  svp_simple_025_001_global_var = 0;  
}

//
//

//
//
//
//

// CHECK-DAG: Data_Access_Conflict : svp_simple_025_001_global_var, 35-38-35
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Data_Access_Conflict bugs = 1