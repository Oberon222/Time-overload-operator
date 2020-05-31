#pragma once
#include <iostream>
using namespace std;

class Time
{
	int hours, minutes, seconds;
	bool CorrectData(int data)
	{
		return (data >= 0 && data < 60);
	}

public:
	Time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	/*Time(int value)
	{
		hours = value;
		minutes = value;
		seconds = value;
	}*/

	Time(int hours, int minutes, int seconds)
	{
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	Time(int value)
	{
		this->hours = (value /60)/60;
		int tmpHour = (hours * 60) * 60; // години в секундах

		this->minutes = (value - tmpHour)/60;
		int tmpMin = minutes * 60; // хвилини в секундах

		this->seconds = value -(tmpHour+ tmpMin);

	}

	void ShowTime();

	Time operator+(const Time& other) const;

	Time operator-(const Time& other) const;

	Time operator*(const Time& other) const;
	
	Time operator/(const Time& other) const;

	bool operator>(const Time& other) const;

	bool operator<(const Time& other) const;
	
	bool operator>=(const Time& other) const;

	bool operator<=(const Time& other) const;

	bool operator!=(const Time& other) const;

	bool operator==(const Time& other) const;
};
