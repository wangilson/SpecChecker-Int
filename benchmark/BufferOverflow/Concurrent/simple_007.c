//
// Created by root on 2027/5/24.
//
//
// 中断的副作用影响了路径条件导致数组越界
//

// RUN: %clang -S -c -O -g -emit-llvm -fno-discard-value-names -Xclang -disable-llvm-passes -Xclang -disable-O0-optnone %s -o %t.bc
// RUN: %opt -loops -lcssa -loop-unroll -unroll-count=2 -S -debugify %t.bc -o %t.ll
// RUN: %intAtomPlus -stat=false -int-data-access-conflict=false -int-bof=true -int-dbz=false %t.ll -tasks=simple_007_main,simple_007_isr_1,simple_007_isr_2 -priority=0,1,2 -reportFile=%t.json > %t.txt
// RUN: %FileCheck -input-file=%t.txt %s

#define BUFFER_SIZE 10
typedef unsigned int uint;
typedef unsigned char uchar;
int simple_007_global_array[BUFFER_SIZE];
uchar simple_007_global_flag = 0;
uint simple_007_global_var = 0;

void simple_007_Init();

unsigned int simple_007_Adjust(unsigned int index);

void simple_007_main() {
    unsigned int index1 = 0;

    simple_007_Init();
    while (index1 < BUFFER_SIZE - 1) {
        index1++;
    }
    index1 = simple_007_Adjust(index1);
    simple_007_global_array[index1] = 0;// 预埋误报
}

void simple_007_Init() {
    simple_007_global_flag = 0;
    simple_007_global_var = 0;
}

unsigned int simple_007_Adjust(unsigned int index) {
    index += simple_007_global_var;
    return index;
}
void simple_007_isr_1(){
    unsigned int index2 = 0;
    unsigned int top = 0;
    if(simple_007_global_var == 1){
        top = BUFFER_SIZE;
    }else{
        top = BUFFER_SIZE - 1;
    }
    while (index2 < top) {
        index2++;
    }
    simple_007_global_array[index2] = 0; // 并发缺陷，当isr2在47行之前发生抢占时，会导致数组越界
}

void simple_007_isr_2() {
    if (simple_007_global_flag != 0) {
        simple_007_global_var = 1;
    } else {
        simple_007_global_var = 0;
    }
}

//误报
// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_007_global_array, 32
// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_007_global_array, 55
// CHECK-DAG: done: detected bugs = 2
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 2
