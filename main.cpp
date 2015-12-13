#include <iostream>
#include <ctype.h>
#include <cstdlib>

#include "romanArabic.h"

using namespace std;

int main(){

  cout << "Enter valid roman numerals or arabic numerals between 1 and 3999." << endl;

  string test;
  getline(cin, test);

  while(test[0] != '\0'){
    bool stringOrInt = true;

    for(int i = 0; i < test.size(); i++){
      if(!isdigit(test[i]) && stringOrInt == true)
      	stringOrInt = false;
    }

    if(stringOrInt == true){
      int arabicTest = atoi(test.c_str());

      romanArabic romar(arabicTest);

      if(romar.isArabicValid())
       cout << arabicTest << " as a roman numeral is " << romar.toString() << endl << endl;
    } else {
    romanArabic romar(test);

    if(romar.isRomanValid())
     cout << test << " as an arabic numeral is " << romar.toInt() << endl << endl;
    }

    getline(cin, test);
  }

  cout << "closing" << endl;
  return 0;
}
