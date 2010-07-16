#include "units.h"
#include "xmlnode.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
namespace LMT {

///
Units::Units(const char *text) {
  XmlNode xn;
  xn.parse_text(text);
  parseXml(xn);
}

void Units::parseXml(const XmlNode &n) {
 try {

  // syst
  unsigned nb_syst = n.nb_elements("syst");
  for(unsigned i=0;i<nb_syst;++i) {
    XmlNode ns( n.get_element("syst",i) );
    vector<string> &vec = unit_systems[ ns.get_attribute("id") ];
    unsigned nb_fond_units = ns.nb_elements("use");
    for(unsigned j=0;j<nb_fond_units;++j)
      vec.push_back( ns.get_element("use",j).get_attribute("unit_id") );
  }
  // prefixes
  unsigned nb_prefixes = n.nb_elements("prefix");
  for(unsigned i=0;i<nb_prefixes;++i) {
    XmlNode ns( n.get_element("prefix",i) );
    Prefix p;
    p.name = ns.get_attribute("name");
    ns.get_attribute("exponent",p.val);
    prefixes.push_back( p );
  }
  // units
  unsigned nb_groups = n.nb_elements("group");
  for(unsigned num_group=0;num_group<nb_groups;++num_group) {
    vector<pair<string,Unit> > group_data;
    // group
    XmlNode ng( n.get_element("group",num_group) );
    group_names.push_back( ng.get_attribute("id") );
    double scales_ref_group = 1.0;
    if (ng.has_attribute("equivalence"))
      scales_ref_group = getCoeff( ng.get_attribute("equivalence") );
    unsigned nb_units = ng.nb_elements("unit");
    for(unsigned num_unit=0;num_unit<nb_units;++num_unit) {
      // unit
      XmlNode nu( ng.get_element("unit",num_unit) );
      Unit unit;
      nu.get_attribute("scale",unit.scale);
      unit.scale /= scales_ref_group;
      unit.num_group = num_group;
      string name_unit = nu.get_attribute("id");
      group_data.push_back( make_pair( name_unit , unit ) );
      bool noprefix = nu.has_attribute("noprefix") && nu.get_attribute("noprefix")=="true";
      if ( noprefix )
        continue;
      for(vector<Prefix>::const_iterator itp=prefixes.begin();itp!=prefixes.end();++itp) {
        Unit u;
        u.scale = unit.scale * std::pow( 10.0, itp->val );
        u.num_group = num_group;
        group_data.push_back( make_pair( itp->name + name_unit, u ) );
      }
    }
    // exploitation of group_data
    for(map<string,vector<string> >::const_iterator itsy=unit_systems.begin();itsy!=unit_systems.end();++itsy) {
      const vector<string> &ss( itsy->second );
      double scales_ref = 1.0;
      for (vector<pair<string,Unit> >::const_iterator iter=group_data.begin();iter!=group_data.end();++iter) {
        if ( find(ss.begin(),ss.end(),iter->first) != ss.end() ) {
          scales_ref = iter->second.scale;
          break;
        }
      }
      map<string,Unit> &d( data[itsy->first] );
      for (vector<pair<string,Unit> >::const_iterator iter=group_data.begin();iter!=group_data.end();++iter) {
        d[ iter->first ] = iter->second;
        d[ iter->first ].scale /= scales_ref;
      }
    }
  }
  
 } catch (const IoException &e) { cerr << e.what() << endl; }
}

///
double Units::getCoeff(const string &coeff,const string &unit_system) const {
    // syst
    Tdata::const_iterator iter;
    iter = data.find( unit_system );
    if (iter==data.end())
      return -1;
    // name
    char *n = strdup(coeff.c_str());
    int expo = 1;
    double res = 1.0;
    char *pos;
    for(pos=n;*pos;++pos);
    for(;pos>=n;--pos) {
      if (*pos=='/') {
        res /= std::pow( get_coeff_simple(pos+1,iter), expo);
        *pos = 0;
        expo = 1;
      }
      else if (*pos=='*') {
        res *= std::pow( get_coeff_simple(pos+1,iter), expo);
        *pos = 0;
        expo = 1;
      }
      else if (*pos=='^') {
        expo = atoi(pos+1);
        *pos = 0;
      }
    }
    res *= std::pow( get_coeff_simple(n,iter), expo);
    free(n);
    return res;
}

///
double Units::get_coeff_simple(const string &coeff,Tdata::const_iterator iter) const {
  map<string,Unit>::const_iterator res = iter->second.find(coeff);
  if (res==iter->second.end())
    return -1;
  return res->second.scale;
}

// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------
// <?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>
//<!--Unit configuration file v1.0 - from \"citrus\" project (http://citrus.sourceforge.net/)
//    And modified by LECLERC Hugo to be used in Lib_fem.
//  Reference:
//    Avallone, Eugene A. and Theodore Baumeister III, Marks' Standard
//    Handbook for Mechanical Engineers, 9th ed., McGraw-Hill, NY, 1987
//  -->
static const char *unit_data = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>           \n"
"<units>                                                                                \n"
"  <prefix exponent=\"24\" name=\"Y\"/>                                                 \n"
"  <prefix exponent=\"21\" name=\"Z\"/>                                                 \n"
"  <prefix exponent=\"18\" name=\"E\"/>                                                 \n"
"  <prefix exponent=\"15\" name=\"P\"/>                                                 \n"
"  <prefix exponent=\"12\" name=\"T\"/>                                                 \n"
"  <prefix exponent=\"9\" name=\"G\"/>                                                  \n"
"  <prefix exponent=\"6\" name=\"M\"/>                                                  \n"
"  <prefix exponent=\"3\" name=\"k\"/>                                                  \n"
"  <prefix exponent=\"2\" name=\"h\"/>                                                  \n"
"  <prefix exponent=\"1\" name=\"da\"/>                                                 \n"
"  <prefix exponent=\"-1\" name=\"d\"/>                                                 \n"
"  <prefix exponent=\"-2\" name=\"c\"/>                                                 \n"
"  <prefix exponent=\"-3\" name=\"m\"/>                                                 \n"
"  <prefix exponent=\"-6\" name=\"u\"/>                                                 \n"
"  <prefix exponent=\"-6\" name=\"u\"/>                                                 \n"
"  <prefix exponent=\"-9\" name=\"n\"/>                                                 \n"
"  <prefix exponent=\"-12\" name=\"p\"/>                                                \n"
"  <prefix exponent=\"-15\" name=\"f\"/>                                                \n"
"  <prefix exponent=\"-18\" name=\"a\"/>                                                \n"
"  <prefix exponent=\"-21\" name=\"z\"/>                                                \n"
"  <prefix exponent=\"-24\" name=\"y\"/>                                                \n"
"                                                                                       \n"
"  <syst id=\"SI\">                                                                     \n"
"    <use unit_id=\"1\"/>                                                               \n"
"    <use unit_id=\"m\"/>                                                               \n"
"    <use unit_id=\"kg\"/>                                                              \n"
"    <use unit_id=\"s\"/>                                                               \n"
"    <use unit_id=\"K\"/>                                                               \n"
"    <use unit_id=\"euro\"/>                                                            \n"
"    <use unit_id=\"B\"/>                                                               \n"
"    <use unit_id=\"rad\"/>                                                             \n"
"    <use unit_id=\"st\"/>                                                              \n"
"  </syst>                                                                              \n"
"                                                                                       \n"
"  <syst id=\"uSI\">                                                                    \n"
"    <use unit_id=\"1\"/>                                                               \n"
"    <use unit_id=\"um\"/>                                                              \n"
"    <use unit_id=\"mg\"/>                                                              \n"
"    <use unit_id=\"us\"/>                                                              \n"
"    <use unit_id=\"K\"/>                                                               \n"
"    <use unit_id=\"euro\"/>                                                            \n"
"    <use unit_id=\"B\"/>                                                               \n"
"    <use unit_id=\"rad\"/>                                                             \n"
"    <use unit_id=\"st\"/>                                                              \n"
"  </syst>                                                                              \n"
"                                                                                       \n"
"  <group id=\"dimensionless\">                                                         \n"
"    <unit id=\"none\" scale=\"1\" name=\"none\" noprefix=\"true\"/>                    \n"
"    <unit id=\"1\" scale=\"1\" name=\"none\"/>                                         \n"
"    <unit id=\"\" scale=\"1\" name=\"none\" noprefix=\"true\"/>                        \n"
"    <unit id=\"%\" scale=\"0.01\" name=\"percent\" noprefix=\"true\"/>                 \n"
"    <unit id=\"percent\" scale=\"0.01\" name=\"percent\" noprefix=\"true\"/>           \n"
"    <unit id=\"mol\" scale=\"6.02214e23\" name=\"mole\"/>           \n"
"  </group>                                                                             \n"
"  <group id=\"mass\">                                                                  \n"
"    <unit id=\"g\" scale=\"0.001\" name=\"gramm\"/>                                    \n"
"    <unit id=\"t\" scale=\"1000\" name=\"metric ton\"/>                                \n"
"    <unit id=\"slug\" scale=\"14.5939029372\" name=\"slug\"/>                          \n"
"    <unit id=\"lbm\" scale=\"0.45359237\" name=\"pound mass\" plur_name=\"pounds mass\"/> \n"
"    <unit id=\"oz.\" scale=\"0.02834952313\" name=\"ounce\" noprefix=\"true\"/>        \n"
"  </group>                                                                             \n"
"  <group id=\"angle\">                                                                 \n"
"    <unit id=\"rad\" scale=\"1\" name=\"radian\"/>                                     \n"
"    <unit id=\"deg\" scale=\"0.0174532925199432954743716805978692718781530857086181640625\" name=\"degree\"/> \n"
"    <unit id=\"'\" scale=\"1.04719755119\" name=\"angle-minute\" noprefix=\"true\"/>   \n"
"    <unit id=\"&quot;\" scale=\"62.8318503714\" name=\"angle-second\" noprefix=\"true\"/> \n"
"  </group>                                                                             \n"
"  <group id=\"information\">                                                           \n"
"    <unit id=\"b\" scale=\"1\" name=\"bit\" noprefix=\"true\"/>                        \n"
"    <unit id=\"B\" scale=\"8\" name=\"byte\" noprefix=\"true\"/>                       \n"
"    <unit id=\"kB\" scale=\"8192\" name=\"kilobyte\" noprefix=\"true\"/>               \n"
"    <unit id=\"MB\" scale=\"8388608\" name=\"megabyte\" noprefix=\"true\"/>            \n"
"    <unit id=\"GB\" scale=\"8589934592\" name=\"gigabyte\" noprefix=\"true\"/>         \n"
"    <unit id=\"TB\" scale=\"8796093022208\" name=\"terabyte\" noprefix=\"true\"/>      \n"
"  </group>                                                                             \n"
"  <group id=\"money\">                                                                 \n"
"    <unit id=\"euro\" scale=\"1\" name=\"euro\"/>                                      \n"
"    <unit id=\"Fr\" scale=\"6.55957\" name=\"franc\"/>                                 \n"
"  </group>                                                                             \n"
"  <group id=\"time\">                                                                  \n"
"    <unit id=\"s\" scale=\"1\" name=\"second\"/>                                       \n"
"    <unit id=\"mn\" scale=\"60\" name=\"minute\" noprefix=\"true\"/>                   \n"
"    <unit id=\"hr\" scale=\"3600\" name=\"hour\" noprefix=\"true\"/>                   \n"
"    <unit id=\"day\" scale=\"86400\" name=\"day\" noprefix=\"true\"/>                  \n"
"    <unit id=\"week\" scale=\"604800\" name=\"week\" noprefix=\"true\"/>               \n"
"    <unit id=\"yr\" scale=\"31556925.9747\" name=\"year\" noprefix=\"true\"/>          \n"
"    <unit id=\"fort\" scale=\"1209600\" name=\"fortnight\" noprefix=\"true\"/>         \n"
"  </group>                                                                             \n"
"  <group id=\"temperature\">                                                           \n"
"    <unit id=\"K\" scale=\"1\" name=\"Kelvin\"/>                                       \n"
"    <unit id=\"K\" scale=\"1\" name=\"Kelvin\"/>                                      \n"
"    <unit id=\"degK\" scale=\"1\" name=\"Kelvin\"/>                                    \n"
"    <unit id=\"C\" scale=\"1\" offset=\"274.15\" name=\"Celsius\"/>                   \n"
"    <unit id=\"degC\" scale=\"1\" offset=\"274.15\" name=\"Celsius\"/>                 \n"
"    <unit id=\"R\" scale=\"0.555555555555555555555555555555555556\" name=\"Rankine\"/> \n"
"    <unit id=\"degR\" scale=\"0.555555555555555555555555555555555556\" name=\"Rankine\"/> \n"
"    <unit id=\"F\" scale=\"0.555555555555555555555555555555555556\" offset=\"460.67\" name=\"Fahrenheight\"/> \n"
"    <unit id=\"degF\" scale=\"0.555555555555555555555555555555555556\" offset=\"460.67\" name=\"Fahrenheight\"/> \n"
"  </group>                                                                             \n"
"  <group id=\"length\">                                                                \n"
"    <unit id=\"m\" scale=\"1\" name=\"meter\"/>                                        \n"
"    <unit id=\"Am\" scale=\"10e-10\" name=\"angstrom\" noprefix=\"true\"/>              \n"
"    <unit id=\"mi.\" scale=\"1609.344\" name=\"mile\"/>                                \n"
"    <unit id=\"mil\" scale=\"2.54e-05\" name=\"mil\"/>                                 \n"
"    <unit id=\"yd.\" scale=\"0.9144\" name=\"yard\"/>                                  \n"
"    <unit id=\"ft.\" scale=\"0.3048\" name=\"foot\" plur_name=\"feet\"/>               \n"
"    <unit id=\"in.\" scale=\"0.0254\" name=\"inch\" plur_name=\"inches\"/>             \n"
"    <unit id=\"cubit\" scale=\"0.4572\" name=\"bit\"/>                                 \n"
"    <unit id=\"furlong\" scale=\"5.588\" name=\"furlong\"/>                            \n"
"    <unit id=\"fathom\" scale=\"1.8288\" name=\"thom\"/>                               \n"
"  </group>                                                                             \n"
"  <group id=\"solid_angle\">                                                           \n"
"    <unit id=\"st\" scale=\"1\" name=\"steradian\"/>                                   \n"
"  </group>                                                                             \n"
"  <!-- non fondamental units -->                                                       \n"
"  <group id=\"energy\" equivalence=\"kg*m^2/s^2\">                                     \n"
"    <unit id=\"J\" scale=\"1\" name=\"Joule\"/>                                        \n"
"    <unit id=\"eV\" scale=\"160.2176462e-21\" name=\"electron volt\"/>                 \n"
"    <unit id=\"erg\" scale=\"1e-5\" name=\"erg\"/>                                     \n"
"    <unit id=\"Btu\" scale=\"1055.05585262\" name=\"British thermal unit\"/>           \n"
"  </group>                                                                             \n"
"  <group id=\"current\" equivalence=\"eV/s/m\">                                        \n"
"    <unit id=\"A\" scale=\"1\" name=\"ampere\"/>                                       \n"
"  </group>                                                                             \n"
"  <group id=\"electric_potential\" equivalence=\"kg*m^2/s^3/A\">                       \n"
"    <unit id=\"V\" scale=\"1\" name=\"volt\"/>                                         \n"
"  </group>                                                                             \n"
"  <group id=\"entropy\" equivalence=\"kg*m^2/s^2/K\">                                  \n"
"    <unit id=\"clausius\" scale=\"4186.8\" name=\"clausius\"/>                         \n"
"  </group>                                                                             \n"
"  <group id=\"luminous_intensity\" equivalence=\"J/s/m^2\">                            \n"
"    <unit id=\"candela\" scale=\"1\" name=\"candela\"/>                                \n"
"  </group>                                                                             \n"
"  <group id=\"luminous_flux\" equivalence=\"candela*st\">                              \n"
"    <unit id=\"lm\" scale=\"0.0795774715459\" name=\"lumen\"/>                         \n"
"  </group>                                                                             \n"
"  <group id=\"magnetic_flux_density\" equivalence=\"kg/s^2/A\">                        \n"
"    <unit id=\"T\" scale=\"1\" name=\"Tesla\"/>                                        \n"
"    <unit id=\"G\" scale=\"1e-4\" name=\"gauss\"/>                                     \n"
"  </group>                                                                             \n"
"  <group id=\"magnetic_flux\" equivalence=\"kg*m^2/s^2/A\">                            \n"
"    <unit id=\"Wb\" scale=\"1\" name=\"Weber\"/>                                       \n"
"  </group>                                                                             \n"
"  <group id=\"magnetic_inductance\" equivalence=\"kg*m^2/s^2/A^2\">                    \n"
"    <unit id=\"H\" scale=\"1\" name=\"Henry\"/>                                        \n"
"  </group>                                                                             \n"
"  <group id=\"capacitance\" equivalence=\"s^2/kg/m^2\">                                \n"
"    <unit id=\"F\" scale=\"1\" name=\"Farad\"/>                                        \n"
"  </group>                                                                             \n"
"  <group id=\"electric_conductance\" equivalence=\"s^3*A^2/kg/m^2\">                   \n"
"    <unit id=\"S\" scale=\"1\" name=\"siemen\"/>                                       \n"
"  </group>                                                                             \n"
"  <group id=\"electric_resistance\" equivalence=\"kg*m^2/s^3/A^2\">                    \n"
"    <unit id=\"ohm\" scale=\"1\" name=\"ohm\"/>                                        \n"
"  </group>                                                                             \n"
"  <group id=\"electric_charge\" equivalence=\"A*s\">                                   \n"
"    <unit id=\"C\" scale=\"1\" name=\"Coloumb\"/>                                      \n"
"  </group>                                                                             \n"
"  <group id=\"information_rate\" equivalence=\"b/s\">                                  \n"
"    <unit id=\"baud\" scale=\"1\" name=\"baud\"/>                                      \n"
"  </group>                                                                             \n"
"  <group id=\"kinematic_viscosity\" equivalence=\"m^2/s\">                             \n"
"    <unit id=\"St\" scale=\"0.0001\" name=\"Stoke\"/>                                  \n"
"  </group>                                                                             \n"
"  <group id=\"absolute_viscosity\" equivalence=\"kg/m/s\">                             \n"
"    <unit id=\"P\" scale=\"10\" name=\"poise\"/>                                       \n"
"    <unit id=\"reyn\" scale=\"10\" name=\"reynold\"/>                                  \n"
"  </group>                                                                             \n"
"  <group id=\"power\" equivalence=\"kg*m^2/s^3\">                                      \n"
"    <unit id=\"W\" scale=\"1\" name=\"Watt\"/>                                         \n"
"    <unit id=\"hp\" scale=\"745.699871582\" name=\"horsepower\"/>                      \n"
"  </group>                                                                             \n"
"  <group id=\"frequency\" equivalence=\"1/s\">                                         \n"
"    <unit id=\"Hz\" scale=\"1\" name=\"Hertz\"/>                                       \n"
"    <unit id=\"rpm\" scale=\"0.016666666666666666666667\" name=\"revolution per minute\" plur_name=\"revolutions per minute\" /> \n"
"    <unit id=\"Bq\" scale=\"1\" name=\"becquerel\"/>                                   \n"
"    <unit id=\"Ci\" scale=\"37000000000\" name=\"curie\"/>                             \n"
"    <unit id=\"Rd\" scale=\"1000000\" name=\"rutherford\"/>                            \n"
"  </group>                                                                             \n"
"  <group id=\"pressure\" equivalence=\"kg/m/s^2\">                                     \n"
"    <unit id=\"Pa\" scale=\"1\" name=\"pascal\"/>                                      \n"
"    <unit id=\"psi\" scale=\"1\" name=\"pound per square inch\" plur_name=\"pounds per square inch\"/> \n"
"    <unit id=\"bar\" scale=\"100000\" name=\"bar\"/>                                   \n"
"    <unit id=\"atm\" scale=\"101325\" name=\"atmosphere\"/>                            \n"
"  </group>                                                                             \n"
"  <group id=\"force\" equivalence=\"kg*m/s^2\">                                        \n"
"    <unit id=\"N\" scale=\"1\" name=\"newton\"/>                                       \n"
"    <unit id=\"dyne\" scale=\"0.00001\" name=\"dyne\"/>                                \n"
"  </group>                                                                             \n"
"  <group id=\"velocity\" equivalence=\"m/s\">                                          \n"
"    <unit id=\"mph\" scale=\"0.44704\" name=\"mile per hour\" plur_name=\"miles per hour\"/> \n"
"    <unit id=\"kph\" scale=\"0.27777777777777777777777777778\" name=\"kilometer per hour\" plur_name=\"kilometers per hour\"/> \n"
"  </group>                                                                             \n"
"  <group id=\"volume\" equivalence=\"m^3\">                                            \n"
"    <unit id=\"cup\" scale=\"2.3658825e-4\" name=\"cup\"/>                             \n"
"    <unit id=\"qt.\" scale=\"9.46353e-04\" name=\"quart\"/>                            \n"
"    <unit id=\"gal\" scale=\"3.785412e-03\" name=\"gallon\"/>                          \n"
"    <unit id=\"L\" scale=\"0.001\" name=\"liter\"/>                                    \n"
"  </group>                                                                             \n"
"  <group id=\"specific_energy\" equivalence=\"m^2/s^2\">                               \n"
"    <unit id=\"Gy\" scale=\"1\" name=\"Gray\"/>                                        \n"
"    <unit id=\"rd\" scale=\"0.01\" name=\"rad\"/>                                      \n"
"  </group>                                                                             \n"
"  <group id=\"mole_flux\" equivalence=\"m^2/s^2\">                                     \n"
"    <unit id=\"kat\" scale=\"1\" name=\"katal\"/>                                      \n"
"  </group>                                                                             \n"
"  <group id=\"hardness\" equivalence=\"m/N\">                                          \n"
"    <unit id=\"VHN\" scale=\"1\" name=\"Vickers\"/>                                    \n"
"    <unit id=\"Rk\" scale=\"1\" name=\"Rockwell\"/>                                    \n"
"  </group>                                                                             \n"
"</units>";

Units units(unit_data);

};
