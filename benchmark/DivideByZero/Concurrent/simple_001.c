
int rand();
int simple_001_d;
void print(int);

void simple_001_main() {
    simple_001_d = rand();
    if (simple_001_d != 0) {
        print(10 / simple_001_d);
    }
}

void simple_001_isr_1()                 // not safe interrupt
{
    simple_001_d--;
}

void simple_001_isr_2()                // safe interrupt
{
    simple_001_d--;
    if (simple_001_d <= 0)
    {
        simple_001_d = 1;
    }
}

//
//
//
//

// CHECK-DAG: Interrupt-Aware Div_Zero : simple_001_d, 9
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: Interrupt-Aware Div_Zero bugs = 1