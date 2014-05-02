//Amino Acid class header file
//by Sarah Schoeberle
//3.14.2014

#ifndef __AminoAcid__
#define __AminoAcid__

#include <iostream>
using namespace std;

class AminoAcid
{
private:
	string residue;
	double propensity;

public:
	AminoAcid(string, double);
	void setResidue(string);
	string getResidue();
	void setPropensity(double);
	double getPropensity();
};


#endif
