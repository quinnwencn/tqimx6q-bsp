cmd_firmware/built-in.o :=  arm-linux-gnueabihf-ld -EL    -r -o firmware/built-in.o firmware/imx/sdma/sdma-imx6q.bin.gen.o firmware/imx/sdma/sdma-imx7d.bin.gen.o firmware/ti_3410.fw.gen.o firmware/ti_5052.fw.gen.o firmware/mts_cdma.fw.gen.o firmware/mts_gsm.fw.gen.o firmware/mts_edge.fw.gen.o firmware/edgeport/boot.fw.gen.o firmware/edgeport/boot2.fw.gen.o firmware/edgeport/down.fw.gen.o firmware/edgeport/down2.fw.gen.o firmware/edgeport/down3.bin.gen.o firmware/whiteheat_loader.fw.gen.o firmware/whiteheat.fw.gen.o firmware/keyspan_pda/keyspan_pda.fw.gen.o firmware/keyspan_pda/xircom_pgs.fw.gen.o 
