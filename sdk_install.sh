#!/bin/bash
INST_ARCH=$(uname -m | sed -e "s/i[3-6]86/ix86/" -e "s/x86[-_]64/x86_64/")
SDK_ARCH=$(echo x86_64 | sed -e "s/i[3-6]86/ix86/" -e "s/x86[-_]64/x86_64/")

verlte () {
	[  "$1" = "`printf "$1\n$2" | sort -V | head -n1`" ]
}

verlt() {
	[ "$1" = "$2" ] && return 1 || verlte $1 $2
}

verlt `uname -r` 3.2
if [ $? = 0 ]; then
	echo "Error: The SDK needs a kernel > 3.2"
	exit 1
fi

if [ "$INST_ARCH" != "$SDK_ARCH" ]; then
	# Allow for installation of ix86 SDK on x86_64 host
	if [ "$INST_ARCH" != x86_64 -o "$SDK_ARCH" != ix86 ]; then
		echo "Error: Installation machine not supported!"
		exit 1
	fi
fi

NATIVE_LIB_INSTALL_DIR="/opt/sdx65/apps_proc/build-qti-distro-nogplv3-debug/tmp-glibc/"
NATIVE_LIB_LINK_NAME="sysroots-uninative"

target_sdk_dir=$(pwd)

titlestr="sdx SDK installer version nodistro.0"
printf "%s\n" "$titlestr"
printf "%${#titlestr}s\n" | tr " " "="

if [ -n "$(echo $target_sdk_dir|grep ' ')" ]; then
	echo "The target directory path ($target_sdk_dir) contains spaces. Abort!"
	exit 1
fi

SUDO_EXEC=$(which "sudo")
if [ -z $SUDO_EXEC ]; then
	echo "No command 'sudo' found, please install sudo first. Abort!"
	exit 1
fi

# test sudo could gain root right
$SUDO_EXEC pwd >/dev/null 2>&1
[ $? -ne 0 ] && echo "Sorry, you are not allowed to execute as root." && exit 1

printf "Setting it up..."

# now that we have sudo rights, create the directory
if [ ! -d $NATIVE_LIB_INSTALL_DIR ]
then
	$SUDO_EXEC mkdir -p $NATIVE_LIB_INSTALL_DIR >/dev/null 2>&1
else
	$SUDO_EXEC rm -rf $NATIVE_LIB_INSTALL_DIR/* >/dev/null 2>&1
fi

env_setup_script="environment-setup.sh"
$SUDO_EXEC sed -e "s:/home/pkang/sdk/sdx65:$target_sdk_dir:g" -i $env_setup_script

# create link for sysroots-uninative directory with sudo rights
$SUDO_EXEC ln -s $target_sdk_dir/$NATIVE_LIB_LINK_NAME $NATIVE_LIB_INSTALL_DIR/$NATIVE_LIB_LINK_NAME >/dev/null 2>&1

echo "done"

echo "SDK has been successfully set up and is ready to be used."

