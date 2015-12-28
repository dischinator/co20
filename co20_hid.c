#include <stdio.h>
#include <string.h>
#include "hidapi.h"
#include "co20_hid.h"

hid_device *co20_handle;

int co20_init() {
    // open the device using the VID, PID,
    co20_handle = hid_open(0x3eb, 0x2013, NULL);
    if(!co20_handle) {
        printf("device not found\n");
        return 1;
    }
    
    return 0;
}

short co20_get_air_quality() {
    short airValue=0;
    int res;
    unsigned char buf[65];
    
    memcpy(buf, "\x00\x40\x68\x2a\x54\x52\x0a\x40\x40\x40\x40\x40\x40\x40\x40\x40\x40", 0x11);
    res = hid_write(co20_handle, buf, 0x11);
    if(res!=0x11) {
        printf("write error: %d\n", res);
        return -1;
    }
    
    res = hid_read(co20_handle, buf, 65);
    if (res < 0) {
        printf("unable to read()\n");
        return -1;
    }

    // copy current air quality value from buffer
    // you should get 450 as a result when you plug in the stick,
    // if you are getting weird results you are probably not on a little endian system
    // and need to correct the byte order
    memcpy(&airValue, buf+2, 2);

    return airValue;        
}
