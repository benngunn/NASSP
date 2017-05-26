/***************************************************************************
This file is part of Project Apollo - NASSP
Copyright 2017

Coupling Data Unit (Header)

Project Apollo is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Project Apollo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Project Apollo; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

See http://nassp.sourceforge.net/license/ for more details.

**************************************************************************/

#pragma once

#include "apolloguidance.h"

#include "powersource.h"

class CDU
{
public:
	CDU(ApolloGuidance &comp, int l, int err, bool isicdu);
	void Timestep(double simdt);
	void ChannelOutput(int address, ChannelValue val);
	void SetReadCounter(double angle);
protected:
	void DoZeroCDU();
	double gyroPulsesToRad(int pulses);
	int radToGyroPulses(double angle);

	double ReadCounter;
	double ErrorCounter;

	double OldReadCounter;

	ApolloGuidance &agc;

	//Address of AGC CDU counter
	int loc;
	//Channel for error counter commands
	int err_channel;

	bool IsICDU;
	bool ZeroCDU;
	bool ErrorCounterEnabled;

	//Output channel bit for CDU Zeroing
	int CDUZeroBit;
	//Output channel bit for error counter enabled
	int ErrorCounterBit;
};