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
int EA = 1; // EA = 0 disable interrupt，EA = 1 enable interrupt
typedef unsigned int uint;
typedef unsigned char uchar;
int simple_008_global_array[BUFFER_SIZE];
uchar simple_008_global_flag = 1;
uint simple_008_global_var1 = 0;
uint simple_008_global_var2 = 0;

void simple_008_Init();
extern uint rand();

void simple_008_main() {
    unsigned int index1 = 0;
    unsigned int index2 = 0;
    simple_008_Init();
    EA = 0;
    if (simple_008_global_var1 < BUFFER_SIZE) {
        index1 = simple_008_global_var1;
    } else {
        index1 = 0;
    }
    EA = 1;
    simple_008_global_array[index1] = 0;//
    if (simple_008_global_var2 < BUFFER_SIZE) {
        index2 = simple_008_global_var2;
    } else {
        index2 = 0;
    }
    simple_008_global_array[index2] = 0;// bug
}

void simple_008_Init() {
    EA = 0;
    simple_008_global_var1 = rand();
    simple_008_global_var2 = rand();
    EA = 1;
}

void simple_008_isr() {
    simple_008_global_var1++;
    simple_008_global_var2++;
}


// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_008_global_array, 42
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1
