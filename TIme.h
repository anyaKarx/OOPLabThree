#pragma once
#include <iostream>
#include <iomanip>
class Time
{
private:
	uint16_t _year;
	uint16_t _month;
	uint16_t _day;
	uint16_t _hour;
	uint16_t _minute;

public:
	Time(uint16_t year, uint16_t month, uint16_t _day, uint16_t hour, uint16_t minute);
	Time() {};
	void SetYear(uint16_t year);
	void SetMonth(uint16_t month);
	void SetDay(uint16_t _day);
	void SetHour(uint16_t hour);
	void SetMinute(uint16_t minute);

	uint16_t GetYear();
	uint16_t GetMonth();
	uint16_t GetDay();
	uint16_t GetHour();
	uint16_t GetMinute();
	friend std::wostream& operator<<(std::wostream& os, const Time& time);
};

inline std::wostream& operator<<(std::wostream& os, const Time& time)
{
	return os << time._year
		<< L"." << std::setfill(L'0')<< std::setw(2) << time._month<<L"." 
		<< std::setfill(L'0') <<std::setw(2) << time._day<< L" " 
		<< std::setfill(L'0') << std::setw(2) << time._hour << L":"
		<< std::setfill(L'0') << std::setw(2) << time._minute << L".";
}