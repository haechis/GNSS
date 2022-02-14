#include <iostream>
#include <fstream>
#include <string>
#include "gnss.h"

int main(void) {
	
	// GNSS Target Site , DOY
	std::string site = "SEOS";
	std::string doy = "SEOS";
	GNSS_f gf;
	gf.setSite("SEOS");
	gf.setDOY("032");
	gf.setOBS();
	// std::cout << gf.File_nav;
	
	// create file name
	std::string filename(gf.File_nav);
	std::ifstream readFile;

	int a = gf.ReadEPH(filename);


	readFile.open(gf.File_nav);
	// ���� �� ��: obs ���� �� �پ� �б� -> gnss cpp �̿�~
	readFile.close();

	

	

}
