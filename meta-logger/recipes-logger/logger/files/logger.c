#include <stdio.h>
#include <syslog.h>
//#include "calc.h"

int main() {
    openlog("logger", LOG_PID|LOG_CONS, LOG_USER);
    //int result = calculate(1, 2, '+');
    //syslog(LOG_INFO, "%d", result);
    closelog();
    return 0;
}

