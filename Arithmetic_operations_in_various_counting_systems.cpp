#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main() {
    long long digit_between;
    int digit_system;
    int digit_a_from;
    int   ACQL_dig;
    long long  digit_from;
    long long   the_number=0;
    long long   the_b_number = 0 ;
    long long   the_a_number = 0 ;
    long long   how_many;
    string text;
    bool validInput = false;
    while (!validInput) {
        cout << " أدخل قيمة الرقم الدال على العملية :" << endl;
        cout << " للتحويل بين أنظمةالعد المختلفة أدخل الرقم 5 " << endl;
        cout << " للضرب(*) بين أنظمة العد المختلفة أدخل الرقم 4 " << endl;
        cout << " للقسمة(/) بين أنظمة العد المختفة أدخل الرقم 3 " << endl;
        cout << " للطرح(-) بين أنظمة العد المختلفة أدخل الرقم 2" << endl;
        cout << " للجمع(+) بين الأنظمة العد المختلفة أدخل الرقم 1" << endl;
        cin >> digit_system ;
        }
        if (digit_system == 1 || digit_system == 2 || digit_system == 3 || digit_system == 4 || digit_system == 5 ) {
        validInput = false;
        while (!validInput) {
            switch (digit_system) {
                case 1 :
                    cout << " إدخل قيمة نظام الرقم الاول المراد اجراء عملية الجمع معه :" << endl;
                    validInput = true ;
                    break;
                case 2 :
                    cout << " إدخل قيمة نظام الرقم الاول المراد اجراء عملية طرحه أو الطرح منه :" << endl;
                    validInput = true ;
                    break;
                case 3 :
                    cout << " إدخل قيمة نظام الرقم الاول المراد اجراء عملية القسمة عليه :" << endl;
                    validInput = true ;
                    break;
                case 4 :
                    cout << " إدخل قيمة نظام الرقم الاول المراد اجراء عملية الضرب به :" << endl;
                    validInput = true ;
                    break;
                default:
                    cout << " إدخل قيمة نظام الرقم المراد التحويل منه :" << endl;
                    break;
            }
            cout << " للنظام الثنائي (Binary) اكتب 2 " << " للنظام الرباعي (Quaternary) اكتب 4 " << endl;
            cout << " للنظام الثماني (Octal) اكتب 8 " << " للنظام العشري (Decimal) اكتب 10 " << endl;
            cout << " للنظام السداسي عشر (Hexadecimal) اكتب 16" << endl;
            cin >> digit_from ;
            switch (digit_from) {
        case 2:
            case 4:
            case 8:
            case 10:
            case 16:
                validInput = true;
                break;
            default:
                cout << "عذراً، القيمة غير صالحة..." << endl;
                break;
            }
        }
        validInput = false ; 
        while (!validInput) {
            switch (digit_system) {
                case 1 :
                    cout << " أدخل الرقم الأول المراد اجراء عملية الجمع معه :" << endl;
                    break;
            
                case 2 :
                    cout << " أدخل الرقم الأول المراد اجراء عملية طرحه أو الطرح منه :" << endl;
                    break;
                    
                case 3 :
                    cout << " أدخل الرقم الأول المراد اجراء عملية قسمته :" << endl;
                    break;

                case 4 :
                    cout << " أدخل الرقم الاول المراد اجراء عملية الضرب به :" << endl;
                    break;

                default:
                cout << " إدخل الرقم المراد تحويله :" << endl;
                break;
            }

            getline(cin, text);
            int the_alpha = text.length();
            for (char c : text) {
            validInput = false ; 
                the_alpha-- ;
                int ACQL_NUMBER = static_cast<int>(c);
                how_many = pow (digit_from , the_alpha ) ;
                
                if ((digit_from==16) && ( ACQL_NUMBER >= 65 && ACQL_NUMBER <= 90)) {
                    ACQL_dig = ACQL_NUMBER - 55 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                

                } else if ((digit_from==16) && (ACQL_NUMBER <= 122 && ACQL_NUMBER >= 97)) {
                    ACQL_dig = ACQL_NUMBER - 87 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                
                } else if ((digit_from==16) && ( ACQL_NUMBER >= 48 && ACQL_NUMBER <= 57)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;


                } else if ((digit_from==10) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 57)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_from==8) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 55)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_from==4) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 51)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_from==2 ) && ( ACQL_NUMBER == 48 || ACQL_NUMBER == 49)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_b_number = the_b_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else {
                    cout << "عذراً، القيمة ("<<text<<") غير صالحة في النظام ال. " << digit_from << " حاول مرة أخرى." << endl;
                    validInput = false;
                    break;
                }
            }
        }
    } else if (digit_system == 1 || digit_system == 2 || digit_system == 3 || digit_system == 4 ) {
        bool validInput = false;
        while (!validInput) {
            switch (digit_system) {
                case 1 :
                    cout << " إدخل قيمة نظام الرقم الثاني المراد اجراء عملية الجمع معه :" << endl;
                    validInput = true ;
                    break;
                case 2 :
                    cout << " إدخل قيمة نظام الرقم الثاني المراد اجراء عملية طرحه الطرح منه :" << endl;
                    validInput = true ;
                    break;
                case 3 :
                    cout << " إدخل قيمة نظام الرقم الثاني المراد اجراء عملية القسمة عليه :" << endl;
                    validInput = true ;
                    break;
                default:
                    cout << " إدخل قيمة نظام الرقم الثاني المراد اجراء عملية الضرب به :" << endl;
                    break;
            }
            cout << " للنظام الثنائي (Binary) اكتب 2 " << " للنظام الرباعي (Quaternary) اكتب 4 " << endl;
            cout << " للنظام الثماني (Octal) اكتب 8 " << " للنظام العشري (Decimal) اكتب 10 " << endl;
            cout << " للنظام السداسي عشر (Hexadecimal) اكتب 16" << endl;
            cin >> digit_a_from ;
        switch (digit_from) {
            case 2:
            case 4:
            case 8:
            case 10:
            case 16:
                validInput = true;
                break;
            
            default:
                cout << "عذراً، القيمة غير صالحة..." << endl;
                break;
            }
        }
        string text_a;
        validInput = false ; 
        while (!validInput) {
            switch (digit_system) {
                case 1 :
                    cout << " إدخل الرقم الثاني المراد اجراء عملية الجمع معه :" << endl;
                    break;
            
                case 2 :
                    cout << " إدخل الرقم الثاني المراد اجراء عملية طرحه الطرح منه :" << endl;
                    break;
                    
                case 3 :
                    cout << " إدخل الرقم الثاني المراد اجراء عملية القسمة عليه :" << endl;
                    break;

                default :
                    cout << " إدخل قيمة الرقم الثاني المراد اجراء عملية الضرب به :" << endl;
                    break;
            }
            getline(cin, text_a);
            int the_alpha = text_a.length();
            for (char c : text_a) {
                the_alpha-- ;
                how_many = pow (digit_a_from , the_alpha ) ;
                int ACQL_NUMBER = static_cast<int>(c);

                if ((digit_a_from==16) && (ACQL_NUMBER <= 122 && ACQL_NUMBER >= 97)) {
                    ACQL_dig = ACQL_NUMBER - 87 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;

                } else if ((digit_a_from==16) && ( ACQL_NUMBER >= 65 && ACQL_NUMBER <= 90)) {
                    ACQL_dig = ACQL_NUMBER - 55 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;

                } else if ((digit_a_from==16) && ( ACQL_NUMBER >= 48 && ACQL_NUMBER <= 57)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;

                } else if ((digit_a_from==10) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 57)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_a_from==8) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 55)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_a_from==4) && (ACQL_NUMBER >= 48 && ACQL_NUMBER <= 51)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else if ((digit_a_from==2 ) && ( ACQL_NUMBER == 48 || ACQL_NUMBER == 49)) {
                    ACQL_dig = ACQL_NUMBER - 48 ;
                    the_a_number = the_a_number + (ACQL_dig * how_many );
                    validInput = true;
                    
                } else {
                    cout << "عذراً، القيمة ("<<text_a<<") غير صالحة في النظام ال. " << digit_a_from << " حاول مرة أخرى." << endl;
                    validInput = false;
                    break;
                }
            }
        }
    }
    switch (digit_system) {
        case 1 :
            the_number = the_b_number + the_a_number;
            break;
    
        case 2 :
            the_number = the_b_number - the_a_number;
            break;
            
        case 3 :
            the_number = the_b_number / the_a_number;
            break;
    
        case 4 :
            the_number = the_b_number * the_a_number;
            break;
        case 5 :
            the_number = the_b_number;
            break;
    
        default:
        cout << "عذراً، القيمة غير صالحة..." << endl;
            break;
    }
    if (digit_system == 1 || digit_system == 2 || digit_system == 3 || digit_system == 4 || digit_system == 5 ) {
        
        int which_digit_to;
        validInput = false;
        int binary = 0; // المتغير الذي سيحتوي على النتيجة الثنائية
        int quaternary  = 0; // المتغير الذي سيحتوي على النتيجة الثنائية
        int octal  = 0; // المتغير الذي سيحتوي على النتيجة الثنائية
        string hexadecimal;
        int base = 1; // القاعدة التي ستستخدم في التحويل
        while (!validInput) {
            switch (digit_system) {
                case 1 :
                    cout << " أدخل قيمة النظام المراد عرض نتيجة الجمع فيه :" << endl;
                    break;
                case 2 :
                    cout << " أدخل قيمة النظام المراد عرض نتيجة الالطرح فيه :" << endl;
                    break;
                case 3 :
                    cout << " أدخل قيمة النظام المراد عرض نتيجة القسمة فيه :" << endl;
                    break;
                case 4 :
                    cout << " أدخل قيمة النظام المراد عرض نتيجة الضرب فيه :" << endl;
                    break;
                default:
                    cout << " أدخل قيمة النظام المراد تحويل الرقم اليه :" << endl;
                    break;
            }
            cout << " للنظام الثنائي (Binary) اكتب 2 " << " للنظام الرباعي (Quaternary) اكتب 4 " << endl;
            cout << " للنظام الثماني (Octal) اكتب 8 " << " للنظام العشري (Decimal) اكتب 10 " << endl;
            cout << " للنظام السداسي عشر (Hexadecimal) اكتب 16" << endl;
            cin >> which_digit_to ;

            switch (which_digit_to) {
                case 2:
                    while (the_number > 0) {
                        int remainder = the_number % which_digit_to ; // الباقي عند قسمة الرقم على 2
                        binary = binary + (remainder * base ); // ضع الباقي في المتغير الثنائي
                        the_number = the_number / which_digit_to ; // قسّم الرقم على 2 للانتقال إلى الرقم التالي
                        base = base * 10; // زيادة القاعدة بمقدار 10 في كل تكرار
                    }
                    cout << "القيمة بالنظام الثنائي (Binary): " << binary << endl;
                    validInput = true ;
                break;
                case 4:
                    while (the_number > 0) {
                        int remainder = the_number % which_digit_to ; // الباقي عند قسمة الرقم على 2
                        quaternary = quaternary + (remainder * base ); // ضع الباقي في المتغير الثنائي
                        the_number = the_number / which_digit_to ; // قسّم الرقم على 2 للانتقال إلى الرقم التالي
                        base = base * 10; // زيادة القاعدة بمقدار 10 في كل تكرار
                    }
                    cout << "القيمة بالنظام الرباعي (Quaternary) : " << quaternary << endl;
                    validInput = true ;
                    break;

                case 8:
                    while (the_number > 0) {
                        int remainder = the_number % which_digit_to ; // الباقي عند قسمة الرقم على 2
                        octal = octal + (remainder * base ); // ضع الباقي في المتغير الثنائي
                        the_number = the_number / which_digit_to ; // قسّم الرقم على 2 للانتقال إلى الرقم التالي
                        base = base * 10; // زيادة القاعدة بمقدار 10 في كل تكرار
                    }
                    cout << "القيمة بالنظام الثماني (Octal) : " << octal  << endl;
                    validInput = true ;
                    break;
                case 10:
                    cout << "القيمة بالنظام العشري (Decimal) " << the_number << endl;
                    validInput = true ;
                    break;
                case 16:
                    while (the_number > 0) {
                        int remainder = the_number % 16;
                        char hexChar;
                        if (remainder < 10) {
                            hexChar = remainder + '0';
                        } else {
                            hexChar = remainder - 10 + 'A';
                        }
                        hexadecimal = hexChar + hexadecimal;
                        the_number /= 16;
                    }
                    cout << "القيمة بالنظام السداسي عشر (Hexadecimal) : " << hexadecimal <<endl;
                    validInput = true ;
                    break;
                default:
                    cout << " عذراً , القيمة غير صالحة... :" << endl;
                break;
            } 
        }
    }
}