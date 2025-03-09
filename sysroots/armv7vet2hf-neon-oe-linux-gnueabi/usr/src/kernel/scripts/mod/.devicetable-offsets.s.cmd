cmd_scripts/mod/devicetable-offsets.s := arm-oe-linux-gnueabi-gcc  -mno-thumb-interwork -marm -fuse-ld=bfd -fmacro-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0=/usr/src/debug/make-mod-scripts/1.0-r0                      -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0=/usr/src/debug/make-mod-scripts/1.0-r0                      -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot=                      -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native=  -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source=/usr/src/kernel -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-build-artifacts=/usr/src/kernel -Wp,-MD,scripts/mod/.devicetable-offsets.s.d -nostdinc -isystem /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/bin/arm-oe-linux-gnueabi/../../lib/arm-oe-linux-gnueabi/gcc/arm-oe-linux-gnueabi/9.5.0/include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include -I./arch/arm/include/generated -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include -I./include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi -I./include/generated/uapi -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_types.h -D__KERNEL__ -mlittle-endian -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/mach-qcom/include -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -Wno-misleading-indentation -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mfpu=vfp -funwind-tables -marm -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -Os --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fmacro-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/= -Wno-packed-not-aligned -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/mod -I ./scripts/mod -DKBUILD_BASENAME='"devicetable_offsets"' -DKBUILD_MODNAME='"devicetable_offsets"'  -fverbose-asm -S -o scripts/mod/devicetable-offsets.s /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/mod/devicetable-offsets.c

source_scripts/mod/devicetable-offsets.s := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/mod/devicetable-offsets.c

deps_scripts/mod/devicetable-offsets.s := \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/cc/has/asm/inline.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_attributes.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler-gcc.h \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kbuild.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/mod_devicetable.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi/asm/types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/asm-generic/int-ll64.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/uapi/asm/bitsperlong.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/asm-generic/bitsperlong.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/bitsperlong.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/posix_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/stddef.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/stddef.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi/asm/posix_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/posix_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/uuid.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/uuid.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
    $(wildcard include/config/kasan.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/debug/entry.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arm/heavy/mb.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/spectre.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/asm-generic/barrier.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kasan-checks.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/lib/arm-oe-linux-gnueabi/gcc/arm-oe-linux-gnueabi/9.5.0/include/stdarg.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/string.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/asm/string.h \

scripts/mod/devicetable-offsets.s: $(deps_scripts/mod/devicetable-offsets.s)

$(deps_scripts/mod/devicetable-offsets.s):
