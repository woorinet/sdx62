cmd_scripts/selinux/mdp/mdp := gcc  -isystem/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/include -O2 -pipe -L/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/lib                         -L/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/lib                         -Wl,--enable-new-dtags                         -Wl,-rpath-link,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/lib                         -Wl,-rpath-link,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/lib                         -Wl,-rpath,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/usr/lib                         -Wl,-rpath,/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work/sdxlemur-oe-linux-gnueabi/make-mod-scripts/1.0-r0/recipe-sysroot-native/lib                         -Wl,-O1 -Wl,--allow-shlib-undefined -Wl,--dynamic-linker=/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/sysroots-uninative/x86_64-linux/lib/ld-linux-x86-64.so.2 -Wp,-MD,scripts/selinux/mdp/.mdp.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer -std=gnu89     -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include -I/home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/security/selinux/include -I./include  -I ./scripts/selinux/mdp   -o scripts/selinux/mdp/mdp /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/selinux/mdp/mdp.c   

source_scripts/selinux/mdp/mdp := /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/scripts/selinux/mdp/mdp.c

deps_scripts/selinux/mdp/mdp := \
    $(wildcard include/config/ext2/fs/security.h) \
    $(wildcard include/config/ext4/fs/security.h) \
    $(wildcard include/config/ext4/use/for/ext2.h) \
    $(wildcard include/config/jfs/security.h) \
    $(wildcard include/config/reiserfs/fs/security.h) \
    $(wildcard include/config/jffs2/fs/security.h) \
    $(wildcard include/config/xfs/fs.h) \
    $(wildcard include/config/gfs2/fs.h) \
    $(wildcard include/config/btrfs/fs.h) \
    $(wildcard include/config/f2fs/fs/security.h) \
    $(wildcard include/config/ocfs2/fs.h) \
    $(wildcard include/config/overlay/fs.h) \
    $(wildcard include/config/squashfs/xattr.h) \
    $(wildcard include/config/unix98/ptys.h) \
    $(wildcard include/config/hugetlbfs.h) \
    $(wildcard include/config/tmpfs.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/security/selinux.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/debug/fs.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/pstore.h) \
  /usr/include/stdc-predef.h \
  /usr/include/stdio.h \
  /usr/include/features.h \
  /usr/include/x86_64-linux-gnu/sys/cdefs.h \
  /usr/include/x86_64-linux-gnu/bits/wordsize.h \
  /usr/include/x86_64-linux-gnu/gnu/stubs.h \
  /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
  /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h \
  /usr/include/x86_64-linux-gnu/bits/types.h \
  /usr/include/x86_64-linux-gnu/bits/typesizes.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
  /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
  /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
  /usr/include/x86_64-linux-gnu/bits/stdio.h \
  /usr/include/x86_64-linux-gnu/bits/stdio2.h \
  /usr/include/stdlib.h \
  /usr/include/x86_64-linux-gnu/bits/waitflags.h \
  /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
  /usr/include/endian.h \
  /usr/include/x86_64-linux-gnu/bits/endian.h \
  /usr/include/x86_64-linux-gnu/bits/byteswap.h \
  /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
  /usr/include/x86_64-linux-gnu/sys/types.h \
  /usr/include/time.h \
  /usr/include/x86_64-linux-gnu/sys/select.h \
  /usr/include/x86_64-linux-gnu/bits/select.h \
  /usr/include/x86_64-linux-gnu/bits/sigset.h \
  /usr/include/x86_64-linux-gnu/bits/time.h \
  /usr/include/x86_64-linux-gnu/bits/select2.h \
  /usr/include/x86_64-linux-gnu/sys/sysmacros.h \
  /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /usr/include/x86_64-linux-gnu/bits/stdlib-bsearch.h \
  /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
  /usr/include/x86_64-linux-gnu/bits/stdlib.h \
  /usr/include/unistd.h \
  /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
  /usr/include/x86_64-linux-gnu/bits/environments.h \
  /usr/include/x86_64-linux-gnu/bits/confname.h \
  /usr/include/getopt.h \
  /usr/include/x86_64-linux-gnu/bits/unistd.h \
  /usr/include/string.h \
  /usr/include/xlocale.h \
  /usr/include/x86_64-linux-gnu/bits/string.h \
  /usr/include/x86_64-linux-gnu/bits/string2.h \
  /usr/include/x86_64-linux-gnu/bits/string3.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/security/selinux/include/classmap.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/capability.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/types.h \
  /usr/include/x86_64-linux-gnu/asm/types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/int-ll64.h \
  /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/posix_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/stddef.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/cc/has/asm/inline.h) \
  /usr/include/x86_64-linux-gnu/asm/posix_types.h \
  /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/asm-generic/posix_types.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/include/uapi/linux/socket.h \
  /home/pkang/sdx62/apps_proc/build-qti-distro-nogplv3-perf/tmp-glibc/work-shared/sdxlemur/kernel-source/security/selinux/include/initial_sid_to_string.h \

scripts/selinux/mdp/mdp: $(deps_scripts/selinux/mdp/mdp)

$(deps_scripts/selinux/mdp/mdp):
