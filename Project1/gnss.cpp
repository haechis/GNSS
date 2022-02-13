#include "gnss.h"
//#include <string>

void GNSS_f::setOBS() {
	// create file name
	std::string File_obs = this->Site + this->DOY + "0.22o";
	std::string File_nav = this->Site + this->DOY + "0.22n";
}
void GNSS_f::setSite(std::string Site) {
	this->Site = Site;

}
void GNSS_f::setDOY(std::string DOY) {
	this->DOY = DOY;
}
