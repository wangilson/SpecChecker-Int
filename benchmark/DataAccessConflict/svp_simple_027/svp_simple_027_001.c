/*
 * racebench2.1_remarks
 * Filename:svp_simple_027_001
 * Template File:svp_simple_027
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_027_001_main
 * 中断入口:svp_simple_027_001_isr_1，svp_simple_027_001_isr_2，svp_simple_027_001_isr_3
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"

void svp_simple_027_001_init();

volatile int svp_simple_027_001_gloable_var;
void svp_simple_027_001_main() {
  disable_isr(-1);
  svp_simple_027_001_init();

  enable_isr(1);
  if (svp_simple_027_001_gloable_var > 12) {  
    svp_simple_027_001_gloable_var = 0;       
  }

  return ;
}

void svp_simple_027_001_init() {
  svp_simple_027_001_gloable_var = rand();

  init();
}

void svp_simple_027_001_isr_1() {
  svp_simple_027_001_gloable_var++;  
  enable_isr(2);
}
void svp_simple_027_001_isr_2() {
  svp_simple_027_001_gloable_var += 2;  
}
void svp_simple_027_001_isr_3() {
  svp_simple_027_001_gloable_var += 3;  
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

// CHECK-DAG: 41-45-41
// CHECK-DAG: 41-48-41
// CHECK-DAG: 45-48-45
// CHECK-DAG: 27-41-28
// CHECK-DAG: 27-45-28
// CHECK-DAG: detected bugs = 5
// CHECK-DAG: detected Data_Access_Conflict bugs = 5