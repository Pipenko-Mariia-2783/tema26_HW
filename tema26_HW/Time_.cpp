#include "Time_.h"

Time_::Time_()
{
    tm info = {};
    auto curent = time(0);

#if dateWindows == 1
    localtime_s(&info, &curent);
#elif dateWindows == 0
    tm* p = localtime(&curent);
    info = *p;
#endif

    hour = info.tm_hour;
    minutes = info.tm_min;
    seconds = info.tm_sec;
    format = true;
}   

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

void Time_::setHour(int hour)
{
    this->hour = hour;
}

int Time_::getHour() const
{
    return hour;
}

void Time_::setMinutes(int minutes)
{
    this->minutes = minutes;
}

int Time_::getMinutes() const
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    this->seconds = seconds;
}

int Time_::getSeconds() const
{
    return seconds;
}

void Time_::setFormat(bool format)
{
    this->format = format;
}

bool Time_::getFormat() const
{
    return format;
}

bool Time_::valid() const
{
    return (hour >= 0 && hour <= 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
}

void Time_::tickTime()
{
    seconds++;
}

void Time_::untickTime()
{
    seconds--;
}

void Time_::showTime() const
{
    if (format == true) {
        cout << hour << " hour " << minutes << " min " << seconds << " sec" << endl;
    }
    else if(format == false){
        if (hour >= 0 && hour < 12) {
            cout << hour << " AM " << minutes << " min " << seconds << " sec" << endl;
        }
        else if (hour > 12 && hour <= 24) {
            cout << hour-12 << " PM " << minutes << " min " << seconds << " sec" << endl;
        }
        else if (hour == 12) {
            cout << hour<< " PM " << minutes << " min " << seconds << " sec" << endl;
        }
    }
}

bool Time_::operator==(const Time_& obj) const&
{
    if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds) {
        return true;
    }
    else {
        return false;
    }
}

bool Time_::operator!=(const Time_& obj) const&
{
    return!(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
    if (hour != obj.hour)
        return hour > obj.hour;

    if (minutes != obj.minutes)
        return minutes > obj.minutes;

    return seconds > obj.seconds;
}

bool Time_::operator<(const Time_& obj) const&
{
    if (hour != obj.hour)
        return hour < obj.hour;

    if (minutes != obj.minutes)
        return minutes < obj.minutes;

    return seconds < obj.seconds;
}

bool Time_::operator>=(const Time_& obj) const&
{
    return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
    return (*this < obj) || (*this == obj);
}

Time_& Time_::operator+=(float s)
{
    // TODO: insert return statement here
    this->seconds += s;
    while (this->seconds >= 60) {
        this->seconds -= 60;
        this->minutes++;
    }
    return*this;
}

Time_& Time_::operator-=(float s)
{
    // TODO: insert return statement here
    this->seconds -= s;
    while (this->seconds < 0) {
        this->seconds += 60;
        this->minutes--;
    }
    return*this;
}

Time_& Time_::operator+=(int m)
{
    // TODO: insert return statement here
    this->minutes += m;
    while (this->minutes >= 60) {
        this->minutes -= 60;
        this->hour++;
    }
    return*this;
}

Time_& Time_::operator-=(int m)
{
    // TODO: insert return statement here
    this->minutes -= m;
    while (this->minutes < 0) {
        this->minutes += 60;
        this->hour--;
    }
    return*this;
}

Time_& Time_::operator+=(long h)
{
    // TODO: insert return statement here
    this->hour += h;
    if (hour >= 24) {
        hour = hour % 24;
    }
    return*this;
}

Time_& Time_::operator-=(long h)
{
    // TODO: insert return statement here
    this->hour -= h;
    if (hour < 0) {
        hour += 24;
    }
    return*this;
}

Time_ Time_::operator+(float s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(float s) const&
{
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(int m) const&
{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(int m) const&
{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const&
{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const&
{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}
