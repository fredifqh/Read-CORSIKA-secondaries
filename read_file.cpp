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

double energy(double id_particle, double mass, double p_x, double p_y, double p_z){
	
	if (id_particle == 0)
		mass == MASS_PHOT;

	if (id_particle == 1 or id_particle == 2) 
	 	mass == MASS_ELEC;

	if (id_particle == 5 or id_particle == 6)
		mass == MASS_MUON;

	return sqrt(pow(mass, 2) + pow(p_x, 2) + pow(p_y, 2) + pow(p_z, 2));
}

double distance(double pos_x, double pos_y){
	return pow(pos_x, 2) + pow(pos_y, 2);
}


int main(int argc, char const *argv[]){
	
	string program_name = argv[0];
	string file_name = argv[1];
	
	ifstream in("secundarios.sec");
	ofstream out("result.dat");

	out.setf(std::ios::scientific);
	out.setf(std::ios::showpos);
	out.precision(7);

//	cout.setf(std::ios::scientific);
//	cout.setf(std::ios::showpos);
//	cout.precision(7);
	
	vector<vector<double> > v;

	if (in){
		
		string line;
		
		while (getline(in, line)){
			if (line[0] != '#'){
				v.push_back(vector<double>());
				stringstream split(line);
				double value;

				while (split >> value)
					v.back().push_back(value);
			}
		}
	}

/*    for (int i = 0; i < v.size(); ++i){
    	
    	out << energy(v[i][0], 0, v[i][1], v[i][2], v[i][3]) << '\t';// i << v[i][1]  << v[i][2] << -1*v[i][3] << '\t';
    out << endl;
    }	
*/

	//cout << v[0][0] << endl; //Elemento fila cero y columna cero de la matriz 
    //cout << v.size() << endl;  //Número de filas


               //for para leer toda la matriz//

    for (int i = 0; i < v.size(); i++) { // i para fila             
        for (int j = 0; j < v[i].size(); j++) // j para columna
            out << v[i][j] << '\t';    
        out << endl;
    }
 
    return 0;
}
