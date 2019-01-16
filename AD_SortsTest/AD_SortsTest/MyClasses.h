#pragma once
class MyClasses
{
public:
	MyClasses();
	~MyClasses();
};

#define SPLITTER   ";"
#define EPSILON   0.01

class DVKE
{
protected:
	DVKE * N;
	DVKE * V;
	void * Data;

public:
	DVKE();
	DVKE(DVKE *N, void *Data, DVKE *V);
	DVKE* getN();
	DVKE* getV();
	void* getData();
	void setN(DVKE *N);
	void setV(DVKE *V);
	void setData(void *Data);

};

class GEOKO
{
private:
	int BrGr;
	int LaGr;
	int BrMin;
	int LaMin;
	double BrSec;
	double LaSec;
	double abstand;

public:
	GEOKO(int BrGr, int LaGr, int BrMin, int LaMin, double BrSec, double LaSec);

	int getBrGr();
	int getLaGr();
	int getBrMin();
	int getLaMin();
	double getBrSec();
	double getLaSec();
	void setBrGr(int BrGr);
	void setLaGr(int LaGr);
	void setBrMin(int BrMin);
	void setLaMin(int LaMin);
	void setBrSec(double BrSec);
	void setLaSec(double LaSec);

	double getAbstand();
	void setAbstand(GEOKO * geo, GEOKO * mitte);

	static void calcGeo(double secLong, double * sec, int * min, int * gr);

	void Print();
	void PrintShort();

	bool operator>(GEOKO& geoRigth);
	bool operator<(GEOKO& geoRigth);
	bool operator>=(GEOKO& geoRigth);
	bool operator<=(GEOKO& geoRigth);
	bool operator==(GEOKO& geoRigth);
	bool operator!=(GEOKO& geoRigth);

	//	friend std::ostream& operator << (std::ostream& stream, const GEOKO& geo);
};

class DVK : DVKE
{
private:
	long  Max;      //Maximale Anzahl der Elemente
	long Anz;       //Anzahl der vorhandenen Elemente
	DVKE ** Index;  //Array von Pointern auf DVKE

public:
	DVK(long Max);
	int getMax();
	int getAnz();
	void setMax(int Max);
	void setAnz(int Anz);

	bool anhaengen(GEOKO *);
	void print();
	void heapSort();
	void heapDown();
	void vertausche(long First, long Second);
};
