**#In Linux**  
  - type below comamnds to install woori-net SDK for SDX65  
  
  ```
  sudo apt-get install git cmake build-essential python
  git clone https://github.com/wooriNet/sdx62.git
  cd sdx65
  ```

**#Setup SDK**  
  - type below commands  
  
  ```
  chmod 755 sdk_install.sh
  sudo ./sdk_install.sh
  ```

**#How to build test application**  

  ```
  mkdir testArmApp
  cd testArmApp
  vi main.c
  ```
  `main.c`
```
#include <stdio.h>
int main(void)
{
  printf("Hello ARM World!" "\n");
  return 0;
}
```

```
vi CMakeLists.txt
```
`CMakeLists.txt`
```
INCLUDE(CMakeForceCompiler)

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)
SET(CMAKE_SYSTEM_PROCESSOR arm)

PROJECT(hello)
cmake_minimum_required(VERSION 2.8.0)

#<SDKPATH> is sdk installed path.
SET(SDKPATH /home/xxxxx/sdx65)
SET(SC_ROOT ${SDKPATH}/sysroots/armv7vet2hf-neon-oe-linux-gnueabi)
SET(SC_GNUEABI ${SDKPATH}/sysroots/x86_64-pokysdk-linux/usr/bin/arm-oe-linux-gnueabi)

SET(CMAKE_C_COMPILER ${SC_GNUEABI}/arm-oe-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER ${SC_GNUEABI}/arm-oe-linux-gnueabi-g++)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfloat-abi=hard -mfpu=neon --sysroot=${SC_ROOT}" CACHE INTERNAL "" FORCE)
SET(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} --sysroot=${SC_ROOT}" CACHE INTERNAL "" FORCE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard -mfpu=neon --sysroot=${SC_ROOT}" CACHE INTERNAL "" FORCE)
SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} --sysroot=${SC_ROOT}" CACHE INTERNAL "" FORCE)

set (source_files main.c)

add_executable(testApp ${source_files})

add_compile_options (-g -Wall)

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
```
```
  cmake .
  make 
```

