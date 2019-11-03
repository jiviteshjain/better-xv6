// c4c76835d1286fa240fe02c4da81f6d4

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void) {
    int pid;
    for (int i = 0; i < 10; i++) {
        pid = fork();
        if (pid == 0) {
            int my_pid = getpid();
            for (int g = 0; g < 5; g++)
                printf(1, "i: %d pid: %d\n", i, my_pid);
            volatile int j = 0;
            for (volatile int k = 0; k < 10000; k++) {
                j++;
                j = j % 12;
            }
            exit();
        }
    }
    for (int i = 0; i < 10; i++) {
        wait();
    }
    exit();
}