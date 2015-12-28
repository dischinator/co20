#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "co20_hid.h"

int main(int argc, char* argv[])
{
    unsigned short airValue=0;
    char date[26];
    time_t timer;
    struct tm* tm_info;
    FILE* csv;
    
    co20_init();
        
    csv = fopen("air.csv","a");
    if(!csv) {
        printf("cannot open air.csv for appending\n");
        return 1;
    }
    setvbuf(csv, NULL, _IONBF, 0);
    
    while(1) {
        airValue = co20_get_air_quality();

        time(&timer);
        tm_info = localtime(&timer);
        strftime(date, 26, "%d.%m.%Y %H:%M:%S", tm_info);
        fprintf(csv, "%s;%d\n", date, airValue);
        printf("%s;%d\n", date, airValue);
        
        sleep(2);
    }
}
