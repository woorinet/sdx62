cmd_usr/initramfs_data.o := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin/clang -target arm-oe-linux-gnueabi -DBINDER_IPC_32BIT=1   -Wp,-MD,usr/.initramfs_data.o.d  -nostdinc -isystem /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/lib/clang/10.0.1/include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include -I./arch/arm/include/generated -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include -I./include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi -I./include/generated/uapi -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/mach-qcom/include -Qunused-arguments -D__ASSEMBLY__ -fno-PIE --target=arm-oe-linux-gnueabi --prefix=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi- --gcc-toolchain=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/linux-msm/5.4-r0/recipe-sysroot-native/usr/bin -no-integrated-as -Werror=unknown-warning-option -mabi=aapcs-linux -mfpu=vfp -funwind-tables -meabi gnu -marm -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -include asm/unified.h -msoft-float -Wa,-gdwarf-2 -DINITRAMFS_IMAGE="usr/initramfs_data.cpio" -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/usr -I ./usr    -c -o usr/initramfs_data.o /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/usr/initramfs_data.S

source_usr/initramfs_data.o := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/usr/initramfs_data.S

deps_usr/initramfs_data.o := \
    $(wildcard include/config/64bit.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/asm/unified.h \
    $(wildcard include/config/cpu/v7m.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/stringify.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/asm-generic/vmlinux.lds.h \
    $(wildcard include/config/ld/dead/code/data/elimination.h) \
    $(wildcard include/config/lto/clang.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kprobes.h) \
    $(wildcard include/config/function/error/injection.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/syscalls.h) \
    $(wildcard include/config/bpf/events.h) \
    $(wildcard include/config/serial/earlycon.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/timer/of.h) \
    $(wildcard include/config/irqchip.h) \
    $(wildcard include/config/common/clk.h) \
    $(wildcard include/config/of/reserved/mem.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/idle.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/thermal.h) \
    $(wildcard include/config/debug/info/btf.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/unwinder/orc.h) \
    $(wildcard include/config/pm/trace.h) \
    $(wildcard include/config/blk/dev/initrd.h) \
    $(wildcard include/config/amd/mem/encrypt.h) \

usr/initramfs_data.o: $(deps_usr/initramfs_data.o)

$(deps_usr/initramfs_data.o):
