#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double MASS_ELEC = 0.000510998928;
const double MASS_MUON = 0.105658369;
const double MASS_PHOT = 0;
const double RADIO_ARRAY = 5;
const double RADIO_DETEC = 1.5;
const double COORD_DETEC_X = (sqrt (3)* RADIO_ARRAY)/2;
const double COORD_DETEC_Y = 0.5*RADIO_ARRAY;

double energy(double id_particle, double mass, double p_x, double p_y, double p_z){
	
	if (id_particle == 0)
		mass == MASS_PHOT;

	if (id_particle == 1 or id_particle == 2) 
	 	mass == MASS_ELEC;

	if (id_particle == 5 or id_particle == 6)
		mass == MASS_MUON;

	return sqrt(pow(mass, 2) + pow(p_x, 2) + pow(p_y, 2) + pow(p_z, 2));
}

struct Point
{
double e1, e2;
};

double Distance(const Point& p1, const Point& p2)
{
double x = p2.e1 - p1.e1 ;
double y = p2.e2 - p1.e2 ;
double r_sq = pow(x, 2) + pow(y, 2);
return sqrt (r_sq);
}



double distance(double pos_x, double pos_y){
	return pow(pos_x, 2) + pow(pos_y, 2);
}

int main(int argc, char const *argv[]){


	if (argc < 2)
	{
	cerr << "input the name of file\n"<< endl;
	}
	string program_name = argv[0];
	//string file_name = argv[1];
	

	ifstream in(argv[1]);
	ofstream out("result.dat");

	out.setf(std::ios::scientific);
	out.setf(std::ios::showpos);
	out.precision(7);
	
	int rank, size;
	
	vector<vector<double> > v;

	if (in){
		
		string line; 
		int i = 0;
		while (getline(in, line)){
			if (line[0] != '#'){
				v.push_back(vector<double>());
				stringstream split(line);
				double value;
				while (split >> value){
					v.back().push_back(value);
				}			
			}
		}
	}

Point tanque_1 = {0, RADIO_ARRAY};
Point tanque_2 = {-COORD_DETEC_X, -COORD_DETEC_Y};
Point tanque_3 = { COORD_DETEC_X, -COORD_DETEC_Y};

for (int i = 0; i < v.size(); i++) { 
  Point position = {(v[i][4])/100, (v[i][5])/100};
  if (Distance(position, tanque_1) < RADIO_DETEC || Distance(position, tanque_2) < RADIO_DETEC || Distance(position, tanque_3) < RADIO_DETEC)
 out <<  v[i][4] << "    "<<v[i][5] << endl;
}

// los siguientes for se usan para leer toda la matriz
/*
    for (int i = 0; i < v.size(); i++) { // i para fila             
        for (int j = 0; j < v[i].size(); j++) // j para columna
            out << v[i][j] << '\t';    
        out << endl;
    }
*/
return 0;
}
