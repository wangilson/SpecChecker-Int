/*
 * racebench2.1_remarks
 * Filename:svp_simple_032_001
 * Template File:svp_simple_032
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_032_001_main
 * 中断入口:svp_simple_032_001_isr_1,svp_simple_032_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 * 1.全局变量的访问处在多层循环内
 * 2.单个寄存器对特定中断的开关：EX0->svp_simple_032_001_isr_1;EX1->svp_simple_032_001_isr_2.
 *
 */

#include "../common.h"

//
//
//
//

#define BUFFER_SIZE 10
#define POWER_Ah 18
typedef unsigned int uint;
uint powerA = 0;
uint fgExecute = 1;
uint EA;
uint EX0;// svp_simple_032_001_isr_1
uint EX1;// svp_simple_032_001_isr_2
void svp_simple_032_001_Update();

void svp_simple_032_001_main(){
  while(1){
    svp_simple_032_001_Update();
  }
}

void svp_simple_032_001_Update() {
  for (uint i = 0; i < BUFFER_SIZE; i++) {
    for (uint j = 0; j < BUFFER_SIZE; j++) {
      if (i + j == POWER_Ah) {
        EX0 = 0;
        powerA = powerA + 5;
        EX0 = 1;
      }
    }
  }
  for (uint i = 0; i < BUFFER_SIZE; i++) {
    for (uint j = 0; j < BUFFER_SIZE; j++) {
      if (fgExecute == 1) {
        EX1 = 0;
        powerA = powerA + 5;
        EX1 = 1;
      }
    }
  }
}

void svp_simple_032_001_isr_1() {
  if (fgExecute == 1) {
    powerA = 30;
    fgExecute = 0;
  } else {
    powerA = 0;
  }
}

void svp_simple_032_001_isr_2() {
  if (fgExecute == 0) {
    powerA = 50;
    fgExecute = 1;
  } else {
    powerA = 0;
  }
}

// 这个访问冲突需要考虑中断间的副作用
// CHECK-NOT: Data_Access_Conflict : powerA, 45-72-45
// CHECK-DAG: Data_Access_Conflict : powerA, 45-75-45
// CHECK-DAG: Data_Access_Conflict : powerA, 54-63-54
// 不属于一个原子区
// CHECK-DAG: 45-75-54
// CHECK-DAG: 45-63-54