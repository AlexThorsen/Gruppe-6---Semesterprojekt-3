/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "UART_1.h"

CY_ISR(TXInterrupt_handler) {
    
}

CY_ISR(RXInterrupt_handler) {
    
//    char input[3] = {'0','\r','\n'};
//    
//    input[0] = UART_1_GetChar();
//    
//    UART_1_PutString(input);
    
    switch(UART_1_GetChar()) {
        case 'b' | 'B':
            LED_Write(!LED_Read());
        break;
//        case 'a' | 'A':
//            UART_1_PutString("a\r");
//        break;
//        case 'n' | 'N':
//            UART_1_PutString("n\r");
//        break;
        case 'h' | 'H':
            UART_1_PutString("Hallo world\r");
        break;
    }
}

int main(void)
{
    CyGlobalIntEnable;
    
    TXInterrupt_StartEx(TXInterrupt_handler);
    RXInterrupt_StartEx(RXInterrupt_handler);
    UART_1_Start();
    
    for(;;)
    {
        
    }
    
    TXInterrupt_Stop();
    RXInterrupt_Stop();
    UART_1_Stop();
}
