QT +=             \
  widgets         \
  gui             \
  charts          \
  serialbus       \
  serialport      

requires(qtConfig(filedialog))

QMAKE_CXXFLAGS +=                  \
  -std=c++2b                       \
  -Wno-deprecated-copy             \
  -Wno-deprecated-enum-enum-conversion \
  -I/usr/local/include

TARGET = GasFlow

CONFIG += static

HEADERS +=  \
  $$PWD/src/*.h   

HEADERS +=                                \
    3rdparty/modbus/modbus.h              \
    3rdparty/modbus/modbus-private.h      \
    3rdparty/modbus/modbus-rtu.h          \
    3rdparty/modbus/modbus-rtu-private.h  \
    3rdparty/modbus/modbus-tcp.h          \
    3rdparty/modbus/modbus-tcp-private.h  \
    3rdparty/modbus/modbus-version.h

SOURCES +=  \
  $$PWD/src/*.cpp 

SOURCES +=                          \
    3rdparty/modbus/modbus.c        \
    3rdparty/modbus/modbus-data.c   \
    3rdparty/modbus/modbus-rtu.c    \
    3rdparty/modbus/modbus-tcp.c

FORMS +=                     \
  $$PWD/ui/*.ui              \
  $$PWD/ui/components/*.ui 

RESOURCES += images.qrc

target.path = $$PWD/install

INSTALLS += target
