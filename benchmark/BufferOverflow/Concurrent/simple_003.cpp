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
typedef unsigned char uchar;
int simple_003_global_array[BUFFER_SIZE];
uchar simple_003_global_flag = 0;
uint simple_003_global_var1;
uint simple_003_global_var2;
extern uint rand();
void simple_003_Init();
void simple_003_Adjust();

void simple_003_main() {
  simple_003_Init();



  simple_003_Adjust();
  simple_003_global_array[simple_003_global_var1] = 0;// bug
  simple_003_global_array[simple_003_global_var2] = 0;//


}

void simple_003_Init() {
  simple_003_global_flag = 0;
  simple_003_global_var1 = 0;
  simple_003_global_var2 = 0;
}

void simple_003_Adjust(){
  if(simple_003_global_flag){
    simple_003_global_var1 = rand();
    simple_003_global_flag = 0;
  }else{
    simple_003_global_var1 = rand() % 10;
  }
}

void simple_003_isr() {
  if(simple_003_global_flag){
    simple_003_global_flag = 0;
  }else{
    simple_003_global_flag = 1;
  }
}

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_003_global_array, 30
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1
