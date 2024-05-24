#pragma once
#include <iostream>

class WeatherForecast
{
	std::string week_day;
	unsigned date_day;
	unsigned date_month;
	int temperature;
	double precipitation;
public:
	WeatherForecast(std::string wdayy = "Monday", unsigned dday = 1, unsigned dmonth = 1, int t = 0, double p = 0);
	WeatherForecast(const WeatherForecast& other) = default;
	friend std::ostream& operator<<(std::ostream& out, const WeatherForecast& wf);
	friend std::istream& operator>>(std::istream& in, WeatherForecast& wf);
	std::string get_week_day() const;
	unsigned get_date_day() const;
	unsigned get_date_month() const;
	int get_temperature() const;
	double get_precipitation() const;
	void set_temperature(int t);
	void set_precipitation(double p);
	bool operator < (const WeatherForecast& other) const;

	
};