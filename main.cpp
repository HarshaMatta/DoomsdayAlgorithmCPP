#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int doomsDay(int year) {
  int cenCode;
  switch ((year / 100) % 4) {
  case 0:
    cenCode = 2;
    break;

  case 1:
    cenCode = 0;
    break;

  case 2:
    cenCode = 5;
    break;

  case 3:
    cenCode = 3;
    break;
  }

  int a = (year % 100) / 12;

  int b = (year % 100) % 12;

  int c = b / 4;

  int doomsDay = (a + b + c + cenCode) % 7;

  return doomsDay;
}
int main() {
  int year;
  int month;
  int day;
  cout << "year : ";
  cin>>year;
  cout<<endl<<"month : ";
  cin>> month;
  cout<<endl<<"day : ";
  cin>> day;

  int doomsDate;

  string days[7] = {"sunday",   "monday", "tuesday", "wednesday",
                    "thursday", "friday", "saturday"};
  int doomsDays[12] = {3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};

  doomsDate = doomsDay(year);

  if (year % 400 == 0 && month <= 2 ||
      year % 100 != 0 && year % 4 == 0 && month <= 2) {
    cout << days[((7 + ((day - doomsDays[month - 1] + doomsDate - 1)) % 7)) % 7]
         << endl;
  } else {
    cout << days[((7 + ((day - doomsDays[month - 1] + doomsDate)) % 7)) % 7]
         << endl;
  }
}
