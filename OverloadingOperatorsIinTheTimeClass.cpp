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

    // Перегрузка оператора сложения
    Time operator+(const Time& other) const {
        Time result(*this);
        result.seconds += other.seconds;
        result.minutes += other.minutes;
        result.hours += other.hours;

        result.normalize();

        return result;
    }

    // Перегрузка оператора вычитания
    Time operator-(const Time& other) const {
        Time result(*this);
        result.seconds -= other.seconds;
        result.minutes -= other.minutes;
        result.hours -= other.hours;

        result.normalize();

        return result;
    }

    // Перегрузка оператора сложения: Time + float
    Time operator+(float secs) const {
        Time result(*this);
        result.seconds += static_cast<int>(secs);
        result.normalize();
        return result;
    }

    // Перегрузка оператора сложения: float + Time
    friend Time operator+(float secs, const Time& time);

    // Перегрузка оператора сравнения
    bool operator<(const Time& other) const {
        if (hours < other.hours) return true;
        if (hours > other.hours) return false;
        if (minutes < other.minutes) return true;
        if (minutes > other.minutes) return false;
        return seconds < other.seconds;
    }

    bool operator>(const Time& other) const {
        return other < *this;
    }

    bool operator<=(const Time& other) const {
        return !(*this > other);
    }

    bool operator>=(const Time& other) const {
        return !(*this < other);
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

private:
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }

        if (hours >= 24) {
            hours %= 24;
        }
    }
};

// Перегрузка оператора сложения: float + Time
Time operator+(float secs, const Time& time) {
    return Time(time) + secs;
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        Time time1(11, 59, 59);
        Time time2(0, 0, 1);
        //Time time3(24, 0, 0); // Будет выброшено исключение

        time1.print();
        time2.print();

        Time sum = time1 + time2;
        sum.print();

        Time diff = time1 - time2;
        diff.print();

        Time timeWithFloat = time1 + 3.5;
        timeWithFloat.print();

        Time floatWithTime = 4.2 + time1;
        floatWithTime.print();

        cout << "time1 < time2: " << (time1 < time2) << endl;
        cout << "time1 > time2: " << (time1 > time2) << endl;
        cout << "time1 == time2: " << (time1 == time2) << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}