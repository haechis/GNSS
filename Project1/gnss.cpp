#include "gnss.h"
//#include <string>
#define MAXBUFLEN   1024

GNSS_f::GNSS_f() {};
void GNSS_f::setOBS() {
	// create file name
	File_obs = this->Site + this->DOY + "0.22o";
	File_nav = this->Site + this->DOY + "0.22n";
	//std::cout << File_nav;
}
void GNSS_f::setSite(std::string Site) {
	this->Site = Site;

}
void GNSS_f::setDOY(std::string DOY) {
	this->DOY = DOY;
}

struct GNSS_f::eph {
	char GNSS_type; // G R E C J ...

	int prn;
	double t_oe;
	double a, b, c, t_gd;
	double sqrtA;
	double e;
	double i_0, i_dot;
	double omega, Omega_0;
	double dn;
	double C_uc, C_us;
	double C_rc, C_rs;
	double C_ic, C_is;
	double IODE;
	double week_num;
	double health;
	double IODC;

	eph() {

		int prn=0;
		double t_oe = 0;
		double a = 0, b = 0, c = 0, t_gd = 0;
		double sqrtA = 0;
		double e = 0;
		double i_0 = 0, i_dot = 0;
		double omega = 0, Omega_0 = 0;
		double dn = 0;
		double C_uc = 0, C_us = 0;
		double C_rc = 0, C_rs = 0;
		double C_ic = 0, C_is = 0;
		double IODE = 0;
		double week_num = 0;
		double health = 0;
		double IODC = 0;
	}

	eph(int PPRN, double *V) {
		prn = PPRN;
		t_oe = V[1];
	}

};

double GNSS_f::str2double(std::string s, int a, int b) {
	//int c = b - 3;
	double x = pow(10, std::stof(s.substr(b - 2, b)));
	return std::stof(s.substr(a, b - 4)) * x;
}


int GNSS_f::ReadEPH(std::string fp) {
	// File_Nav

	std::vector<std::string> lines;
	std::string line;

	std::ifstream input_file(fp);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '" << fp << std::endl;
		return EXIT_FAILURE;
	}

	double al[] = { 0.0, 0.0, 0.0, 0.0 };
	double be[] = { 0.0, 0.0, 0.0, 0.0 };

	while (std::getline(input_file, line)) {
		//line.
		//if (strstr(line))

		//al[0] = std::stof(line.substr(2,12));

		//std::string* ptr = std::strstr(line.substr(60, 60 + 9), "ION ALPHA");

		std::string line_al = line.substr(60, 68);
		//std::cout << line_al << std::endl;
		if (line_al.compare("ION ALPHA") == 0) {
 
			al[0] = str2double(line, 3, 13);
			al[1] = str2double(line, 15, 25);
			al[2] = str2double(line, 27, 37);
			al[3] = str2double(line, 39, 49);
			//std::cout << al[3] << std::endl;


			//al[0] = std::stof(line.substr(4, 9) + "E" + line.substr(11, 13));
			//std::cout << al[0] << std::endl;
			//std::cout << "str2double" << str2double(line, 4, 13) << std::endl;
			//std::cout << "(1) check" << std::endl;
			//std::cout << line_al << std::endl;
			//std::cout << "check" << std::endl;

		}
		std::string line_be = line.substr(60, 67);
		if (line_be.compare("ION BETA") == 0) {

			be[0] = str2double(line, 3, 13);
			be[1] = str2double(line, 15, 25);
			be[2] = str2double(line, 27, 37);
			be[3] = str2double(line, 39, 49);


		}
		std::string line_tmp = line.substr(60, 72);
		if (line_tmp.compare("END OF HEADER") == 0) {
			break;
		}

		//if (strcmp(line.substr(60, 60 + 9), "ION ALPHA"))

		//std::cout << line.substr(2, 12) << std::endl;
	}
	

	// navigation - GPS
	while (std::getline(input_file, line)) {
		double V[31];
		int prn_n = std::stoi(line.substr(0, 2));
		V[0] = prn_n;
		V[1] = std::stod(line.substr(12, 13)) * 3600 + std::stod(line.substr(15, 16)) * 60 + std::stod(line.substr(18, 21)); // toe
		V[2] = str2double(line, 22, 40); // a
		V[3] = str2double(line, 41, 59); // b
		V[4] = str2double(line, 60, 78); // c
		//std::cout << V[3] << std::endl;

		// line 2
		std::getline(input_file, line);

		V[5] = str2double(line, 3, 21);
		V[6] = str2double(line, 22, 40); 
		V[7] = str2double(line, 41, 59); 
		V[8] = str2double(line, 60, 78); 
		//std::cout << V[8] << std::endl;

		// line 3
		std::getline(input_file, line);

		V[9] = str2double(line, 3, 21);
		V[10] = str2double(line, 22, 40);
		V[11] = str2double(line, 41, 59);
		V[12] = str2double(line, 60, 78);

		// line 4
		std::getline(input_file, line);

		V[13] = str2double(line, 3, 21);
		V[14] = str2double(line, 22, 40);
		V[15] = str2double(line, 41, 59);
		V[16] = str2double(line, 60, 78);

		// line 5
		std::getline(input_file, line);

		V[17] = str2double(line, 3, 21);
		V[18] = str2double(line, 22, 40);
		V[19] = str2double(line, 41, 59);
		V[20] = str2double(line, 60, 78);

		// line 6
		std::getline(input_file, line);

		V[21] = str2double(line, 3, 21);
		V[22] = str2double(line, 22, 40);
		V[23] = str2double(line, 41, 59);
		V[24] = str2double(line, 60, 78);

		// line 7
		std::getline(input_file, line);

		V[25] = str2double(line, 3, 21);
		V[26] = str2double(line, 22, 40);
		V[27] = str2double(line, 41, 59);
		V[28] = str2double(line, 60, 78);

		// line 8
		std::getline(input_file, line);

		V[29] = str2double(line, 3, 21);
		V[30] = str2double(line, 22, 40);
		//V[31] = str2double(line, 41, 59);
		//V[32] = str2double(line, 60, 78);
		eph(prn_n, V);
		break;
	}

}