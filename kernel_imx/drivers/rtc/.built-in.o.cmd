cmd_drivers/rtc/built-in.o :=  arm-linux-gnueabihf-ld -EL    -r -o drivers/rtc/built-in.o drivers/rtc/rtc-lib.o drivers/rtc/hctosys.o drivers/rtc/systohc.o drivers/rtc/rtc-core.o drivers/rtc/rtc-mxc.o drivers/rtc/rtc-pcf8563.o drivers/rtc/rtc-snvs.o 
