#include "date.h"

Date::Date(const int& y, const int& m, const int& d)
{
	year = y;
	month = m;
	day = d;
}

void Date::SetYear(const int& y)
{
	year = y;
}

void Date::SetMonth(const int& m)
{
	month = m;
}

void Date::SetDay(const int& d)
{
	day = d;
}

bool operator <(const Date& d1, const Date& d2)
{
	if (d1.GetYear() < d2.GetYear()) { return true;}
		else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() < d2.GetMonth())) { return true;}
			else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() == d2.GetMonth())
										&& (d1.GetDay() < d2.GetDay())) { return true;}
				else { return false;}
}

bool operator ==(const Date& d1, const Date& d2)
{
	if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() == d2.GetMonth()) && (d1.GetDay() == d2.GetDay())) { return true;}
		else { return false;}
}

bool operator <=(const Date& d1, const Date& d2)
{
	if ((d1 < d2) || (d1 == d2)) { return true;}
		else { return false;}
}

bool operator >(const Date& d1, const Date& d2)
{
	if (d1.GetYear() > d2.GetYear()) { return true;}
		else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() > d2.GetMonth())) { return true;}
			else if ((d1.GetYear() == d2.GetYear()) && (d1.GetMonth() == d2.GetMonth())
										&& (d1.GetDay() > d2.GetDay())) { return true;}
				else { return false;}
}

bool operator >=(const Date& d1, const Date& d2)
{
	if ((d1 > d2) || (d1 == d2)) { return true;}
		else { return false;}
}

bool operator !=(const Date& d1, const Date& d2)
{
	if (!(d1 == d2)) { return true;}
		else { return false;}
}


ostream &operator <<(ostream &ostr,const Date &dt){
	ostr << setfill('0') << setw(4) << dt.year << '-'
			 << setw(2) << dt.month << '-' << setw(2) << dt.day;
	return ostr;
}

bool checkFormat(string& str){
	int shetchik = count(str.begin(),str.end(),'-');
	if((str[str.length()-1]=='-') ||  (shetchik>2 || shetchik<2)) {
		return false;
	}
	for(char i:str){
		if((i<'0' || i>'9')&& i!='-'){
			return false;
		}

	}
	return true;
}


Date ParseDate(istream& is)
{
	int y, m, d;
	Date rez;
	string str0;
	is >> str0;
	if(!checkFormat(str0)){
		throw invalid_argument(str0);
	}
	istringstream is2(str0);

	if (!(is2 >> y)) {string error = "Wrong date format";
	throw invalid_argument(error);};
	if ((y < 0) || (y > 9999))  {string error = "Wrong date format";
	throw invalid_argument(error);};
	if (is2.peek() != '-') {string error = "Wrong date format";
			throw invalid_argument(error);};
	is2.ignore(1);
	if (!(is2 >> m)) {string error = "Wrong date format";
	throw invalid_argument(error);};
	if (is2.peek() != '-') {string error = "Wrong date format";
			throw invalid_argument(error);};
	is2.ignore(1);
	if (!(is2 >> d)) {string error = "Wrong date format";
	throw invalid_argument(error);};
	if ((m < 1) || (m > 12)) { stringstream ss; ss << "Month value is invalid"; string error = ss.str();
								throw invalid_argument(error);};
	if ((d < 1) || (d > 31)) { stringstream ss; ss << "Day value is invalid";string error =  ss.str();
								throw invalid_argument(error);};
	rez.SetYear(y);
	rez.SetMonth(m);
	rez.SetDay(d);
	return rez;
};
