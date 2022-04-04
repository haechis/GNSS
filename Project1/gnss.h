#pragma once
#include <string>
#include<iostream>
#include<vector>
#include <fstream>
#include<cstring>
#include<cmath>

class GNSS_f
{
private:
	std::string Site;
	std::string DOY;
public:
	GNSS_f();
	
	std::string File_obs;
	std::string File_nav;
	void setSite(std::string Site);
	void setDOY(std::string DOY);
	void setOBS();
	double str2double(std::string s, int a, int b);
	double str2double2(std::string s, int a, int b);

	void ReadEPH(std::string fp);
	void ReadOBS(std::string fp);

	struct Obs {
		int yy;
		int mm;
		int dd;

		double hour;
		double min;
		double sec;

		std::string gnss_type; // GRECJ ..
		int prn;
		double meas; // measurement
		
		std::vector<int> PRN_s;
		std::vector<double> MEAS_s;
		std::vector<char> PRN_types;

		Obs() {
			double yy = 0;
			double mm = 0;
			double dd = 0;

			double hour = 0;
			double min = 0;
			double sec = 0;

			std::string gnss_type = ""; // GRECJ ..
			int prn = 0;
			double meas = 0;
			
		}
		
	}
	;

	struct eph {
		char GNSS_type; // G R E C J ...

		int prn;
		double t_oe;
		double a, b, c, t_gd;
		double sqrtA;
		double e;
		double i_0, i_dot;
		double Omega_dot, omega, Omega_0;
		double dn;
		double C_uc, C_us;
		double C_rc, C_rs;
		double C_ic, C_is;
		double IODE;
		double week_num;
		double health;
		double IODC;

		eph() {

			int prn = 0;
			double t_oe = 0;
			double a = 0, b = 0, c = 0, t_gd = 0;
			double sqrtA = 0;
			double e = 0;
			double i_0 = 0, i_dot = 0;
			double Omega_dot = 0, omega = 0, Omega_0 = 0;
			double dn = 0;
			double C_uc = 0, C_us = 0;
			double C_rc = 0, C_rs = 0;
			double C_ic = 0, C_is = 0;
			double IODE = 0;
			double week_num = 0;
			double health = 0;
			double IODC = 0;
		}

		eph(int PPRN, double* V) {
			prn = PPRN;
			t_oe = V[1];
			a = V[2];
			b = V[3];
			c = V[4];
			sqrtA = V[12];
			e = V[10];
			i_0 = V[17];
			i_dot = V[21];
			Omega_dot = V[20];
			omega = V[19];
			Omega_0 = V[15];
			dn = V[7];
			C_uc = V[9];
			C_us = V[11];
			C_rc = V[18];
			C_rs = V[6];
			C_ic = V[14];
			C_is = V[16];
			IODE = V[5];
			week_num = V[23];
			health = V[26];
			IODC = V[28];
		}
	};
	std::vector<eph> ephs;
	std::vector<Obs> Obss;

	struct MEAS {
		
	};
	std::vector<MEAS> meas_s;
};

