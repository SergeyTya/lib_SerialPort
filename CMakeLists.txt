
add_library( serialport SHARED
iSerialPort.h
iSerialPort.cpp
win_port.h
win_port.cpp
)

#USE interface to unclude lib path at project target
target_include_directories(serialport
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
          
install(TARGETS serialport DESTINATION .)
