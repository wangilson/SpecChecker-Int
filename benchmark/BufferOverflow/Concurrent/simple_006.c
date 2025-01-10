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
int simple_006_global_array[BUFFER_SIZE];
uchar simple_006_global_flag = 1;
uint simple_006_global_var1;
uint simple_006_global_var2;
extern uint rand();
void simple_006_Init();


void simple_006_main() {
    unsigned int index1, index2;
    simple_006_Init();
    if (simple_006_global_var1 < BUFFER_SIZE) {
        index1 = simple_006_global_var1;
    } else {
        index1 = 0;
    }
    if (simple_006_global_var2 < BUFFER_SIZE) {
        index2 = simple_006_global_var2;
    } else {
        index2 = 0;
    }
    simple_006_global_array[index1] = 0;// bug
    simple_006_global_array[index2] = 0;
}

void simple_006_Init() {
    simple_006_global_var1 = rand();
    simple_006_global_var2 = rand();
    simple_006_global_flag = 0;
}

void simple_006_isr() {
    if (simple_006_global_flag != 0) {
        simple_006_global_var2++;
    }else{
        simple_006_global_var1++;
    }
}

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : simple_006_global_array, 37
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1
