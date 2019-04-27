#pragma once
#include <string>
#include "iostream"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include "algorithm"

using namespace std;

class Date {
public:
  Date() { year = 0; month = 0; day = 0;};
  Date(const int&, const int&, const int&);
  void SetYear(const int&);
  void SetMonth(const int&);
  void SetDay(const int&);
  int GetYear() const { return year;};
  int GetMonth() const { return month;};
  int GetDay() const { return day;};
  friend bool operator <(const Date&, const Date&);
  friend bool operator <=(const Date&, const Date&);
  friend bool operator ==(const Date&, const Date&);
  friend bool operator >=(const Date&, const Date&);
  friend bool operator >(const Date&, const Date&);
  friend bool operator !=(const Date&, const Date&);
  friend ostream& operator <<(ostream &, const Date&);
  int year;
  int month;
  int day;
};

bool checkFormat(string&);

Date ParseDate(istream&);
