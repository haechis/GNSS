#include "gnss.h"
//#include <string>
GNSS_f::GNSS_f() {};
void GNSS_f::setOBS() {
	// create file name
	File_obs = this->Site + this->DOY + "0.22o";
	File_nav = this->Site + this->DOY + "0.22n";
	std::cout << File_nav;
}
void GNSS_f::setSite(std::string Site) {
	this->Site = Site;

}
void GNSS_f::setDOY(std::string DOY) {
	this->DOY = DOY;
}
