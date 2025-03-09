	.arch armv7-a
	.fpu softvfp
	.eabi_attribute 20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute 21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute 23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute 24, 1	@ Tag_ABI_align8_needed
	.eabi_attribute 25, 1	@ Tag_ABI_align8_preserved
	.eabi_attribute 26, 2	@ Tag_ABI_enum_size
	.eabi_attribute 30, 4	@ Tag_ABI_optimization_goals
	.eabi_attribute 34, 1	@ Tag_CPU_unaligned_access
	.eabi_attribute 18, 2	@ Tag_ABI_PCS_wchar_t
	.file	"asm-offsets.c"
@ GNU C89 (GCC) version 9.5.0 (arm-oe-linux-gnueabi)
@	compiled by GNU C version 5.5.0 20171010, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version none
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -nostdinc
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include
@ -I ./arch/arm/include/generated
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include
@ -I ./include
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/include/uapi
@ -I ./arch/arm/include/generated/uapi
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi
@ -I ./include/generated/uapi
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/mach-qcom/include
@ -I /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/.
@ -I ./.
@ -iprefix /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/bin/arm-oe-linux-gnueabi/../../lib/arm-oe-linux-gnueabi/gcc/arm-oe-linux-gnueabi/9.5.0/
@ -D __KERNEL__ -D __LINUX_ARM_ARCH__=7 -U arm
@ -D KBUILD_BASENAME="asm_offsets" -D KBUILD_MODNAME="asm_offsets"
@ -isystem /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/bin/arm-oe-linux-gnueabi/../../lib/arm-oe-linux-gnueabi/gcc/arm-oe-linux-gnueabi/9.5.0/include
@ -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h
@ -include /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_types.h
@ -MD arch/arm/kernel/.asm-offsets.s.d
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c
@ -mno-thumb-interwork -mlittle-endian -mabi=aapcs-linux -mfpu=vfp -marm
@ -mfloat-abi=soft -mtls-dialect=gnu -march=armv7-a
@ -auxbase-strip arch/arm/kernel/asm-offsets.s -Os -Wall -Wundef
@ -Werror=strict-prototypes -Wno-trigraphs
@ -Werror=implicit-function-declaration -Werror=implicit-int
@ -Werror=return-type -Wno-format-security -Wno-misleading-indentation
@ -Wno-frame-address -Wformat-truncation=0 -Wformat-overflow=0
@ -Wno-address-of-packed-member -Wframe-larger-than=1024
@ -Wimplicit-fallthrough=3 -Wno-unused-but-set-variable
@ -Wunused-const-variable=0 -Wdeclaration-after-statement -Wvla
@ -Wno-pointer-sign -Wno-stringop-truncation -Wno-array-bounds
@ -Wstringop-overflow=0 -Wno-restrict -Wno-maybe-uninitialized
@ -Werror=date-time -Werror=incompatible-pointer-types
@ -Werror=designated-init -Wno-packed-not-aligned -std=gnu90 -fuse-ld=bfd
@ -fmacro-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0=/usr/src/debug/make-mod-scripts/1.0-r0
@ -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0=/usr/src/debug/make-mod-scripts/1.0-r0
@ -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot=
@ -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native=
@ -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source=/usr/src/kernel
@ -fdebug-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-build-artifacts=/usr/src/kernel
@ -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE
@ -fno-dwarf2-cfi-asm -fno-ipa-sra -funwind-tables
@ -fno-delete-null-pointer-checks -fstack-protector-strong
@ -fomit-frame-pointer -fno-strict-overflow -fno-merge-all-constants
@ -fmerge-constants -fstack-check=no -fconserve-stack
@ -fmacro-prefix-map=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/=
@ -fverbose-asm --param allow-store-data-races=0
@ options enabled:  -faggressive-loop-optimizations -fassume-phsa
@ -fauto-inc-dec -fbranch-count-reg -fcaller-saves -fcode-hoisting
@ -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
@ -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdevirtualize
@ -fdevirtualize-speculatively -fearly-inlining
@ -feliminate-unused-debug-types -fexpensive-optimizations
@ -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse
@ -fgcse-lm -fgnu-runtime -fgnu-unique -fguess-branch-probability
@ -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
@ -findirect-inlining -finline -finline-atomics -finline-functions
@ -finline-functions-called-once -finline-small-functions -fipa-bit-cp
@ -fipa-cp -fipa-icf -fipa-icf-functions -fipa-icf-variables -fipa-profile
@ -fipa-pure-const -fipa-ra -fipa-reference -fipa-reference-addressable
@ -fipa-stack-alignment -fipa-vrp -fira-hoist-pressure
@ -fira-share-save-slots -fira-share-spill-slots
@ -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
@ -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
@ -fmath-errno -fmerge-constants -fmerge-debug-strings
@ -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
@ -fpartial-inlining -fpeephole -fpeephole2 -fplt -fprefetch-loop-arrays
@ -freg-struct-return -freorder-blocks -freorder-functions
@ -frerun-cse-after-loop -fsched-critical-path-heuristic
@ -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
@ -fsched-last-insn-heuristic -fsched-pressure -fsched-rank-heuristic
@ -fsched-spec -fsched-spec-insn-heuristic -fsched-stalled-insns-dep
@ -fschedule-insns2 -fsection-anchors -fsemantic-interposition
@ -fshow-column -fshrink-wrap -fshrink-wrap-separate -fsigned-zeros
@ -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop -fssa-phiopt
@ -fstack-protector-strong -fstdarg-opt -fstore-merging
@ -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
@ -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
@ -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
@ -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
@ -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
@ -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
@ -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
@ -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
@ -ftree-vrp -funit-at-a-time -funwind-tables -fverbose-asm -fwrapv
@ -fwrapv-pointer -fzero-initialized-in-bss -marm -mbe32 -mglibc
@ -mlittle-endian -mpic-data-is-text-relative -msched-prolog
@ -munaligned-access -mvectorize-with-neon-quad

	.text
	.syntax divided
	.syntax unified
	.arm
	.syntax unified
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	.fnstart
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:51:   DEFINE(TSK_ACTIVE_MM,		offsetof(struct task_struct, active_mm));
	.syntax divided
