#pragma once
#include <string>


class GNSS_f
{
private:
	std::string Site;
	std::string DOY;
public:
	GNSS_f();
	void setSite(std::string Site);
	void setDOY(std::string DOY);
	void setOBS();
	

};
