#ifndef util_H
#define util_H 1 
#include <string>
namespace util{

std::string rename(std::string const&);

struct modbus_parameters_t{
  int baud = 19200;
  char parity = 'N';
  int data_bit = 8;
  int stop_bit = 2; };
}
#endif
