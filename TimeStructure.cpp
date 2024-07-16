#include <iostream>

namespace TimeStruct {
    struct Time {
        int hours;
        int minutes;
        int seconds;

        Time operator+(const Time& other) const {
            Time result;
            result.hours = hours + other.hours;
            result.minutes = minutes + other.minutes;
            result.seconds = seconds + other.seconds;

            if (result.seconds >= 60) {
                result.minutes += result.seconds / 60;
                result.seconds %= 60;
            }

            if (result.minutes >= 60) {
                result.hours += result.minutes / 60;
                result.minutes %= 60;
            }

            return result;
        }

        Time operator-(const Time& other) const {
            Time result;
            result.hours = hours - other.hours;
            result.minutes = minutes - other.minutes;
            result.seconds = seconds - other.seconds;

            if (result.seconds < 0) {
                result.minutes--;
                result.seconds += 60;
            }

            if (result.minutes < 0) {
                result.hours--;
                result.minutes += 60;
            }

            return result;
        }
    };

    int getTotalSeconds(const Time& time) {
        return time.hours * 3600 + time.minutes * 60 + time.seconds;
    }
}

using namespace std;
using namespace TimeStruct;

int main() {
    setlocale(LC_ALL, "Russian");

    Time time;

    cout << "Введите часы: ";
    cin >> time.hours;

    cout << "Введите минуты: ";
    cin >> time.minutes;

    cout << "Введите секунды: ";
    cin >> time.seconds;

    cout << "Всего секунд: " << getTotalSeconds(time) << endl;

    Time t1{ 1, 30, 0 };
    Time t2{ 0, 45, 30 };

    Time t3 = t1 + t2;
    cout << "t1 + t2 = " << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;

    Time t4 = t1 - t2;
    cout << "t1 - t2 = " << t4.hours << ":" << t4.minutes << ":" << t4.seconds << endl;

    return 0;
}