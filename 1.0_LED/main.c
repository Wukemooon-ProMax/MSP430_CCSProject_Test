#include "driverlib.h"

void main (void)
{
    WDT_A_hold(WDT_A_BASE);

    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2,GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN7);

    while (1) {
        if (GPIO_getInputPinValue(GPIO_PORT_P2,GPIO_PIN1)==0) {
            __delay_cycles(100000);
            if (GPIO_getInputPinValue(GPIO_PORT_P2,GPIO_PIN1)==0) {
                GPIO_toggleOutputOnPin(GPIO_PORT_P4,GPIO_PIN7);
            }
        }
    }
    
    //return(0);
    
    /*
    GPIO_setAsInputPinWithPullUpResistor上拉模式，P2.0连接GND需要默认状态为高电平。
    */
}
