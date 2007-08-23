//
// C++ Interface: codegen_vector
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo_lec@club-internet.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <vector>

namespace Codegen {

/// an extensible vector with static data at beginning...
template<class T,unsigned nb_fixed_size=2>
class Cvector {
public:
  ///
  Cvector():s(0) {}
  ///
  void push_back(T data) {
    if ( s == nb_fixed_size )
      stl_vec.push_back(data);
    else
      stat_vec[s++] = data;
  }
  ///
  bool erase_first(const T &val) {
    for(unsigned i=0;i<s;++i) {
      if ( stat_vec[i] == val ) {
        erase(i);
        return true;
      }
    }
    for(unsigned i=0;i<stl_vec.size();++i) {
      if ( stl_vec[i] == val ) {
        stl_vec.erase( stl_vec.begin()+i );
        return true;
      }
    }
    return false;
  }
  ///
  void erase(unsigned i) {
    using namespace std;
    if ( i < nb_fixed_size ) {
      for(unsigned j=i+1;j<s;++j)
        stat_vec[j-1] = stat_vec[j];
      if ( stl_vec.size() ) {
        stat_vec[nb_fixed_size-1] = stl_vec[0];
        stl_vec.erase(stl_vec.begin());
      }
      else
        --s;
    }
    else {
      stl_vec.erase( stl_vec.begin()+i-nb_fixed_size );
    }
  }
  ///
  void clear(unsigned i) {
    stl_vec.clear();
    s = 0;
  }
  ///
  T &operator[](unsigned i) {
    if ( i < nb_fixed_size )
      return stat_vec[i];
    return stl_vec[i-nb_fixed_size];
  }
  ///
  const T &operator[](unsigned i) const {
    if ( i < nb_fixed_size )
      return stat_vec[i];
    return stl_vec[i-nb_fixed_size];
  }
  ///
  unsigned size() const { return s+stl_vec.size(); }
  ///
  bool operator==(const Cvector &cv) const {
    if ( size()!=cv.size() )
      return false;
    for(unsigned i=0;i<nb_fixed_size;++i)
      if (stat_vec[i]!=cv.stat_vec[i])
        return false;
    for(unsigned i=0;i<stl_vec.size();++i)
      if (stl_vec[i]!=cv.stl_vec[i])
        return false;
    return true;
  }
  bool find(const T &val) {
    for(unsigned i=0;i<size();++i)
        if ( operator[](i) == val )
            return true;
    return false;
  }
private:
  unsigned s;
  T stat_vec[ nb_fixed_size ];
  std::vector<T> stl_vec;
};

}
