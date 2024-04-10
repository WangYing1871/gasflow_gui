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
  -Wno-deprecated-enum-enum-conversion

LIBS +=               \
  -lmodbus            \
  -lboost_system      \
  -lboost_filesystem  \
  -lboost_atomic      

CONFIG += \
  static  

HEADERS +=  \
  $$PWD/src/*.h   

SOURCES +=  \
  $$PWD/src/*.cpp 

FORMS +=                     \
  $$PWD/ui/*.ui              \
  $$PWD/ui/components/*.ui 
                       
TARGET = GasFlow       

target.path = $$PWD/install

INSTALLS += \
  target
