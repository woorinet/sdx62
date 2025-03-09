cmd_arch/arm/boot/compressed/piggy.o := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin/clang -target arm-oe-linux-gnueabi -DBINDER_IPC_32BIT=1   -Wp,-MD,arch/arm/boot/compressed/.piggy.o.d  -nostdinc -isystem /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/lib/clang/10.0.1/include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include -I./arch/arm/include/generated -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include -I./include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi -I./include/generated/uapi -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/mach-qcom/include -Qunused-arguments -D__ASSEMBLY__ -fno-PIE --target=arm-oe-linux-gnueabi --prefix=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi- --gcc-toolchain=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin -no-integrated-as -Werror=unknown-warning-option -mabi=aapcs-linux -mfpu=vfp -funwind-tables -meabi gnu -marm -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -include asm/unified.h -msoft-float -Wa,-gdwarf-2 -DZIMAGE -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/compressed -I ./arch/arm/boot/compressed    -c -o arch/arm/boot/compressed/piggy.o /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/compressed/piggy.S

source_arch/arm/boot/compressed/piggy.o := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/boot/compressed/piggy.S

deps_arch/arm/boot/compressed/piggy.o := \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/asm/unified.h \
    $(wildcard include/config/cpu/v7m.h) \
    $(wildcard include/config/thumb2/kernel.h) \

arch/arm/boot/compressed/piggy.o: $(deps_arch/arm/boot/compressed/piggy.o)

$(deps_arch/arm/boot/compressed/piggy.o):
