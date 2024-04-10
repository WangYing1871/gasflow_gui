#include "util.h"

namespace util{
std::string rename(std::string const& name){
  if (name.length()<=1) return name;
  char c = name.back();
  if(c=='_' || c=='-') return name+"_0";
  if (!std::isdigit(c)) return name+"0";
  return name.substr(0,name.length()-1)+std::string{(char)(c+1)}; }

}
