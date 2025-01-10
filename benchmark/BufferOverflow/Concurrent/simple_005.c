int Voltage[9];
extern int rand();
extern void Process();
int AD_count = 0;

void simple_005_main() {
    while (1) {
        if (AD_count > 5) {
            Process();
        }
    }
}
void ade_isr()
{
    if(rand() == 1)
    {
        Voltage[AD_count] = rand() << 1; ///> bug
    }
    else if (rand() == 2)
    {
        Voltage[AD_count] = rand() << 2; ///> bug
    }
    else if (rand() == 3)
    {
        Voltage[AD_count] = rand() << 3; ///> bug
    }

    if (AD_count == 9)
    {
        AD_count = 0;
    }
    else
    {
        AD_count++;
    }
}

//
//
//
//

// CHECK-DAG: Buffer_Overflow : Voltage, 17
// CHECK-DAG: Buffer_Overflow : Voltage, 21
// CHECK-DAG: Buffer_Overflow : Voltage, 25
// CHECK-DAG: detected bugs = 3
// CHECK-DAG: detected Buffer_Overflow bugs = 3