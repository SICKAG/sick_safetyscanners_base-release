// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------

/*!
*  Copyright (C) 2020, SICK AG, Waldkirch
*  Copyright (C) 2020, FZI Forschungszentrum Informatik, Karlsruhe, Germany
*
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.

*/

// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!
 * \file Generics.h
 *
 * \author  Lennart Puck <puck@fzi.de>
 * \date    2018-09-24
 * \author  Martin Schulze <schulze@fzi.de>
 * \date    2020-04-15
 */
//----------------------------------------------------------------------

#ifndef SICK_SAFETYSCANNERS_BASE_GENERICS_H
#define SICK_SAFETYSCANNERS_BASE_GENERICS_H

#include <memory>

namespace sick {

/*!
 * \brief Generic helper function to create std::unique_ptr similar to the C++14 standard.
 *
 * 	param T Target Object type.
 * 	param Ts Argument list type.
 * \param params Arguments forwarded to the object's constructor.
 * \return std::unique_ptr<T> Returns a std::unique_ptr instance.
 */
template <typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params)
{
  // C++11 does not come with a make_unique function, so here it is.
  // Borrowed from Scott Meyers' Effective C++ page 139.
  return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}

} // namespace sick
#endif // SICK_SAFETYSCANNERS_BASE_GENERICS_H