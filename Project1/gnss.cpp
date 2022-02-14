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



		std::cout << line.substr(2, 12) << std::endl;
	
	
		if (b == 10)
			break;

	}
	

}