#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define led 17
#define button 18

int main()
{
    if (gpioInitialise() < 0)
    {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    gpioSetMode(led, PI_OUTPUT);
    gpioSetMode(button, PI_INPUT);
    gpioSetPullUpDown(button, PI_PUD_UP);

    while (1) {
        if (gpioRead(button) == 0) {
            printf("Led on ... \n");
            gpioWrite(led, 1);
        } else {
            printf("... Led off \n");
            gpioWrite(led, 0);
        }
    }

    gpioTerminate();
    return 0;
}
