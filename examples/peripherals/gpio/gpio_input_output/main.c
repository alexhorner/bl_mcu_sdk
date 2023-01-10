#include "bflb_mtimer.h"
#include "bflb_gpio.h"
#include "board.h"
#include <inttypes.h>

struct bflb_device_s *gpio;

int main(void)
{
    board_init();
    printf("\r\nHello!\r\n");
    //uint64_t time = bflb_mtimer_get_time_us();
    //printf("%" PRIu64 "\r\n", time);
    //time = bflb_mtimer_get_time_us();
    //printf("%" PRIu64 "\r\n", time);

    /*while (1) {
        time = bflb_mtimer_get_time_us();
        printf("%" PRIu64 "\r\n", time);
    }*/
    //printf(time);
    bflb_mtimer_delay_ms(3000);

    gpio = bflb_device_get_by_name("gpio");
    printf("gpio loaded\r\n");
    bflb_gpio_init(gpio, GPIO_PIN_8, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    printf("gpio init\r\n");
    //bflb_gpio_init(gpio, GPIO_PIN_1, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);

    while (1) {
        bflb_gpio_set(gpio, GPIO_PIN_8);
        //printf("GPIO_PIN_1=%x\r\n", bflb_gpio_read(gpio, GPIO_PIN_1));
        printf("On\r\n");
        bflb_mtimer_delay_ms(500);

        bflb_gpio_reset(gpio, GPIO_PIN_8);
        //printf("GPIO_PIN_1=%x\r\n", bflb_gpio_read(gpio, GPIO_PIN_1));
        printf("Off\r\n");
        bflb_mtimer_delay_ms(500);
    }
}
