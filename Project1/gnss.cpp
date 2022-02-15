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

	int b = 0;

	while (std::getline(input_file, line)) {
		b++;
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

		//if (strcmp(line.substr(60, 60 + 9), "ION ALPHA"))

		//std::cout << line.substr(2, 12) << std::endl;
	
	
		if (b == 10)
			break;

	}
	

}