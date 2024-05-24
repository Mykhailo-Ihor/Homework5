#include "weather forecast.h"
#include <iomanip>
WeatherForecast::WeatherForecast(std::string wday, unsigned dday, unsigned dmonth, int t, double p) : week_day(wday), date_day(dday), date_month(dmonth), temperature(t), precipitation(p)
{
	if (dday < 1 || dday > 31)
	{
		std::cout << "Invalid day! Setting day to 1\n";
		date_day = 1;
	}
	if (dmonth < 1 || dmonth > 12)
	{
		std::cout << "Invalid month! Setting month to 1\n";
		date_month = 1;
	}
}

std::string WeatherForecast::get_week_day() const
{
	return week_day;
}

unsigned WeatherForecast::get_date_day() const
{
	return date_day;
}

unsigned WeatherForecast::get_date_month() const
{
	return date_month;
}

int WeatherForecast::get_temperature() const
{
	return temperature;
}

double WeatherForecast::get_precipitation() const
{
	return precipitation;
}

void WeatherForecast::set_temperature(int t)
{
	temperature = t;
}

void WeatherForecast::set_precipitation(double p)
{
	precipitation = p;
}

bool WeatherForecast::operator <(const WeatherForecast& other) const {
	if (date_month != other.date_month)
		return date_month < other.date_month;
	return date_day < other.date_day;
}

std::ostream& operator<<(std::ostream& out, const WeatherForecast& wf)
{
	out << std::left << std::setw(10) << wf.week_day << " ";
	if (wf.date_day < 10)
		out << 0;
	out << wf.date_day << '/';
	if (wf.date_month < 10)
		out << 0;
	out << wf.date_month << " | Temperature: " << std::left << std::setw(3) << wf.temperature << "| Precipitation (mm) " << wf.precipitation;
	return out;
}

std::istream& operator>>(std::istream& in, WeatherForecast& wf)
{
	in >> wf.week_day >> wf.date_day >> wf.date_month >> wf.temperature >> wf.precipitation;
	return in;
}

