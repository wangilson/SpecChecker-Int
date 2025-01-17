#define BUFFER_SIZE 10
#define TRUE 1
typedef unsigned int uint;
typedef unsigned char uchar;
uint num = 0x0d000000;
int receive_buffer_B[BUFFER_SIZE];
uchar falg_clock = TRUE;
uint send_frame_num_B = 0;

void simple_008_Init();
extern uint rand();
int SRAMcheck();
int main()
{
	return SRAMcheck();
}

int SRAMcheck() {
    unsigned int index = 0;
    simple_008_Init();

    if (send_frame_num_B < BUFFER_SIZE) {
        index = send_frame_num_B;
    } else {
        index = 0;
    }

    receive_buffer_B[index] = 0;
	return 0;
}

void simple_008_Init() {
    send_frame_num_B = rand();
}

void Int0ISR() {
	if(num >= 0x0c000000){
		if(falg_clock == TRUE)
		{
			send_frame_num_B++;
		}
	}
}


// CHECK-DAG: Interrupt-Aware Buffer_Overflow : receive_buffer_B, 28
// CHECK-DAG: detected bugs = 1
// CHECK-DAG: detected Interrupt-Aware Buffer_Overflow bugs = 1
