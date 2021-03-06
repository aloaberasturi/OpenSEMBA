// OpenSEMBA
// Copyright (C) 2015 Salvador Gonzalez Garcia        (salva@ugr.es)
//                    Luis Manuel Diaz Angulo         (lmdiazangulo@semba.guru)
//                    Miguel David Ruiz-Cabello Nuñez (miguel@semba.guru)
//                    Daniel Mateos Romero            (damarro@semba.guru)
//
// This file is part of OpenSEMBA.
//
// OpenSEMBA is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// OpenSEMBA is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with OpenSEMBA. If not, see <http://www.gnu.org/licenses/>.

#include "Layer.h"

#include <cassert>
#include <iostream>
#include <sstream>

namespace SEMBA {
namespace Geometry {
namespace Layer {

Layer::Layer() {

}

Layer::Layer(const Id id, const std::string& name)
:   Identifiable<Id>(id) {
    name_ = spaceToUnderscore(name);
}

Layer::Layer(const std::string& name) {
    name_ = spaceToUnderscore(name);
}

Layer::Layer(const Layer& rhs)
:   Identifiable<Id>(rhs) {
    name_ = rhs.name_;
}

Layer::~Layer() {

}

bool Layer::operator ==(const Layer& rhs) const {
    if (typeid(*this) != typeid(rhs)) {
        return false;
    }
    bool res = true;
    res &= (this->getId() == rhs.getId());
    res &= (this->getName() == rhs.getName());
    return res;
}

bool Layer::operator !=(const Layer& rhs) const {
    return !(*this == rhs);
}

std::string Layer::getName() const {
    return name_;
}

std::string Layer::getParentName() const {
   assert(false);
   return std::string();
}

std::string Layer::getChildName() const {
   assert(false);
   return std::string();
}

void Layer::printInfo() const {
    std::cout << toStr() << std::endl;
}

std::string Layer::toStr() const {
    std::stringstream ss;
    ss << "Layer. Id: " << getId() << " Name: " << getName();
    return ss.str();
}

std::string Layer::spaceToUnderscore(std::string rhs) {
    std::string str = rhs;
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if(*it == ' ') {
            *it = '_';
        }
    }
    return str;
}

} /* namespace Layer */
} /* namespace Geometry */
} /* namespace SEMBA */
