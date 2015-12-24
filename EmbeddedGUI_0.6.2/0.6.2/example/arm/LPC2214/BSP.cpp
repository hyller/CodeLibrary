#include "BSP.h"
#include "LPC22xx.H"

#define ExtSRAMAddress 0x40000000
  
void delay(unsigned int n){
	for(int m=0;m<n;m++){
		;	
	}
}

//void BSP_UART_SendStringCongestion(const char* string){
//	//disable the UART interrputs
//	U0IER= 0x00;	
//	while(1){	
//		int n=0;
//loop:
//		if (string[n]=='\0')
//			break;
//		U0RBR=string[n];
//		n++;
//		while((U0LSR & 0x40)==0 )
//			;//congested,wait until send over
//		goto loop;
//	}
//	//enable all UART interrputs again
//	U0IER= 0x07;
//}
//
//void BSP_UART_SendBufferCongestion(char* string,int length){
//	//disable the UART interrputs
//	U0IER= 0x00;	
//	while(1){	
//		int n=0;
//loop:
//		if (n==length)
//			break;
//		U0RBR=string[n];
//		n++;
//		while((U0LSR & 0x40)==0 )
//			;//congested,wait until send over
//		goto loop;
//	}
//	//enable all UART interrputs again
//	U0IER= 0x07;
//}
//
//void BSP_UART_ReceiveStringCongestion(char* pBuffer,int size){
//	//disable the UART interrputs
//	U0IER= 0x00;	
//	while((U0LSR & 0x01)==0 ){//congested,wait until receive data
//		int n=0;
//		pBuffer[n]= U0RBR;
//		n++;
//		if (n==size)
//			break;
//	}
//	//enable all UART interrputs again
//	U0IER= 0x07;
//}

unsigned char BSP_GetFuncKey(){
    unsigned int temp=IOPIN0;
    temp=temp&0x0E;
    if (temp!=0x0E){
        delay(3000);
        temp=IOPIN0;
        temp=temp&0x0E;
        if (temp!=0x0E){  // indeed pressed
            if (temp&0x02)
                return 1;
            else if(temp&0x04)
                return 2;
            else
                return 3;
        }else
            return 0;    
    }else
        return 0;
}










