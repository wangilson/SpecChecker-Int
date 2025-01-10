
typedef unsigned char uchar;
typedef unsigned int uint;
#define BUFFER_SIZE 32
#define DATA_SIZE 30
uint data1533[BUFFER_SIZE];
uint simple_010_global_gap = 0;
uint simple_007_global_flag = 1;
void DataInit() {
    uint i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        data1533[i] = 0;
    }
    simple_010_global_gap = DATA_SIZE;
}

void LaunchStatusPack(uint *PdataSendBuf, uint *PdataRcvBuf) {
    uint si;
    for (si = 0; si < simple_010_global_gap; si++) {
        /// PdataSendBuf.size == 32,  a bug occurs here
        PdataSendBuf[si] = PdataRcvBuf[si];
    }
}

void RcvData(uint *data) {
    uint tmp[DATA_SIZE];
    LaunchStatusPack(tmp, data);
}

void simple_010_main() {
    DataInit();
    RcvData(data1533);
}

void simple_010_isr() {
    if (simple_007_global_flag != 0) {
        simple_010_global_gap = BUFFER_SIZE;
    } else {
        simple_010_global_gap = DATA_SIZE;
    }
}

//
//
//
//

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : tmp, 21
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1