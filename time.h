#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;

        // ѕриведение неправильных значений к правильным
        while (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
    }

    void print() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }

    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }
};