#include <iostream>
#include <fstream>
#include <string>
#include "gnss.h"

int main(void) {
	
	// GNSS Target Site , DOY
	GNSS_f();
	GNSS_f::setSite("SEOS");
	GNSS_f::setDOY("032");

	std::string Site = "SEOS"; 
	std::string DOY = "032";

	// create file name
	std::string File_obs = Site + DOY + "0.22o";
	std::string File_nav = Site + DOY + "0.22n";
		
	std::ifstream readFile;

	readFile.open(File_obs);


}
