#include "pch.h"
#include "MyClasses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "math.h"
#include <iomanip>

MyClasses::MyClasses()
{
}


MyClasses::~MyClasses()
{
}



//CLASS DVKE
DVKE::DVKE() {}
DVKE::DVKE(DVKE * N, void * Data, DVKE * V) : N(N), V(V), Data(Data) {}

DVKE * DVKE::getN() {
	return this->N;
}

DVKE * DVKE::getV() {
	return this->V;
}

void * DVKE::getData() {
	return this->Data;
}

void DVKE::setN(DVKE *N) {
	this->N = N;
}

void  DVKE::setV(DVKE *V) {
	this->V = V;
}

void DVKE::setData(void * Data) {
	this->Data = Data;
}


//CLASS GEOKO
GEOKO::GEOKO(int BrGr, int LaGr, int BrMin, int LaMin, double BrSec, double LaSec)
	: BrGr(BrGr), LaGr(LaGr), BrMin(BrMin), LaMin(LaMin), BrSec(BrSec), LaSec(LaSec) {}


int GEOKO::getBrGr() { return BrGr; }
int GEOKO::getLaGr() { return LaGr; }
int GEOKO::getBrMin() { return BrMin; }
int GEOKO::getLaMin() { return LaMin; }
double GEOKO::getBrSec() { return BrSec; }
double GEOKO::getLaSec() { return LaSec; }

void GEOKO::setBrGr(int BrGr) {
	this->BrGr = BrGr;
}

void GEOKO::setLaGr(int LaGr) {
	this->LaGr = LaGr;
}

void GEOKO::setBrMin(int BrMin) {
	this->BrMin = BrMin;
}

void GEOKO::setLaMin(int LaMin) {
	this->LaMin = LaMin;
}

void GEOKO::setBrSec(double BrSec) {
	this->BrSec = BrSec;
}

void GEOKO::setLaSec(double LaSec) {
	this->LaSec = LaSec;
}

double GEOKO::getAbstand() {
	return this->abstand;
}

void GEOKO::setAbstand(GEOKO * geo, GEOKO * mitte) {
	double x = abs(this->getBrSec() - mitte->getBrSec());
	double y = abs(this->getLaSec() - mitte->getLaSec());
	this->abstand = sqrt(x * x + y * y);
}

//Operatoren überladen
bool GEOKO::operator>(GEOKO& geoRight) {
	return this->getAbstand() > geoRight.getAbstand();
}

bool GEOKO::operator<(GEOKO& geoRight) {
	return this->getAbstand() < geoRight.getAbstand();
}

bool GEOKO::operator>=(GEOKO& geoRight) {
	return this->getAbstand() >= geoRight.getAbstand();
}

bool GEOKO::operator<=(GEOKO& geoRight) {
	return this->getAbstand() <= geoRight.getAbstand();
}

bool GEOKO::operator==(GEOKO& geoRight) {
	return fabs(this->getAbstand() - geoRight.getAbstand()) <= EPSILON;
}

bool GEOKO::operator!=(GEOKO& geoRight) {
	return fabs(this->getAbstand() - geoRight.getAbstand()) > EPSILON;
}

std::ostream& operator<<(std::ostream& stream, GEOKO& geo) {
	stream << std::fixed << std::setprecision(2)
		<< std::right << std::setw(12) << std::setfill(' ') << geo.getAbstand() << SPLITTER	//setw() fürs formatieren
		<< std::right << std::setw(12) << std::setfill(' ') << geo.getBrSec() << SPLITTER
		<< std::right << std::setw(12) << std::setfill(' ') << geo.getLaSec() << SPLITTER;
	return stream;
}


//CLASS DVK
DVK::DVK(long Max) {
	this->Index = new DVKE*[Max];
	this->Anz = 0;
}

bool DVK::anhaengen(GEOKO * Geo) {
	int tmpAnz = Anz;
	for (int i = 0; i < tmpAnz; i++) {
		DVKE * tmp = Index[i];

		if (tmp->getN() != NULL) {
			DVKE * next = new DVKE(NULL, Geo, tmp);
			tmp->setN(next);
			return true;
		}
		else {
			return false;
		}
		//weiter machen ...
	}
}

void DVK::print() {
	DVKE * aus = new DVKE();
	while (aus->getN() != NULL) {
		if (aus->getV() == NULL) {
			std::cout << "Erstes Element :" << aus->getData();
		}
		std::cout << "V: " << aus->getV() << " Data: " << aus->getData() << " N: " << aus->getN() << std::endl;
	}
}