# toolchain-arm.cmake
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm)

# Percorsi del compilatore
SET(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
SET(CMAKE_AR arm-linux-gnueabihf-ar)
SET(CMAKE_LINKER arm-linux-gnueabihf-ld)

# Impostiamo i flag di compilazione per ARM
SET(CMAKE_C_FLAGS "-march=armv7-a -mfpu=neon -O2 -fPIC")
SET(CMAKE_CXX_FLAGS "-march=armv7-a -mfpu=neon -O2 -fPIC")
SET(CMAKE_EXE_LINKER_FLAGS "-march=armv7-a -mfpu=neon -O2 -fPIC")