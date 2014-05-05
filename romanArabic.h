#ifndef ROMANARABIC_H
#define ROMANARABIC_H

#include <iostream>
#include <string>

using namespace std;

#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1

class romanArabic{
  int arabic;
  string roman;
  bool arabicValid;
  bool romanValid;
  void checkPosition(int pos, int value, char checkChar, string prev, string next);
 public:
  bool isArabicValid();
  bool isRomanValid();
  romanArabic(string romanForFormat);
  romanArabic(int arabicForFormat);
  int toInt();
  string toString();
};

romanArabic::romanArabic(string romanForFormat){
  roman = romanForFormat;
  arabicValid = true;
  
  if(roman[0] != 'M' && roman[0] != 'D' && roman[0] != 'C' && roman[0] != 'L' && roman[0] != 'X' 
     && roman[0] != 'V' && roman[0] != 'I')
    romanValid = false;
  else{
    arabic = 0;
    romanValid = true;
  }

  
  for(int i = 0; i < roman.size() && romanValid; i++){
    if(romanValid){
      if(roman[i] == 'M')
	arabic += M;
      else if(roman[i] == 'D')
	checkPosition(i, D, 'D', "", "DCLXVI");
      else if(roman[i] == 'C')
	checkPosition(i, C, 'C', "MD", "CLXVI");
      else if(roman[i] == 'L')
	checkPosition(i, L, 'L', "", "LXVI");
      else if(roman[i] == 'X')
	checkPosition(i, X, 'X', "CL", "XVI");
      else if(roman[i] == 'V')
	checkPosition(i, V, 'V', "", "VI");
      else
	checkPosition(i, I, 'I', "XV", "I");
    }
  }
  if(!romanValid){
    cout << "Invalid input." << endl << endl;
    arabic = -1;
  }
}

romanArabic::romanArabic(int arabicForFormat){
  arabic = arabicForFormat;
  arabicValid = true;
  romanValid = true;
  if(arabic > 3999 || arabic < 1)
    arabicValid = false;
  roman = "";
  
  if(arabicValid){
    for(int i = 0; arabic != 0; i++){
      if(arabic >= M){
	arabic -= M;
	roman.push_back('M');
      }
      else if(arabic >= M-C){
	arabic -= M-C;
	roman.push_back('C');
	roman.push_back('M');
      }
      else if(arabic >= D){
	arabic -= D;
	roman.push_back('D');
      }
      else if(arabic >= D-C){
	arabic -= D-C;
      roman.push_back('C');
      roman.push_back('D');
      }
      else if(arabic >= C){
	arabic -= C;
	roman.push_back('C');
      }
      else if(arabic >= C-X){
	arabic -= C-X;
	roman.push_back('X');
	roman.push_back('C');
      }
      else if(arabic >= L){
	arabic -= L;
	roman.push_back('L');
      }
      else if(arabic >= L-X){
	arabic -= L-X;
	roman.push_back('L');
	roman.push_back('X');
      }
      else if(arabic >= X){
	arabic -= X;
	roman.push_back('X');
      }
      else if(arabic >= X-I){
	arabic -= X-I;
	roman.push_back('I');
	roman.push_back('X');
      }
      else if(arabic >= V){
	arabic -= V;
	roman.push_back('V');
      }
      else if(arabic >= V-I){
	arabic -= V-I;
	roman.push_back('I');
	roman.push_back('V');
      }
      else{
	arabic -= I;
	roman.push_back('I');
      }
    } 
  }
  else{
    cout << "Invalid input." << endl << endl;
    roman = "invalid";
    romanValid = false;
  }
}

void romanArabic::checkPosition(int pos, int value, char checkChar, string prev, string next){
  bool shouldSubtract = false;
  bool shouldAdd = false;

  for(int i = 0; i < prev.size(); i++){
    if(roman[pos+1] == prev[i]){
      shouldSubtract = true;
    }
  }
  if(!shouldSubtract){
    for(int i = 0; i <= next.size(); i++){
      if(roman[pos+1] == next[i]){
	  shouldAdd = true;
      }
    }
  }

  if(pos+3 < roman.size()){
    if(roman[pos+3] == checkChar && roman[pos+2] == checkChar
       && roman[pos+1] == checkChar){
      romanValid = false;
    }
  }
  
  if(shouldSubtract){
    arabic -= value;
  }
  else if(shouldAdd){
    arabic += value;
  }
  else
    romanValid = false;
}

int romanArabic::toInt(){
    return arabic;
}

string romanArabic::toString(){
  return roman;
}

bool romanArabic::isRomanValid(){
  return romanValid;
}

bool romanArabic::isArabicValid(){
  return arabicValid;
}

#endif
