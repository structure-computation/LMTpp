//
// C++ Interface: ioexception
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_ioexception_HEADER
#define LMT_ioexception_HEADER

#include <string>

namespace LMT {

class IoException {
public:
  IoException(const std::string &s,unsigned ll=0):msg(s),l(ll) {}
  virtual ~IoException() {}
  std::string what() const { return msg; }
  unsigned line() const { return l; }
  virtual std::string type() const { return "IO"; }
  std::string msg;
  unsigned l;
};


};

#endif // LMT_ioexception_HEADER
