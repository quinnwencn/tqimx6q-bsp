cmd_drivers/usb/host/built-in.o :=  arm-linux-gnueabihf-ld -EL    -r -o drivers/usb/host/built-in.o drivers/usb/host/pci-quirks.o drivers/usb/host/ehci-hcd.o drivers/usb/host/ehci-pci.o drivers/usb/host/ehci-mxc.o drivers/usb/host/ohci-hcd.o drivers/usb/host/ohci-pci.o drivers/usb/host/ohci-platform.o 
