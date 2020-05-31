#include <iostream>
#include "Time.h"
using namespace std;

	void Time::ShowTime()
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}

	Time Time::operator+(const Time& other) const
	{
		int resHuors = this->hours + other.hours;
		int resMinutes = this->minutes + other.minutes;
		if (resMinutes == 60) {
			resMinutes = 0;
			resHuors++;
		}
		else if (resMinutes > 60) {
			resMinutes -= 60;
			resHuors++;
		}

		int resSeconds = this->seconds + other.seconds;
		if (resSeconds == 60) {
			resSeconds = 0;
			resMinutes++;
		}
		else if (resSeconds > 60) {
			resSeconds -= 60;
			resMinutes++;
		}

		Time res(resHuors, resMinutes, resSeconds);
		
		return res;
	}

	Time Time::operator-(const Time& other) const 
	{
		int resSeconds=this->seconds-other.seconds;
		int resMinutes=this->minutes - other.minutes;
		int resHours=this->hours - other.hours;

		if (this->hours > other.hours) {
			resHours = this->hours - other.hours;
		}
		else  
		{
			cout << "This action is incorrect" << endl;
		}


		if (this->minutes > other.minutes) {
			resMinutes = this->minutes - other.minutes;
		}
		else if (this->minutes < other.minutes && this->hours > 0) {
			resMinutes = this->minutes + 60 - other.minutes;
			resHours--;
		}

		else
		{
			cout << "This action is incorrect" << endl;
		}



		if (this->seconds > other.seconds) {
			resSeconds = this->seconds - other.seconds;
		}
		else if (this->seconds < other.seconds && this->minutes>0) {
			resSeconds = this->seconds + 60 - other.seconds;
			resMinutes--;
		}
		else
		{
			cout << "This action is incorrect" << endl;

		}

		Time res(resHours, resMinutes, resSeconds);
		
		return res;
	}

	Time Time::operator*(const Time& other) const
	{
		int resSeconds = this->seconds * other.seconds;
		int resMinutes= this->minutes * other.minutes;
		int resHours= this->hours * other.hours;
		int tmpMin;

		if (resSeconds == 60)
		{
			resSeconds = 0;
			resMinutes++;
		}

		else if (resSeconds > 60)
		{
			tmpMin= resSeconds/60;
			resSeconds =(this->seconds * other.seconds)-(tmpMin * 60);
			resMinutes += tmpMin;

		}

		if (resMinutes == 60) {
			resMinutes = 0;
			resHours++;
		}

		else if (resMinutes > 60) 
		{
			int tmpHours= resMinutes/60;
			resMinutes = tmpMin+(this->minutes * other.minutes)-(tmpHours * 60);
			cout << "resMinutes"<<resMinutes << endl;
			resHours += tmpHours;

		}

		Time res(resHours, resMinutes, resSeconds);
		return res;
	}

	Time Time::operator/(const Time& other) const
	{

		Time res(this->hours / other.hours, this->minutes / other.minutes, this->seconds / other.seconds);
		return res;
	}

	bool Time::operator>(const Time& other) const
	{
		return (this->hours > other.hours && this->minutes > other.minutes && this->seconds > other.seconds);
	}

	bool Time::operator<(const Time& other) const
	{
		return (this->hours < other.hours&& this->minutes < other.minutes&& this->seconds < other.seconds);
	}
	bool Time::operator>=(const Time& other) const
	{
		return (this->hours >= other.hours && this->minutes >= other.minutes && this->seconds >= other.seconds);
	}

	bool Time::operator<=(const Time& other) const
	{
		return (this->hours <= other.hours && this->minutes <= other.minutes && this->seconds <= other.seconds);
	}

	bool Time::operator!=(const Time& other) const
	{
		return (this->hours != other.hours || this->minutes != other.minutes || this->seconds != other.seconds);
	}

	bool Time::operator==(const Time& other) const
	{
		return (this->hours == other.hours && this->minutes == other.minutes && this->seconds == other.seconds);
	}



