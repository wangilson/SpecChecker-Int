//
// 考察函数返回值和副作用的影响导致数组越界
//

// RUN: %clang -S -c -O -g -emit-llvm -fno-discard-value-names -Xclang -disable-llvm-passes -Xclang -disable-O0-optnone %s -o %t.bc
// RUN: %opt -loops -lcssa -loop-unroll -unroll-count=3 -S -debugify %t.bc -o %t.ll
// RUN: %intAtomPlus -stat=false -int-data-access-conflict=false -bof=true -int-dbz=false %t.ll -tasks=simple_001_main -priority=0 -reportFile=%t.json > %t.txt
// RUN: %FileCheck -input-file=%t.txt %s

#define BUFFER_SIZE 10
int simple_001_global_array[BUFFER_SIZE];
unsigned int simple_001_getIndex();
void simple_001_setIndex(unsigned int &index);

void simple_001_main(){
  unsigned int local_size = simple_001_getIndex();
  if(simple_001_global_array[local_size] > 1){
    simple_001_global_array[local_size] = 0;
  }
  local_size = BUFFER_SIZE;
  simple_001_setIndex(local_size);
  simple_001_global_array[local_size] = 0;
}

unsigned int simple_001_getIndex(){
  return BUFFER_SIZE + 1;
}

void simple_001_setIndex(unsigned int &index) { index = index + 1; }

// CHECK-DAG: Buffer_Overflow : simple_001_global_array, 17
// CHECK-DAG: Buffer_Overflow : simple_001_global_array, 18
// CHECK-DAG: Buffer_Overflow : simple_001_global_array, 22
// CHECK-DAG: detected bugs = 3
// CHECK-DAG: detected Buffer_Overflow bugs = 3