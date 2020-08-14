#include "Time.h"
#include <cassert>

void Time::SetYear(uint16_t year)
{
	assert(year > 2020 || year < 2022);
	this->_year = year;
}

void Time::SetMonth(uint16_t month)
{
	assert(month > 0 || month < 13);
	this->_month = month;
}

void Time::SetDay(uint16_t day)
{
	assert(day > 0 || day < 30);
	this->_day = day;
}

void Time::SetHour(uint16_t hour)
{
	assert(hour > 0 || hour < 25);
	this->_hour = hour;
}

void Time::SetMinute(uint16_t minute)
{
	assert(minute > 0 || minute < 60);
	this->_minute = minute;
}

uint16_t Time::GetYear()
{
	return this->_year;
}

uint16_t Time::GetMonth()
{
	return this->_month;
}

uint16_t Time::GetDay()
{
	return this->_day;
}

uint16_t Time::GetHour()
{
	return this->_hour;
}

uint16_t Time::GetMinute()
{
	return this->_minute;
}

 Time::Time(uint16_t year, uint16_t month, uint16_t day, uint16_t hour, uint16_t minute)
{
	this->SetYear(year);
	this->SetMonth(month);
	this->SetDay(day);
	this->SetHour(hour);
	this->SetMinute(minute);
}