@ 51 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TSK_ACTIVE_MM #748 offsetof(struct task_struct, active_mm)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:53:   DEFINE(TSK_STACK_CANARY,	offsetof(struct task_struct, stack_canary));
@ 53 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TSK_STACK_CANARY #864 offsetof(struct task_struct, stack_canary)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:55:   BLANK();
@ 55 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:56:   DEFINE(TI_FLAGS,		offsetof(struct thread_info, flags));
@ 56 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_FLAGS #0 offsetof(struct thread_info, flags)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:57:   DEFINE(TI_PREEMPT,		offsetof(struct thread_info, preempt_count));
@ 57 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_PREEMPT #4 offsetof(struct thread_info, preempt_count)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:58:   DEFINE(TI_ADDR_LIMIT,		offsetof(struct thread_info, addr_limit));
@ 58 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_ADDR_LIMIT #8 offsetof(struct thread_info, addr_limit)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:59:   DEFINE(TI_TASK,		offsetof(struct thread_info, task));
@ 59 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_TASK #12 offsetof(struct thread_info, task)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:60:   DEFINE(TI_CPU,		offsetof(struct thread_info, cpu));
@ 60 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_CPU #16 offsetof(struct thread_info, cpu)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:61:   DEFINE(TI_CPU_DOMAIN,		offsetof(struct thread_info, cpu_domain));
@ 61 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_CPU_DOMAIN #20 offsetof(struct thread_info, cpu_domain)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:62:   DEFINE(TI_CPU_SAVE,		offsetof(struct thread_info, cpu_context));
@ 62 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_CPU_SAVE #24 offsetof(struct thread_info, cpu_context)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:63:   DEFINE(TI_USED_CP,		offsetof(struct thread_info, used_cp));
@ 63 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_USED_CP #76 offsetof(struct thread_info, used_cp)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:64:   DEFINE(TI_TP_VALUE,		offsetof(struct thread_info, tp_value));
@ 64 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_TP_VALUE #92 offsetof(struct thread_info, tp_value)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:65:   DEFINE(TI_FPSTATE,		offsetof(struct thread_info, fpstate));
@ 65 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_FPSTATE #104 offsetof(struct thread_info, fpstate)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:67:   DEFINE(TI_VFPSTATE,		offsetof(struct thread_info, vfpstate));
@ 67 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->TI_VFPSTATE #248 offsetof(struct thread_info, vfpstate)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:84:   DEFINE(THREAD_SZ_ORDER,	THREAD_SIZE_ORDER);
@ 84 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->THREAD_SZ_ORDER #1 THREAD_SIZE_ORDER"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:85:   BLANK();
@ 85 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:86:   DEFINE(S_R0,			offsetof(struct pt_regs, ARM_r0));
@ 86 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R0 #0 offsetof(struct pt_regs, ARM_r0)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:87:   DEFINE(S_R1,			offsetof(struct pt_regs, ARM_r1));
@ 87 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R1 #4 offsetof(struct pt_regs, ARM_r1)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:88:   DEFINE(S_R2,			offsetof(struct pt_regs, ARM_r2));
@ 88 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R2 #8 offsetof(struct pt_regs, ARM_r2)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:89:   DEFINE(S_R3,			offsetof(struct pt_regs, ARM_r3));
@ 89 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R3 #12 offsetof(struct pt_regs, ARM_r3)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:90:   DEFINE(S_R4,			offsetof(struct pt_regs, ARM_r4));
@ 90 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R4 #16 offsetof(struct pt_regs, ARM_r4)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:91:   DEFINE(S_R5,			offsetof(struct pt_regs, ARM_r5));
@ 91 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R5 #20 offsetof(struct pt_regs, ARM_r5)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:92:   DEFINE(S_R6,			offsetof(struct pt_regs, ARM_r6));
@ 92 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R6 #24 offsetof(struct pt_regs, ARM_r6)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:93:   DEFINE(S_R7,			offsetof(struct pt_regs, ARM_r7));
@ 93 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R7 #28 offsetof(struct pt_regs, ARM_r7)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:94:   DEFINE(S_R8,			offsetof(struct pt_regs, ARM_r8));
@ 94 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R8 #32 offsetof(struct pt_regs, ARM_r8)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:95:   DEFINE(S_R9,			offsetof(struct pt_regs, ARM_r9));
@ 95 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R9 #36 offsetof(struct pt_regs, ARM_r9)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:96:   DEFINE(S_R10,			offsetof(struct pt_regs, ARM_r10));
@ 96 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_R10 #40 offsetof(struct pt_regs, ARM_r10)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:97:   DEFINE(S_FP,			offsetof(struct pt_regs, ARM_fp));
@ 97 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_FP #44 offsetof(struct pt_regs, ARM_fp)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:98:   DEFINE(S_IP,			offsetof(struct pt_regs, ARM_ip));
@ 98 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_IP #48 offsetof(struct pt_regs, ARM_ip)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:99:   DEFINE(S_SP,			offsetof(struct pt_regs, ARM_sp));
@ 99 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_SP #52 offsetof(struct pt_regs, ARM_sp)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:100:   DEFINE(S_LR,			offsetof(struct pt_regs, ARM_lr));
@ 100 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_LR #56 offsetof(struct pt_regs, ARM_lr)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:101:   DEFINE(S_PC,			offsetof(struct pt_regs, ARM_pc));
@ 101 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_PC #60 offsetof(struct pt_regs, ARM_pc)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:102:   DEFINE(S_PSR,			offsetof(struct pt_regs, ARM_cpsr));
@ 102 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_PSR #64 offsetof(struct pt_regs, ARM_cpsr)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:103:   DEFINE(S_OLD_R0,		offsetof(struct pt_regs, ARM_ORIG_r0));
@ 103 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->S_OLD_R0 #68 offsetof(struct pt_regs, ARM_ORIG_r0)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:104:   DEFINE(PT_REGS_SIZE,		sizeof(struct pt_regs));
@ 104 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PT_REGS_SIZE #72 sizeof(struct pt_regs)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:105:   DEFINE(SVC_DACR,		offsetof(struct svc_pt_regs, dacr));
@ 105 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SVC_DACR #72 offsetof(struct svc_pt_regs, dacr)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:106:   DEFINE(SVC_ADDR_LIMIT,	offsetof(struct svc_pt_regs, addr_limit));
@ 106 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SVC_ADDR_LIMIT #76 offsetof(struct svc_pt_regs, addr_limit)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:107:   DEFINE(SVC_REGS_SIZE,		sizeof(struct svc_pt_regs));
@ 107 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SVC_REGS_SIZE #80 sizeof(struct svc_pt_regs)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:108:   BLANK();
@ 108 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:109:   DEFINE(SIGFRAME_RC3_OFFSET,	offsetof(struct sigframe, retcode[3]));
@ 109 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SIGFRAME_RC3_OFFSET #756 offsetof(struct sigframe, retcode[3])"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:110:   DEFINE(RT_SIGFRAME_RC3_OFFSET, offsetof(struct rt_sigframe, sig.retcode[3]));
@ 110 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->RT_SIGFRAME_RC3_OFFSET #884 offsetof(struct rt_sigframe, sig.retcode[3])"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:111:   BLANK();
@ 111 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:124:   DEFINE(MM_CONTEXT_ID,		offsetof(struct mm_struct, context.id.counter));
@ 124 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->MM_CONTEXT_ID #376 offsetof(struct mm_struct, context.id.counter)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:125:   BLANK();
@ 125 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:127:   DEFINE(VMA_VM_MM,		offsetof(struct vm_area_struct, vm_mm));
@ 127 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->VMA_VM_MM #32 offsetof(struct vm_area_struct, vm_mm)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:128:   DEFINE(VMA_VM_FLAGS,		offsetof(struct vm_area_struct, vm_flags));
@ 128 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->VMA_VM_FLAGS #40 offsetof(struct vm_area_struct, vm_flags)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:129:   BLANK();
@ 129 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:130:   DEFINE(VM_EXEC,	       	VM_EXEC);
@ 130 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->VM_EXEC #4 VM_EXEC"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:131:   BLANK();
@ 131 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:132:   DEFINE(PAGE_SZ,	       	PAGE_SIZE);
@ 132 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PAGE_SZ #4096 PAGE_SIZE"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:133:   BLANK();
@ 133 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:134:   DEFINE(SYS_ERROR0,		0x9f0000);
@ 134 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SYS_ERROR0 #10420224 0x9f0000"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:135:   BLANK();
@ 135 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:136:   DEFINE(SIZEOF_MACHINE_DESC,	sizeof(struct machine_desc));
@ 136 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SIZEOF_MACHINE_DESC #104 sizeof(struct machine_desc)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:137:   DEFINE(MACHINFO_TYPE,		offsetof(struct machine_desc, nr));
@ 137 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->MACHINFO_TYPE #0 offsetof(struct machine_desc, nr)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:138:   DEFINE(MACHINFO_NAME,		offsetof(struct machine_desc, name));
@ 138 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->MACHINFO_NAME #4 offsetof(struct machine_desc, name)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:139:   BLANK();
@ 139 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:140:   DEFINE(PROC_INFO_SZ,		sizeof(struct proc_info_list));
@ 140 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PROC_INFO_SZ #52 sizeof(struct proc_info_list)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:141:   DEFINE(PROCINFO_INITFUNC,	offsetof(struct proc_info_list, __cpu_flush));
@ 141 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PROCINFO_INITFUNC #16 offsetof(struct proc_info_list, __cpu_flush)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:142:   DEFINE(PROCINFO_MM_MMUFLAGS,	offsetof(struct proc_info_list, __cpu_mm_mmu_flags));
@ 142 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PROCINFO_MM_MMUFLAGS #8 offsetof(struct proc_info_list, __cpu_mm_mmu_flags)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:143:   DEFINE(PROCINFO_IO_MMUFLAGS,	offsetof(struct proc_info_list, __cpu_io_mmu_flags));
@ 143 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->PROCINFO_IO_MMUFLAGS #12 offsetof(struct proc_info_list, __cpu_io_mmu_flags)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:144:   BLANK();
@ 144 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:152:   DEFINE(CPU_SLEEP_SIZE,	offsetof(struct processor, suspend_size));
@ 152 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->CPU_SLEEP_SIZE #40 offsetof(struct processor, suspend_size)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:153:   DEFINE(CPU_DO_SUSPEND,	offsetof(struct processor, do_suspend));
@ 153 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->CPU_DO_SUSPEND #44 offsetof(struct processor, do_suspend)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:154:   DEFINE(CPU_DO_RESUME,		offsetof(struct processor, do_resume));
@ 154 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->CPU_DO_RESUME #48 offsetof(struct processor, do_resume)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:160:   DEFINE(SLEEP_SAVE_SP_SZ,	sizeof(struct sleep_save_sp));
@ 160 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SLEEP_SAVE_SP_SZ #8 sizeof(struct sleep_save_sp)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:161:   DEFINE(SLEEP_SAVE_SP_PHYS,	offsetof(struct sleep_save_sp, save_ptr_stash_phys));
@ 161 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SLEEP_SAVE_SP_PHYS #4 offsetof(struct sleep_save_sp, save_ptr_stash_phys)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:162:   DEFINE(SLEEP_SAVE_SP_VIRT,	offsetof(struct sleep_save_sp, save_ptr_stash));
@ 162 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->SLEEP_SAVE_SP_VIRT #0 offsetof(struct sleep_save_sp, save_ptr_stash)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:164:   DEFINE(ARM_SMCCC_QUIRK_ID_OFFS,	offsetof(struct arm_smccc_quirk, id));
@ 164 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->ARM_SMCCC_QUIRK_ID_OFFS #0 offsetof(struct arm_smccc_quirk, id)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:165:   DEFINE(ARM_SMCCC_QUIRK_STATE_OFFS,	offsetof(struct arm_smccc_quirk, state));
@ 165 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->ARM_SMCCC_QUIRK_STATE_OFFS #4 offsetof(struct arm_smccc_quirk, state)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:166:   BLANK();
@ 166 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:167:   DEFINE(DMA_BIDIRECTIONAL,	DMA_BIDIRECTIONAL);
@ 167 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->DMA_BIDIRECTIONAL #0 DMA_BIDIRECTIONAL"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:168:   DEFINE(DMA_TO_DEVICE,		DMA_TO_DEVICE);
@ 168 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->DMA_TO_DEVICE #1 DMA_TO_DEVICE"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:169:   DEFINE(DMA_FROM_DEVICE,	DMA_FROM_DEVICE);
@ 169 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->DMA_FROM_DEVICE #2 DMA_FROM_DEVICE"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:170:   BLANK();
@ 170 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:171:   DEFINE(CACHE_WRITEBACK_ORDER, __CACHE_WRITEBACK_ORDER);
@ 171 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->CACHE_WRITEBACK_ORDER #6 __CACHE_WRITEBACK_ORDER"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:172:   DEFINE(CACHE_WRITEBACK_GRANULE, __CACHE_WRITEBACK_GRANULE);
@ 172 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->CACHE_WRITEBACK_GRANULE #64 __CACHE_WRITEBACK_GRANULE"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:173:   BLANK();
@ 173 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:181:   BLANK();
@ 181 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:183:   DEFINE(VDSO_DATA_SIZE,	sizeof(union vdso_data_store));
@ 183 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->VDSO_DATA_SIZE #4096 sizeof(union vdso_data_store)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:185:   BLANK();
@ 185 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->"
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:197:   DEFINE(KEXEC_START_ADDR,	offsetof(struct kexec_relocate_data, kexec_start_address));
@ 197 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->KEXEC_START_ADDR #0 offsetof(struct kexec_relocate_data, kexec_start_address)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:198:   DEFINE(KEXEC_INDIR_PAGE,	offsetof(struct kexec_relocate_data, kexec_indirection_page));
@ 198 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->KEXEC_INDIR_PAGE #4 offsetof(struct kexec_relocate_data, kexec_indirection_page)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:199:   DEFINE(KEXEC_MACH_TYPE,	offsetof(struct kexec_relocate_data, kexec_mach_type));
@ 199 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->KEXEC_MACH_TYPE #8 offsetof(struct kexec_relocate_data, kexec_mach_type)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:200:   DEFINE(KEXEC_R2,		offsetof(struct kexec_relocate_data, kexec_r2));
@ 200 "/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c" 1
	
.ascii "->KEXEC_R2 #12 offsetof(struct kexec_relocate_data, kexec_r2)"	@
@ 0 "" 2
@ /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/arch/arm/kernel/asm-offsets.c:202: }
	.arm
	.syntax unified
	mov	r0, #0	@,
	bx	lr	@
	.fnend
	.size	main, .-main
	.ident	"GCC: (GNU) 9.5.0"
	.section	.note.GNU-stack,"",%progbits
