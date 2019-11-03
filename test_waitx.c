#include "types.h"
#include "fcntl.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int pid;
    pid = fork();

    if (pid == 0) {
        volatile int j = 0;
        for (volatile int i = 0; i < 2000000000; i++) {
            j++;
            j = j % 2;
        }
        printf(1, "\nj: %d\n", j);
        exit();
    } else if (pid > 0) {
        int wtime, rtime;
        int wid = waitx(&wtime, &rtime);
        printf(1, "\nwid: %d\twtime: %d\trtime: %d\n", wid, wtime, rtime);
        exit();
    }
}