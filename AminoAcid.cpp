//Amino acid class constructors
//by Sarah Schoeberle
//3.14.2014

#include "AminoAcid.h"

AminoAcid::AminoAcid(string n, double num) {
	residue=n;
	propensity=num;
}
void AminoAcid::setResidue(string n) {
	residue=n;
}
string AminoAcid::getResidue() {
	return residue;
}
void AminoAcid::setPropensity(double num) {
	propensity=num;
}
double AminoAcid::getPropensity() {
	return propensity;
}
