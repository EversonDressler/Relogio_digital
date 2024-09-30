
#include <stdio.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

int main(){

    stdio_init_all();
    printf("Relogio!\n");

    char datetime_buf[256], relogio[10];
    char *datetime_str = &datetime_buf[0];

    datetime_t t = {
            .year  = 2024,
            .month = 9,
            .day   = 29,
            .dotw  = 0, 
            .hour  = ((__TIME__[0] - '0')*10) + (__TIME__[1] - '0'),
            .min   = ((__TIME__[3] - '0')*10) + (__TIME__[4] - '0'),
            .sec   = ((__TIME__[6] - '0')*10) + (__TIME__[7] - '0')
    };

    rtc_init();
    rtc_set_datetime(&t);
   
    for(;;){

        rtc_get_datetime(&t);
        datetime_to_str(datetime_str, sizeof(datetime_buf), &t);

        for (int i = 20; i < 29; i++)
        {
            relogio[i-20] = datetime_str[i];
        }
        relogio[9]='\0';

        printf("\r%s      \n", relogio);
        sleep_ms(1000);
    }
}
