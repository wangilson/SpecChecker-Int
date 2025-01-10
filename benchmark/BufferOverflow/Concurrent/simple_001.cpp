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
int simple_001_global_array[BUFFER_SIZE];
unsigned int simple_001_global_var;
extern unsigned int rand();
void simple_001_Init();

void simple_001_main(){
  simple_001_Init();
  if(simple_001_global_var < BUFFER_SIZE){
    simple_001_global_array[simple_001_global_var] = 0; //bug
  }
}

void simple_001_Init(){
  simple_001_global_var = rand();
}

void simple_001_isr() {
  simple_001_global_var = 0;              //
  simple_001_global_var = BUFFER_SIZE + 1;
}

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_001_global_array, 22
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1