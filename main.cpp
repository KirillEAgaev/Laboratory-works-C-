#include "time.h"

int main() {
    const Time time1(11, 59, 59);
    const Time time2(0, 0, 1);
    Time time3;

    time1.print();
    time2.print();

    Time sum = time1 + time2;
    sum.print();

    return 0;
}