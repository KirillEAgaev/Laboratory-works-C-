#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) {
        setHours(h);
        setMinutes(m);
        setSeconds(s);
    }

    void setHours(int h) {
        if (h < 0 || h >= 24) {
            throw out_of_range("Часы должны быть от 0 до 23");
        }
        hours = h;
    }

    void setMinutes(int m) {
        if (m < 0 || m >= 60) {
            throw out_of_range("Минуты должны быть от 0 до 59");
        }
        minutes = m;
    }

    void setSeconds(int s) {
        if (s < 0 || s >= 60) {
            throw out_of_range("Секунды должны быть от 0 до 59");
        }
        seconds = s;
    }

    void print() const {
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << endl;
    }

    Time operator+(const Time& other) const {
        Time result(*this);
        result.seconds += other.seconds;
        result.minutes += other.minutes;
        result.hours += other.hours;

        if (result.seconds >= 60) {
            result.minutes += result.seconds / 60;
            result.seconds %= 60;
        }

        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes %= 60;
        }

        if (result.hours >= 24) {
            result.hours %= 24;
        }

        return result;
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");

    try {
        const Time time1(11, 59, 59);
        const Time time2(0, 0, 1);
        Time time3(24, 0, 0); // Будет выброшено исключение

        time1.print();
        time2.print();

        Time sum = time1 + time2;
        sum.print();
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}