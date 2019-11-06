// c4c76835d1286fa240fe02c4da81f6d4

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void) {
    set_priority(0);
    int pid;
    for (int i = 0; i < 10; i++) {
        pid = fork();
        if (pid == 0) {
            // set_priority(i*10);
#ifndef DEBUG
            int my_pid = getpid();
            for (int g = 0; g < 5; g++)
                printf(1, "i: %d pid: %d\n", i, my_pid);
#endif
            volatile int j = 0;
            for (volatile int k = 0; k < 10000000; k++) {
                j++;
                j = j % 12;
            }
            exit();
        }
        // printf(2, "***Made %d\n", pid);
    }
    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}