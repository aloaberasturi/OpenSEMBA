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

#include <physicalModel/surface/SIBC.h>

namespace SEMBA {
namespace PhysicalModel {
namespace Surface {

SIBC::SIBC(const Id id,
        const std::string& name,
        const Math::MatC22& Zinfinite,
        const Math::MatC22& ZLinear,
        const std::vector<PoleResidue>& poleImpedance)
:   Identifiable<Id>(id),
    PhysicalModel(name),
    ZInfinity_(Zinfinite),
    ZLinear_(ZLinear),
    poleZ_(poleImpedance) {
}

SIBC::~SIBC() {

}

void SIBC::printInfo() const {
    std::cout << "--- Physical model information ---"   << std::endl;
    std::cout << "Surface Impedance Boundary Condition" << std::endl;
    Surface::printInfo();
    std::cout << "Impedance @ infininite freq.:";
    ZInfinity_.printInfo();
    std::cout << "Impedance @ zero freq.:";
    ZLinear_.printInfo();
    if (poleZ_.size()) {
        std::cout << "Number of poles: " << poleZ_.size() << std::endl;
        std::cout << "# Pole Z11 Z12 Z21 Z22 " << std::endl;
    }
    for (register std::size_t i = 0; i < poleZ_.size(); i++) {
        const std::complex<Math::Real>& pole = poleZ_[i].first;
        const Math::MatC22& Z = poleZ_[i].second;
        std::cout << i << " " << pole << " "
                << Z(0,0) << " " << Z(0,1) << " "
                << Z(1,0) << " " << Z(1,1) << std::endl;
    }
}

std::size_t SIBC::getNumberOfPoles() const {
    return poleZ_.size();
}

} /* namespace Surface */
} /* namespace PhysicalModel */
} /* namespace SEMBA */
