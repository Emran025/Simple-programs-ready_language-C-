#include <iostream> 
#include <string> 
#include <bitset>
using namespace std;

int main(){

    long long ACQL_NUMBER =0 ;
    bool validInput;
    string text ;
    string the_numer_cods = "" ;
    int the_cods ;
    string bcd [] = { "  0000","  0001","  0010","  0011","  0100","  0101","  0110","  0111","  1000","  1001" } ;
    string bca [] = { "  0000","  0111","  0110","  0101","  0100","  1011","  1010","  1001","  1000","  1111" } ;
    string bcb [] = { "  0000","  0001","  0010","  0011","  0100","  1011","  1100","  1101","  1110","  1111" } ;
    
    validInput = false ; 
    while (!validInput){
        cout<<"which the code you want"<<endl; 
        cout<<"for [8,4,2,1] write 1 : "<<endl;
        cout<<"for [8,4,-2,-1] write 2 : "<<endl;
        cout<<"for [2,4,2,1] write 3 : "<<endl;
        cout<<"for change the text to ACQL code write 4: "<<endl;
        cin >> the_cods;
        switch (the_cods) {
            case 1 :
            case 2:
            case 3:
            case 4:
                validInput = true ;
            break;

            default:
                cout << " the nuber is not true , pleas try agine :";
            break;
        }
    }
    validInput = false ; 
    while (!validInput) {
        cout << "Enter a number: ";
        getline(cin, text);
        the_numer_cods = "";
        // تفصيل العدد إلى أرقامه وتخزينها في المصفوفات
        for (char c : text) { 
            ACQL_NUMBER = static_cast<int>(c) - 48;
            if ( the_cods == 1 && ACQL_NUMBER >= 0 && ACQL_NUMBER <= 9 ) {
                the_numer_cods += bcd [ACQL_NUMBER ];
                validInput = true ;
            } else if ( the_cods == 2 && ACQL_NUMBER >= 0 && ACQL_NUMBER <= 9 ) {
                the_numer_cods += bca [ACQL_NUMBER ];
                validInput = true ;
            } else if ( the_cods == 3 && ACQL_NUMBER >= 0 && ACQL_NUMBER <= 9 ) {
                the_numer_cods += bcb [ACQL_NUMBER ];
                validInput = true ;
            } else if ( the_cods == 4 && ACQL_NUMBER >= -7 && ACQL_NUMBER <= 79 ){
                the_numer_cods += to_string(ACQL_NUMBER+48)+ "  ";
                validInput = true ;
            } else {
                the_numer_cods = "";
                validInput = false ;
                cout << "this is not number, try agin ";
                break;
            }
        }
    }
    cout << the_numer_cods ;
}