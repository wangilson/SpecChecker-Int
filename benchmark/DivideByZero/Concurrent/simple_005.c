//
//
//

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)
int stdin;
int data = -1;
int simple_005_flag = 0;
extern int fgets(char * stream, int sz, int s);
extern int atoi(char * stream);
extern void printLine(char * stream);
extern void printIntLine(int);
void simple_005_main() {
    char input_buf[CHAR_ARRAY_SIZE] = "";
    /* POTENTIAL FLAW: Read data from the console using fgets() */
    if (fgets(input_buf, CHAR_ARRAY_SIZE, stdin) != 0) {
        /* Convert to int */
        data = atoi(input_buf); // data可能为0
    } else {
        printLine("fgets() failed.");
    }
    if (simple_005_flag == 0) {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100);
    }else{
        printIntLine(100/ data); // 在30-14之间发生抢占则可能导致除零错误，如果与上面保持一致就不会导致除零错误，但中断改变了条件
    }
}

void simple_005_isr() {
    if (simple_005_flag == 0) {
        simple_005_flag = 1;
    } else {
        simple_005_flag = 0;
    }
}


//
//
//
//

// CHECK-DAG: Interrupt-Aware Div_Zero : data, 26
// CHECK-DAG: done: detected bugs = 1
// CHECK-DAG: done: detected Interrupt-Aware Div_Zero bugs = 1
