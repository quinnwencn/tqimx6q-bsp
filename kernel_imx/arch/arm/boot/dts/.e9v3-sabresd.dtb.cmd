cmd_arch/arm/boot/dts/e9v3-sabresd.dtb := mkdir -p arch/arm/boot/dts/ ; arm-linux-gnueabihf-gcc -E -Wp,-MD,arch/arm/boot/dts/.e9v3-sabresd.dtb.d.pre.tmp -nostdinc -I./arch/arm/boot/dts -I./arch/arm/boot/dts/include -I./drivers/of/testcase-data -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/.e9v3-sabresd.dtb.dts.tmp arch/arm/boot/dts/e9v3-sabresd.dts ; ./scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/e9v3-sabresd.dtb -b 0 -i arch/arm/boot/dts/  -d arch/arm/boot/dts/.e9v3-sabresd.dtb.d.dtc.tmp arch/arm/boot/dts/.e9v3-sabresd.dtb.dts.tmp ; cat arch/arm/boot/dts/.e9v3-sabresd.dtb.d.pre.tmp arch/arm/boot/dts/.e9v3-sabresd.dtb.d.dtc.tmp > arch/arm/boot/dts/.e9v3-sabresd.dtb.d

source_arch/arm/boot/dts/e9v3-sabresd.dtb := arch/arm/boot/dts/e9v3-sabresd.dts

deps_arch/arm/boot/dts/e9v3-sabresd.dtb := \
  arch/arm/boot/dts/e9v3q.dtsi \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/irq.h \
  arch/arm/boot/dts/imx6q-pinfunc.h \
  arch/arm/boot/dts/imx6qdl.dtsi \
  arch/arm/boot/dts/include/dt-bindings/clock/imx6qdl-clock.h \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  arch/arm/boot/dts/skeleton.dtsi \
  arch/arm/boot/dts/e9v3qdl-sabresd.dtsi \
  arch/arm/boot/dts/include/dt-bindings/gpio/gpio.h \
  arch/arm/boot/dts/include/dt-bindings/input/input.h \

arch/arm/boot/dts/e9v3-sabresd.dtb: $(deps_arch/arm/boot/dts/e9v3-sabresd.dtb)

$(deps_arch/arm/boot/dts/e9v3-sabresd.dtb):
