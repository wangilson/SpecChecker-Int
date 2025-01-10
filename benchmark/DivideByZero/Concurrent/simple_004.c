//
//
//

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)
int stdin;
int data = -1;
static int static_five = 5;
extern int fgets(char * stream, int sz, int s);
extern int atoi(char * stream);
extern void printLine(char * stream);
extern void printIntLine(int);
void simple_004_main() {
    if (static_five == 5) {
        {
            char input_buf[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Read data from the console using fgets() */
            if (fgets(input_buf, CHAR_ARRAY_SIZE, stdin) != 0) {
                /* Convert to int */
                data = atoi(input_buf);
            } else {
                printLine("fgets() failed.");
            }
        }
    } else {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a value not equal to zero */
        data = 7;
    }
    if (static_five == 5) {
        /* POTENTIAL FLAW: Possibly divide by zero */
        if (data != 0) {
            printIntLine(100 / data); // 在30-31之间发生抢占则可能导致除零错误
        } else {
            printIntLine(100);
        }
    }
}

void simple_004_isr() {
    char input_buf[CHAR_ARRAY_SIZE] = "";
    if (fgets(input_buf, CHAR_ARRAY_SIZE, stdin) != 0) {
        /* Convert to int */
        data = atoi(input_buf);
    } else {
        printLine("fgets() failed.");
    }
}


//
//
//
//

// CHECK-DAG: Interrupt-Aware Div_Zero : data, 33
// CHECK-DAG: done: detected bugs = 1
// CHECK-DAG: done: detected Interrupt-Aware Div_Zero bugs = 1
