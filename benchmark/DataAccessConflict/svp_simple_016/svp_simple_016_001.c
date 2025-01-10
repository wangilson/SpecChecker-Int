/*
 * racebench2.1_remarks
 * Filename:svp_simple_016_001
 * Template File:svp_simple_016
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_016_001_main
 * 中断入口:svp_simple_016_001_isr_1
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

volatile int svp_simple_016_001_global_var1;

void svp_simple_016_001_main() {
  init();
  int reader1;
  svp_simple_016_001_global_var1 = 0x01;
  reader1 = svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1;

}

void svp_simple_016_001_isr_1() {
  idlerun();
  svp_simple_016_001_global_var1 = 0x09;
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

// CHECK-DAG: Data_Access_Conflict : svp_simple_016_001_global_var1, 24-33-25
// CHECK-DAG: Data_Access_Conflict : svp_simple_016_001_global_var1, 25-33-26
// CHECK-DAG: Data_Access_Conflict : svp_simple_016_001_global_var1, 26-33-27
// CHECK-DAG: detected bugs = 3
// CHECK-DAG: detected Data_Access_Conflict bugs = 3