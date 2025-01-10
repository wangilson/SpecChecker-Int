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

#define BUFFER_SIZE 10
typedef unsigned int uint;
int simple_004_global_array[BUFFER_SIZE];

void simple_004_main() {
  for (uint i = 0; i < BUFFER_SIZE; i++) {
    if (simple_004_global_array[i] == 0) {
      return;
    }
  }
}

void simple_004_isr(){
  for (uint i = 0; i < BUFFER_SIZE; i++) {
    simple_004_global_array[i] = 0;
  }
}

// CHECK-DAG: detected bugs = 0
