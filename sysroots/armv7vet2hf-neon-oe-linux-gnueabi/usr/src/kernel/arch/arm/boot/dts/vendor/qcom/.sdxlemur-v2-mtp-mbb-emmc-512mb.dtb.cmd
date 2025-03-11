cmd_arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb := mkdir -p arch/arm/boot/dts/vendor/qcom/ ; gcc  -isystem/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/include -O2 -pipe -L/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/lib                         -L/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/lib                         -Wl,--enable-new-dtags                         -Wl,-rpath-link,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/lib                         -Wl,-rpath-link,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/lib                         -Wl,-rpath,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/lib                         -Wl,-rpath,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/lib                         -Wl,-O1 -Wl,--allow-shlib-undefined -Wl,--dynamic-linker=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/sysroots-uninative/x86_64-linux/lib/ld-linux-x86-64.so.2 -E -Wp,-MD,arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.d.pre.tmp -nostdinc -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.dts.tmp /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dts ; /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin/dtc -O dtb -o arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb -b 0 -i/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/ -i/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes -@ -Wno-unit_address_vs_reg  -d arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.d.dtc.tmp arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.dts.tmp ; cat arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.d.pre.tmp arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.d.dtc.tmp > arch/arm/boot/dts/vendor/qcom/.sdxlemur-v2-mtp-mbb-emmc-512mb.dtb.d

source_arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dts

deps_arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb := \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-v2.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/clock/qcom,aop-qmp.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/clock/qcom,apsscc-sdxlemur.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/clock/qcom,gcc-sdxlemur.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/clock/qcom,rpmh.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/soc/qcom,dcc_v2.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/sound/qcom,gpr.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/arm-gic.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/interrupt-controller/irq.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/regulator/qcom,rpmh-regulator-levels.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/interconnect/qcom,sdxlemur.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/soc/qcom,rpmh-rsc.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/spmi/spmi.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-pinctrl.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-regulators.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/gpio/gpio.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-coresight.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/msm-arm-smmu-sdxlemur.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-ion.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/arm/msm/msm_ion_ids.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-usb.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/phy/qcom,usb3-5nm-qmp-uni.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-pm.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-pcie.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-blsp.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-thermal.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/thermal/thermal_qti.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/thermal/thermal.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-thermal-modem.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-mtp-mbb-pcie-ep.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-mtp.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-pmic-overlay.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pmx65.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/pmk8350.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/input/input.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/input/linux-event-codes.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/input/qcom,qpnp-power-on.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pm8350b.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pm8350.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pmk8350.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pmr735a.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-adc7-pmr735b.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/pmx65.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-mtp-mbb-emmc.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/pm7250b.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/clock/qcom,rpmcc.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qcom,spmi-vadc.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/iio/qti_power_supply_iio.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/dtc/include-prefixes/dt-bindings/pinctrl/qcom,pmic-gpio.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/qg-batterydata-alium-3600mah.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/smb1394.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-512mb.dtsi \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/dts/vendor/qcom/sdxlemur-bluetooth.dtsi \

arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb: $(deps_arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb)

$(deps_arch/arm/boot/dts/vendor/qcom/sdxlemur-v2-mtp-mbb-emmc-512mb.dtb):
