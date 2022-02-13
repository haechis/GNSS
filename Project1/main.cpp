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
	std::ifstream readFile;

	readFile.open(gf.File_obs);
	// 내일 할 일: obs 파일 한 줄씩 읽기 -> gnss cpp 이용~
	readFile.close();

	

	

}
