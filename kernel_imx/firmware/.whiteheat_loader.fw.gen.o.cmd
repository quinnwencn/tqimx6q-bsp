cmd_firmware/whiteheat_loader.fw.gen.o := arm-linux-gnueabihf-gcc -Wp,-MD,firmware/.whiteheat_loader.fw.gen.o.d  -nostdinc -isystem /opt/EmbedSky/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf/bin/../lib/gcc/arm-linux-gnueabihf/5.3.1/include -I./arch/arm/include -Iarch/arm/include/generated/uapi -Iarch/arm/include/generated  -Iinclude -I./arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I./include/uapi -Iinclude/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian   -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -DCC_HAVE_ASM_GOTO            -c -o firmware/whiteheat_loader.fw.gen.o firmware/whiteheat_loader.fw.gen.S

source_firmware/whiteheat_loader.fw.gen.o := firmware/whiteheat_loader.fw.gen.S

deps_firmware/whiteheat_loader.fw.gen.o := \
  arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/cpu/v7m.h) \
    $(wildcard include/config/thumb2/kernel.h) \

firmware/whiteheat_loader.fw.gen.o: $(deps_firmware/whiteheat_loader.fw.gen.o)

$(deps_firmware/whiteheat_loader.fw.gen.o):
