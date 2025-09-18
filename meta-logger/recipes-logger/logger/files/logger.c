#include <stdio.h>
#include <syslog.h>
//#include "calc.h"

int main(void) {
    openlog("logger-app", LOG_PID|LOG_CONS, LOG_USER);
    //syslog(LOG_INFO, calculate(1,+,2, &result));
    syslog(LOG_INFO, "hi");
    closelog();
    
    return 0;
}

