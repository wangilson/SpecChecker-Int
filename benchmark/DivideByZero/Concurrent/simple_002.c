
int rand();

int simple_002_x, simple_002_y, simple_002_z;

void simple_002_main() {
    simple_002_x = rand();
    simple_002_y = rand();
    if (simple_002_x < simple_002_y) {
        simple_002_z = 1 / (simple_002_x - simple_002_y);
    }
}

void simple_002_isr_1()                        // not safe interrupt
{
    simple_002_x++;
    simple_002_y--;
}

void simple_002_isr_2()                        // safe interrupt
{
    simple_002_x++;
    simple_002_y--;
    if (simple_002_x == simple_002_y) {
        simple_002_x++;
        simple_002_y--;
    }
}

//
//
//
//

// CHECK-DAG: Interrupt-Aware Div_Zero : , 10
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Div_Zero bugs = 1