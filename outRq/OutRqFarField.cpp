/*
 * OutputRequestFarField.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: luis
 */

#include "OutRqFarField.h"

OutRqFarField::OutRqFarField(const Domain& domain,
                             const string& name,
                             const GroupElements<Vol>& elem,
                             const Real iTh, const Real fTh, const Real sTh,
                             const Real iPhi, const Real fPhi, const Real sPhi)
:   Domain(domain),
    OutRqBase(electric, name),
    GroupElements<const Vol>(elem) {

    setThetaAndPhi(iTh, fTh, sTh, iPhi, fPhi, sPhi);
}

OutRqFarField::OutRqFarField(const OutRqFarField& rhs)
:   Domain(rhs),
    OutRqBase(rhs),
    GroupElements<const Vol>(rhs) {

    initialTheta_ = rhs.initialTheta_;
    finalTheta_ = rhs.finalTheta_;
    stepTheta_ = rhs.stepTheta_;
    initialPhi_ = rhs.initialPhi_;
    finalPhi_ = rhs.finalPhi_;
    stepPhi_ = rhs.stepPhi_;
}

OutRqFarField::~OutRqFarField() {

}

bool OutRqFarField::hasSameProperties(const OutRqBase& rhs) const {
    if(!OutRqBase::hasSameProperties(rhs)) {
        return false;
    }
    const OutRqFarField* rhsPtr = rhs.castTo<OutRqFarField>();
    bool hasSameProperties = true;
    hasSameProperties &= initialTheta_ == rhsPtr->initialTheta_;
    hasSameProperties &= finalTheta_ == rhsPtr->finalTheta_;
    hasSameProperties &= stepTheta_ == rhsPtr->stepTheta_;
    hasSameProperties &= initialPhi_ == rhsPtr->initialPhi_;
    hasSameProperties &= finalPhi_ == rhsPtr->finalPhi_;
    hasSameProperties &= stepPhi_ == rhsPtr->stepPhi_;
    return hasSameProperties;
}

Real OutRqFarField::getInitialTheta() const {
    return initialTheta_;
}

Real OutRqFarField::getFinalTheta() const {
    return finalTheta_;
}

Real OutRqFarField::getStepTheta() const {
    return stepTheta_;
}

Real OutRqFarField::getInitialPhi() const {
    return initialPhi_;
}

Real OutRqFarField::getFinalPhi() const {
    return finalPhi_;
}

Real OutRqFarField::getStepPhi() const {
    return stepPhi_;
}

void OutRqFarField::setThetaAndPhi(Real iTh, Real fTh, Real sTh,
                                   Real iPhi, Real fPhi, Real sPhi) {
    initialTheta_ = iTh * acos(-1.0);
    finalTheta_ = fTh * acos(-1.0);
    stepTheta_ = sTh * acos(-1.0);
    initialPhi_ = iPhi * acos(-1.0);
    finalPhi_ = fPhi * acos(-1.0);
    stepPhi_ = sPhi* acos(-1.0);
}
