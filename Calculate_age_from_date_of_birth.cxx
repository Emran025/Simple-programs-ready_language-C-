#include <iostream>
#include <ctime>

int calculateAge(int birthYear, int birthMonth, int birthDay) {

        // الحصول على الوقت الحالي
    std::time_t currentTime = std::time(nullptr);
    
    // تحويل الوقت الحالي إلى هيكل tm
    std::tm* now = std::localtime(&currentTime);
    
    // الحصول على سنة الحالية وشهر الحالي ويوم الحالي
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    
    
    
    // حساب العمر بناءً على تاريخ الميلاد
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
    
     // الحصول على الوقت الحالي
    std::time_t currentTime = std::time(nullptr);
    
    // تحويل الوقت الحالي إلى هيكل tm
    std::tm* now = std::localtime(&currentTime);
    
    // الحصول على سنة الحالية
    int currentYear = now->tm_year + 1900;
  
  
    
        
        while (true) {
    std::cout << "أدخل سنة الميلاد : " ;
    std::cin >> birthYear;

        if (birthYear>= 1900 && birthYear <= currentYear-1  ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            std::cout << "عفواً ، رقم سنة الميلاد غير منطقي ، يرجى المعاودة وادخال عدد بين (1900) و (هذا العام )" << std::endl;
        }
    }

    
            
        while (true) {
    std::cout << "أدخل الشهر من السنة: ";
    std::cin >> birthMonth ;

        if (birthMonth>= 1  && birthMonth<= 12  ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            std::cout << "عفواً ، شهر الميلاد غير منطقي ، الرجاء إعادة المحاولة وإدخال عدد من (01-12) " << std::endl;
        }
    }

    
                
        while (true) {
    std::cout << "أدخل اليوم من الشهر: ";
    std::cin >> birthDay ;

        if (birthDay>= 1  && birthDay<= 32 ) {
            break; // يتم انتهاء الحلقة إذا كان الرقم صحيحًا
        } else {
            std::cout << "عفواً، يوم الميلاد غير منطقي ، الرجاء إعادة المحاولة وإدخال عدد من (01-30)" << std::endl;
        }
    }


 
    
    // حساب العمر
    int age = calculateAge(birthYear, birthMonth, birthDay);
    
    // طباعة العمر
    std::cout << "عمرك هو : " << age << std::endl;
    
    return 0;
}