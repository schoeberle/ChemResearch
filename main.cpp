//Amino acid class driver that prints probability
//by Sarah Schoeberle
//3.14.2014

#include "AminoAcid.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {

	//variables
	vector<AminoAcid*> desc;
	vector<string> name;
	vector<double> prop;
	double temp;
	int count=0;
	double sum=0;
	double probability=0;
	double average=0;
	const double bolt = 0.0019872041;
	//variables used to determine highest probability
	double secSum = 0;
	double secLowAvg = 100;
	double sectAvg = 100;
	vector<int> section;
	double secProb =0;
	
	//read file residues and put into vector
	ifstream residues("acidName.txt");
	if(residues) {
		string value;
		while (residues >> value) {
			name.push_back(value);
		}
	}

	//create a vector of propensity per residue
	for(int i=0; i<name.size();i++) {
		double propensity=0;
		if(name[i]== "ALA"){
			propensity=0.0;
		}
		else if (name[i] == "ARG"){
			propensity=0.21;
		}
		else if (name[i] == "ASN"){
			propensity=0.65;
		}
		else if (name[i] == "ASP"){
			propensity=0.69;
		}
		else if (name[i] == "CYS"){
			propensity=0.68;
		}
		else if (name[i] == "GLU"){
			propensity=0.40;
		}
		else if (name[i] == "GLN"){
			propensity=0.39;
		}
		else if (name[i] == "GLY"){
			propensity=1.0;
		}
		else if (name[i] == "HIS"){
			propensity=0.61;
		}
		else if (name[i] == "ILE"){
			propensity=0.41;
		}
		else if (name[i] == "LEU"){
			propensity=0.21;
		}
		else if (name[i] == "LYS"){
			propensity=0.26;
		}
		else if (name[i] == "MET"){
			propensity=0.24;
		}
		else if (name[i] == "PHE"){
			propensity=0.54;
		}
		else if (name[i] == "PRO"){
			propensity=3.16;
		}
		else if (name[i] == "SER"){
			propensity=0.5;
		}
		else if (name[i] == "THR"){
			propensity=0.66;
		}
		else if (name[i] == "TRP"){
			propensity=0.49;
		}
		else if (name[i] == "TYR"){
			propensity=0.53;
		}
		else if (name[i] == "VAL"){
			propensity=0.61;
		}
		else{
			cout << name[i];
			cout << "Error";
			break;
		}
		prop.push_back(propensity);
	}
	
	//vector to hold a bunch of Aminoacids
	for(int i=0; i<name.size();i++){
		AminoAcid *j = new AminoAcid(name[i],prop[i]);
		desc.push_back(j);
		j++;
	}

	//calculate average
	for(int index=0; index<desc.size();index++){
		sum+=desc.at(index)->getPropensity();
		count++;
	}
	if( count == 0) 
	  average=0;
	else
	  average=sum/count;

      	//find average of sections of prob
	for(int i=0; i<desc.size()-3; i++){
		sectAvg = 0;
		secSum = 0;
		for(int j=0; j<4; j++) {
			secSum+=desc.at(i)->getPropensity();
			i++;
		}
		i=i-4;
		sectAvg = secSum/4;
		//lowest average equals highest probability
		if(sectAvg == secLowAvg) {
			section.push_back(i+1);
		}
		else if(sectAvg < secLowAvg) {
			secLowAvg = sectAvg;
			section.clear();
			section.push_back(i+1);
		}
	}
	//user enter temp
	cout << "Enter temperature in Kelvin: ";
	cin >> temp;
	
	//calculate probability
	probability = expf(-average/(bolt*temp));
	cout << "The probability is " << probability << endl;
       	secProb = expf(-secLowAvg/(bolt*temp));
	cout << "Section with highest probability of being helical: " << endl;
	for(int i=0; i < section.size(); i++) {
		cout << "    amino acid: " << section[i] << " to " 
		 << (section[i]+3) << endl;
	}
	cout<< "     with probability " << secProb << endl;

	return 0;
}
