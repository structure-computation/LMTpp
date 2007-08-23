/* *
                          alt_unit.h  -  description
                             -------------------
    begin                : mar sep 10 2002
    copyright            : (C) 2002 by hleclerc
    email                : hleclerc@lmamef23
 ***************************************************************************/

/* *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef UNITS_H
#define UNITS_H

#include <map>
#include <vector>
#include <string>

namespace LMT {

class XmlNode;

class Units {
public:
  ///
  Units(const char *text);
  ///
  void parseXml(const XmlNode &n);
  ///
  double getCoeff(const std::string &coeff,const std::string &unit_system="SI") const;
private:
  ///
  struct Prefix {
    std::string name;
    int val;
  };
  ///
  struct Unit {
    double scale;
    unsigned num_group;
  };
  ///
  typedef std::map<std::string,std::map<std::string,Unit> > Tdata;
  /// for not composed units
  double get_coeff_simple(const std::string &coeff,Tdata::const_iterator iter) const;
  /// data["unit system"]["name fondamental unit"] ->
  Tdata data;
  /// unit_systems["unit system"]["name fondamental unit"] ->
  std::map<std::string,std::vector<std::string> > unit_systems;
  /// name, exponent
  std::vector<Prefix> prefixes;
  ///
  std::vector<std::string> group_names;
};

extern Units units;

};

#endif // UNITS_H
