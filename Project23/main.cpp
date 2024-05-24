#include <iostream>
#include "weather forecast.h"
#include <list>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#define MATH_DEFINES
using namespace std;

int main()
{
	ifstream fin("WeatherForecast.txt");
	list <WeatherForecast> forecasts;
	copy (istream_iterator<WeatherForecast>(fin), istream_iterator<WeatherForecast>(), back_inserter(forecasts));
	fin.close();
	forecasts.sort();
	copy (forecasts.begin(), forecasts.end(), ostream_iterator<WeatherForecast>(cout, "\n"));

	cout << "Enter month: ";
	int month;
	cin >> month;
	cout << "Total precipitation for month " << month << " is " <<
		accumulate(forecasts.begin(), forecasts.end(), 0., [month](double sum, const WeatherForecast& wf) {
		return wf.get_date_month() == month ? sum + wf.get_precipitation() : sum;
			}) << "mm\n";
	vector <WeatherForecast> rainless_days;
	copy_if(forecasts.begin(), forecasts.end(), back_inserter(rainless_days), [month](const WeatherForecast& wf) {
		return wf.get_precipitation() == 0. && wf.get_date_month() == month;
		});
	if (rainless_days.empty())
		cout << "No rainless days in month " << month << endl;
	else
	{
		cout << "Rainless days in month " << month << ":\n";
		copy(rainless_days.begin(), rainless_days.end(), ostream_iterator<WeatherForecast>(cout, "\n"));
	}
	system("pause");
	system("cls");
	cout << "Rainless days:\n";
	copy_if(forecasts.begin(), forecasts.end(), back_inserter(rainless_days), [](const WeatherForecast& wf) {
		return wf.get_precipitation() == 0.;
		});
	sort(rainless_days.begin(), rainless_days.end(), [](const WeatherForecast& wf1, const WeatherForecast& wf2) {
		return wf1.get_temperature() < wf2.get_temperature();
		});
	copy (rainless_days.begin(), rainless_days.end(), ostream_iterator<WeatherForecast>(cout, "\n"));

	cout << "Coldest day:\n " << rainless_days.front() << endl;
	cout << "Hottest day:\n " << rainless_days.back() << endl;
	system("pause");
	system("cls");
	cout << "Enter day (string)\n";
	list<int> temperatures;
	string day;
	cin >> day;

	transform(forecasts.begin(), forecasts.end(), back_inserter(temperatures), [day](const WeatherForecast& wf) {
		return wf.get_week_day() == day ? wf.get_temperature() : INT_MAX;
		});
	temperatures.sort();
	temperatures.unique();
	temperatures.remove(INT_MAX);
	copy(temperatures.begin(), temperatures.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
