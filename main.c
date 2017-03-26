#include <stdlib.h>
#include <sys/time.h>
#include "util_mosq.h"
#include "config.h"

int main(int argc, char** argv) {

    mosq_sock_t *listensock = NULL;

    int listensock_count = 0;
    int listensock_index = 0;


    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec + tv.tv_usec); //用时间来做种子


    //初始化mosquitto db

    printf("Momo mqtt server\n");
    return 0;
}