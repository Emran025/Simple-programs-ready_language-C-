#include <iostream>
#include <vector>
using namespace std;
int  main() {
    //نقوم باعلان المتغيرات الرئيسية مع المفوفات 
    string text;
    bool validInput = false ;
    int ACQL_NUMBER;
    int  number_length;
    // نضيف المصفوفات التي سنحتاج اليها في العد
    int digits[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string Ones[] = {"", " واحد ", " اثنان ", " ثلاثة ", " أربعة ", " خمسة ", " ستة ", " سبعة ", " ثمانية ", " تسعة  "};
    string Tens[] = { "", "عشر ", " عشرون ", " ثلاثون ", " أربعون ", " خمسون ", " ستون ", " سبعون ", " ثمانون ", " تسعون ", " احد عشر ", " اثنا عشر "};
    string Hundreds[] = {"", " مائة ", " مائتان ", " ثلاث مائة ", " أربع مائة ", " خمس مائة ", " ست مائة ", " سبع مائة ", " ثمان مائة ", " تسع مائة "};
    string Digrees[] = {"","ألفاً ", "ألفان ","آلاف ","مليوناً ", "مليونان ", "ملايين", "ملياراً ", "ملياران ", "مليارات ","تريليوناً ","تريليونان ","تريليونات ","",""};
    // نضيف حلقة لادخال الرقم دالخل سلسلة رقمية وتفصيلها الى الى كل رقم بفرده ثم اعطاء خطأ وتكرار الادخال اذا كان المدخل ليس رقما
    while (!validInput) {
        cout << "Enter a number: "; 
        getline(cin, text);
        // تفصيل العدد إلى أرقامه وتخزينها في المصفوفات
        number_length = text.length();
        for (char c : text) { 
            ACQL_NUMBER = static_cast<int>(c) - 48;
            if ( ACQL_NUMBER >= 0 && ACQL_NUMBER <= 9 ) {
                number_length --;
                digits[number_length] = ACQL_NUMBER;
                validInput = true ;
            } else {
                validInput = false ;
                cout << "this is not number, try agin ";
                break;
            }
        }
    }    //اعلان عن متغيرات لاصلاح الشواذ من القاعدة وبناء حلقات لتصويب الشواذ 
    int t_y[5] = { 0 , digits[3], digits[6], digits[9], digits[12]};
    for (int i = 0; i < 5; i++) {
        int big = (i*3) ;
        bool conditionMet = false ;  // متغير مساعد لتتبع تحقق الشرط في جميع التكرارات
        for ( int j = big + 1 ; j < 15; j++) {
            if ((digits[j] == 0 && digits[big] == 1 ) || (digits[j] == 0 && digits[big] == 2 )) {
                conditionMet = true;
            } else {
                conditionMet = false; // إذا لم يتحقق الشرط في تكرار واحد، نقوم بتعيينه إلى false
                break;
            }
        }
        if (conditionMet) {
            t_y[i] = 0;  // إذا تحقق الشرط في جميع التكرارات، نقوم بتعيين t_y[i]; إلى صفر
            Digrees[big-2] = Digrees[big-1] ;
        }
        for ( int h = 3 ; h < 9 ; h++) { //نضيف شرط لاستبدل مثلا ال"ألفا" ب"آلاف" وهكذا على كل المراتب من خلال القفز درجتين في المصفوفة 
            if ( digits[big + 1] == 0 && digits[big] == h ) {
            Digrees[big-2] = Digrees[big] ;
            }
        } 
        if (  digits[big] == 0 && digits[ big+1] == 0 && digits[big+2] == 0 ) {
            Digrees[big-2] = Digrees[0] ;
        }
        for (int g =1; g<3;g++) {  // إذا تحقق الشرط ، نقوم بتعيين احد عشر واثنا عشر بدلا من واحد عشر واثنان عشر
            if (digits[big+1] == 1 && digits[big] == g  ) {
            t_y[i] = 0;  // إذا تحقق الشرط ، نقوم بتعيين t_y[i]; إلى صفر
            Tens[g] = Tens[g+9] ;  // إذا تحقق الشرط ، نقوم بتعيين احد عشر واثنا عشر بدلا من واحد عشر واثنان عشر عبر القفز 10
            }
        }
        if (digits[big+1] == 1 && digits[big] == 0  ) {
            t_y[i] = 0;  // إذا تحقق الشرط ، نقوم بتعيين t_y[i]; إلى صفر
            Tens[1] = " عشرة " ; // إذا تحقق الشرط، نقوم بتعيين كلمة عشرة بدلا من عشر إلى صفر
            Digrees[big-2] = Digrees[big] ; // إذا تحقق الشرط ، نقوم بتعيين الاف بدلا من الفا اذا كانت الكلمة عشرة
        }         
    }
    // اضافة السلسلة الى متغير بدون اداة الربط
    string combinedString = Hundreds[digits[14]] + Ones[t_y[4]] + Tens[digits[13]]
     + Digrees[10] + Hundreds[digits[11]] + Ones[t_y[3]] + Tens[digits[10]]
     + Digrees[7] + Hundreds[digits[8]] + Ones[t_y[2]] + Tens[digits[7]]
     + Digrees[4] + Hundreds[digits[5]] + Ones[t_y[1]] + Tens[digits[4]]
     + Digrees[1] + Hundreds[digits[2]] + Ones[digits[0]] + Tens[digits[1]] ;
    // اضافة اداة الربط "و" الى الدالة 
    string result;
    int spaceCount = 0;
    for (char c : combinedString ) {
        if (c == ' ') {
            spaceCount++;
            if (spaceCount == 2 ) {
                result += "و ";
                spaceCount = 0;
            } else {
                result += c;
            }
        } else {
            result += c;
            spaceCount = 0;
        }
    }
    cout << result<<endl;
}