#include <iostream>
#include <ctime>
using namespace std;

int calculateAge(int birthYear, int birthMonth, int birthDay) {

     // الحصول على الوقت الحالي
    time_t currentTime = time(nullptr);
    // تحويل الوقت الحالي إلى هيكل tm
    tm* now = localtime(&currentTime);
    // الحصول على سنة الحالية وشهر الحالي ويوم الحالي
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
        while (true) {
        cout << "أدخل سنة الميلاد : " ;
        cin >> birthYear;
        if (birthYear>= 1900 && birthYear <= currentYear-1  ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            cout << "عفواً ، رقم سنة الميلاد غير منطقي ، يرجى المعاودة وادخال عدد بين (1900) و (هذا العام )" << endl;
        }
    }
    while (true) {
        cout << "أدخل الشهر من السنة: ";
        cin >> birthMonth ;

        if (birthMonth>= 1  && birthMonth<= 12  ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            cout << "عفواً ، شهر الميلاد غير منطقي ، الرجاء إعادة المحاولة وإدخال عدد من (01-12) " << endl;
        }
    }
    while (true) {
        cout << "أدخل اليوم من الشهر: ";
        cin >> birthDay ;

        if (birthDay>= 1  && birthDay<= 32 ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            cout << "عفواً، يوم الميلاد غير منطقي ، الرجاء إعادة المحاولة وإدخال عدد من (01-30)" << endl;
        }
    }

    int currentDay = now->tm_mday;// حساب العمر بناءً على تاريخ الميلاد
    int age = currentYear - birthYear;
    // التحقق من أن شهر الميلاد لم يمر بعد الشهر الحالي
    if (birthMonth > currentMonth) {
        age--;
    }
    // في حالة تطابق شهر الميلاد مع الشهر الحالي، يتم التحقق من يوم الميلاد
    else if (birthMonth == currentMonth && birthDay > currentDay) {
        age--;
    }
    return age;
}
int main() {
    // إدخال تاريخ الميلاد
    int birthYear, birthMonth, birthDay;
    // حساب العمر
    int age = calculateAge(birthYear, birthMonth, birthDay);
    // طباعة العمر
    cout << "عمرك هو : " << age << endl;
    return 0;
}
