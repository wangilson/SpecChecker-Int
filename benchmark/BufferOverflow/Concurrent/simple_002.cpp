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
int simple_002_global_array[BUFFER_SIZE];
uint simple_002_global_var1;
uint simple_002_global_var2;
extern uint rand();
void simple_002_Init();

void simple_002_main() {
  simple_002_Init();
  if (simple_002_global_var1 < BUFFER_SIZE &&
      simple_002_global_var2 < BUFFER_SIZE) {
    simple_002_global_array[simple_002_global_var1] = 0; //
    simple_002_global_array[simple_002_global_var2] = 0; // bug
  }
}

void simple_002_Init() {
  simple_002_global_var1 = 0;
  simple_002_global_var2 = 0;
}

void simple_002_isr() {
  for (uint i = 0; i < BUFFER_SIZE; i++) {
    simple_002_global_var1 = 0;
    simple_002_global_var2 = rand();
    //
  }
}

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_002_global_array, 26
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1
