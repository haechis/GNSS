#include "gnss.h"
//#include <string>

 
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

//struct GNSS_f::eph {};
	



double GNSS_f::str2double(std::string s, int a, int b) {
	//int c = b - 3;
	double x = pow(10, std::stof(s.substr(b - 2, b)));
	return std::stof(s.substr(a, b - 4)) * x;
}


void GNSS_f::ReadEPH(std::string fp) {
	//std::vector<eph> ephs;
	// File_Nav
	
	//std::vector<std::string> lines;
	std::string line;

	std::ifstream input_file(fp);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '" << fp << std::endl;
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
	int kkk = 0;
	while (std::getline(input_file, line)) {
		double V[31];
		int prn_n = std::stoi(line.substr(0, 2));
		V[0] = prn_n;
		V[1] = std::stod(line.substr(12, 13)) * 3600 + std::stod(line.substr(15, 16)) * 60 + std::stod(line.substr(18, 21)); // toe
		V[2] = str2double(line, 22, 40); // a [sec]
		V[3] = str2double(line, 41, 59); // b [sec/sec]
		V[4] = str2double(line, 60, 78); // c [sec/sec2]
		//std::cout << V[3] << std::endl;

		// line 2
		std::getline(input_file, line);

		V[5] = str2double(line, 3, 21); // IODE
		V[6] = str2double(line, 22, 40); // Crs [meters]
		V[7] = str2double(line, 41, 59); // dn [rad/sec]
		V[8] = str2double(line, 60, 78); // M0 [rad]
		//std::cout << V[8] << std::endl;

		// line 3
		std::getline(input_file, line);

		V[9] = str2double(line, 3, 21); // Cuc [rad]
		V[10] = str2double(line, 22, 40); // eccentricity
		V[11] = str2double(line, 41, 59); //Cus [rad]
		V[12] = str2double(line, 60, 78); //sqrt(A) [sqrt(m)]

		// line 4
		std::getline(input_file, line);

		V[13] = str2double(line, 3, 21); // Toe [sec of GPS week]
		V[14] = str2double(line, 22, 40); // Cic [rad]
		V[15] = str2double(line, 41, 59); // Omega 0 [rad]
		V[16] = str2double(line, 60, 78); // Cis [rad]

		// line 5
		std::getline(input_file, line);

		V[17] = str2double(line, 3, 21); //i0 [rad]
		V[18] = str2double(line, 22, 40); // Crc [meters]
		V[19] = str2double(line, 41, 59); // omega [rad]
		V[20] = str2double(line, 60, 78); // Omega dot [rad/sec]

		// line 6
		std::getline(input_file, line); 

		V[21] = str2double(line, 3, 21); // IDOT [rad/sec]
		V[22] = str2double(line, 22, 40); // Codes on L2 channel
		V[23] = str2double(line, 41, 59); // GPS Week #
		V[24] = str2double(line, 60, 78); // L2P data flag

		// line 7
		std::getline(input_file, line);

		V[25] = str2double(line, 3, 21); // SV accuracy
		V[26] = str2double(line, 22, 40); // SV health
		V[27] = str2double(line, 41, 59); // TGD [sec]
		V[28] = str2double(line, 60, 78); // IODC

		// line 8
		std::getline(input_file, line);

		V[29] = str2double(line, 3, 21); // transmission time of message
		V[30] = str2double(line, 22, 40);
		//V[31] = str2double(line, 41, 59);
		//V[32] = str2double(line, 60, 78);

		ephs.push_back(eph(prn_n, V));

		// std::vector<eph> &a = eph(prn_n,V);
		// a(prn_n, V);
		//std::cout << kkk++;
		
	}
	//std::cout << ephs[5].prn;
}

void GNSS_f::ReadOBS(std::string fp) {
	std::string line;

	std::ifstream input_file(fp);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '" << fp << std::endl;
	}

	while (std::getline(input_file, line)) {
		std::string EOH = line.substr(60, 72); // End Of Header
		if (EOH.compare("END OF HEADER") == 0) 
			break;
	}
	while (std::getline(input_file, line)) {

	}

	

}