/* *
                          number.h  -  description
                             -------------------
    begin                : mar jui 2 2002
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
#ifndef NUMBER_H
#define NUMBER_H

namespace LMT {

/*!
    Les classes Number<n> servent de paramètres à des classes ou fonctions paramétriques. Ces classes et ces fonctions ont des spécialisations pour les premières : cad  Number<0>, Number<1>, Number<2>, Number<3>. Ainsi les classes Number<n> jouent le rôle de descripteur pour des fonctions C.
*/
template<unsigned num> struct Number {};
template<int num> struct Relative_Number {};

}

#endif
