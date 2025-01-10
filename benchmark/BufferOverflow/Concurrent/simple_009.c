
typedef unsigned short UINT32;
#define BB_BASE_ADDR 0x1000
#define BB_DECODE_VITERBI_OUT_SDA (*((volatile UINT32 *)(BB_BASE_ADDR + 0x9450)))
UINT32 viterbi_status = 0;
UINT32 output_num = 2;
void get_res(UINT32 *output_buf)
{
    UINT32 buf_id = 0;
    UINT32 output = 0x9450;
    for (UINT32 i = 0 ; i < output_num ; i++)                 ///> if interrupt is preempted before there, the value of
    {                                                           ///> output_num is unknown
        if (i % 2 == 0)
        {
            output_buf[buf_id] = (output >> 24) & 0xff;         /// bug
            output_buf[buf_id + 1] = (output >> 16) & 0xff;     /// bug
            output_buf[buf_id + 2] = (output >> 8) & 0xff;      /// bug
            output_buf[buf_id + 3] = (output >> 24) & 0xff;     /// bug
            buf_id += 4;
        }
    }
}

void simple_009_main()
{
    UINT32 output_buf[4];
    get_res(output_buf);
}

void simple_009_isr(){
    viterbi_status = BB_DECODE_VITERBI_OUT_SDA;
    output_num = (viterbi_status >> 4) & 0x1FF;
}

//
//
//
//

// CHECK-DAG: Interrupt-Aware Buffer_Overflow : output_buf, 15
// CHECK-DAG: Interrupt-Aware Buffer_Overflow : output_buf, 16
// CHECK-DAG: Interrupt-Aware Buffer_Overflow : output_buf, 17
// CHECK-DAG: Interrupt-Aware Buffer_Overflow : output_buf, 18
// CHECK-DAG: detected bugs = 4
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 4