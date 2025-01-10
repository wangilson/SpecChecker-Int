//
//
//
#define uchar unsigned char
#define uint unsigned int
uint open_count = 0;
uint close_count = 0;
uint simple_003_global_flag = 0;
int EA = 0;
extern uint rand();
int getOpenStep();
int getCloseStep();
struct S_CONTROL_PARA {
    uint X;
    uint Y;
    uint distance;
};
struct S_CONTROL_PARA globalCtr;
struct S_CONTROL_PARA *ctr = &globalCtr;
void simple_003_Init() {
    EA = 0;
    open_count = rand();
    close_count = rand();
    EA = 1;
}

void simple_003_main() {
    simple_003_Init();
    int diff = getOpenStep();
    ctr->X += ctr->distance / diff;
    EA = 0;
    diff = getCloseStep(); // 被中断开关保护
    ctr->X += ctr->distance / diff;
    EA = 1;
}
int getOpenStep() {
    int step = 0;
    if (open_count > close_count) {
        step = open_count;  // 在30-31之间发生抢占则可能导致除零错误
    } else {
        step = -1;
    }
    return step;
}

int getCloseStep() {
    int step = 0;
    if (open_count > close_count) {
        step = close_count;
    } else {
        step = -1;
    }
    return step;
}

void simple_003_isr() {
    if (simple_003_global_flag != 0) {
        open_count = 1;
        close_count = 0;
    } else {
        open_count = 0;
        close_count = 1;
    }
}


//
//
//
//

// CHECK-DAG: Interrupt-Aware Div_Zero : diff, 30
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Div_Zero bugs = 1

