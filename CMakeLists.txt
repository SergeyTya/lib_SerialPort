
cmake_minimum_required(VERSION 3.19)
add_library( lib_SerialPort STATIC
iSerialPort.h
iSerialPort.cpp
win_port.h
win_port.cpp
)

#USE interface to unclude lib path at project target
target_include_directories(lib_SerialPort
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
          
install(TARGETS lib_SerialPort DESTINATION .)
