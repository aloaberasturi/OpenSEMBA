/*
 * PlaneWave.h
 *
 *  Created on: Jun 28, 2013
 *      Author: luis
 */

#ifndef PLANEWAVE_H_
#define PLANEWAVE_H_

#include "EMSource.h"

class PlaneWave : public EMSource {
public:
    PlaneWave();
    PlaneWave(
	 vector<ElementId> elem,
	 CVecR3 waveDirection,
	 CVecR3 polarization,
	 const Magnitude* magnitude);
	virtual ~PlaneWave();

	virtual ClassBase* clone() const;

	const CVecR3& getPolarization() const;
	const CVecR3& getWaveDirection() const;
	Real getTheta() const;
	Real getPhi() const;
	Real getAlpha() const;
	Real getBeta() const;

	CVecR3 getElectricField(const Real time) const;
	pair<CVecR3,CVecR3> getElectromagneticField(const Real time) const;
	void printInfo() const;
private:
	CVecR3 waveDirection_;
	CVecR3 polarization_;
    pair<Real,Real> cartesianToPolar(const CVecR3& vec) const;
    Real reduceRadians(const Real radianIn) const;
};

#endif /* PLANEWAVE_H_ */
