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


	
	//GNSS_f *setSite(site);
	//GNSS_f *setDOY("032");

	std::string Site = "SEOS"; 
	std::string DOY = "032";

	
	std::string File_obs = Site + DOY + "0.22o";
	std::string File_nav = Site + DOY + "0.22n";
		
	


}
