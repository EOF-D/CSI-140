/*
Author:                  Andy Zheng
Class:                   CSI-140-04
Assignment:              Week Eleven Assignment One - Fortune Teller
Date Assigned:           11/12/23
Due Date:                11/26/23

Description:
  Week 11 fortune teller program.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking)
*/

#include <ctime>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

const vector<string> ZODIACS = {
  "Capricorn",
  "Aquarius", 
  "Pisces", 
  "Aries", 
  "Taurus", 
  "Gemini",
  "Cancer", 
  "Leo", 
  "Virgo", 
  "Libra", 
  "Scorpio", 
  "Sagittarius"
};

const vector<string> FORTUNES = {
  "Your future is cloudy.",
  "Your future is bright.",
  "Your future is good!",
  "Expect a surprise today.",
  "Something good will show in your life soon.",
  "You will meet someone new today.",
  "Many business oppurtunities will come your way.",
  "You will be successful in your career.",
  "Your future is uncertain.",
  "You will be lucky today.",
};

struct Date {
  int day;
  int month;
  int year;
};


int parseAge(Date birthdate, Date currentdate) {
  int age = currentdate.year - birthdate.year;
  
  // Check if birthday hasnt happened yet.
  if (currentdate.month < birthdate.month || (currentdate.month == birthdate.month && currentdate.day < birthdate.day)) {
    age -= 1;
  }
    
  return age;
}

string getZodiac(Date birthdate) {
  int birthMonth = birthdate.month;
  int birthDay = birthdate.day;

  // Ternary as shortcut otherwise it gets really ugly.
  // Need switch for requirement.
  switch (birthMonth) {
    case 1:
      return (birthDay >= 21) ? "Aquarius" : "Capricorn";
    case 2:
      return (birthDay >= 20) ? "Pisces" : "Aquarius";
    case 3:
      return (birthDay >= 21) ? "Aries" : "Pisces";
    case 4:
      return (birthDay >= 21) ? "Taurus" : "Aries";
    case 5:
      return (birthDay >= 22) ? "Gemini" : "Taurus";
    case 6:
      return (birthDay >= 22) ? "Cancer" : "Gemini";
    case 7:
      return (birthDay >= 23) ? "Leo" : "Cancer";
    case 8:
      return (birthDay >= 22) ? "Virgo" : "Leo";
    case 9:
      return (birthDay >= 24) ? "Libra" : "Virgo";
    case 10:
      return (birthDay >= 24) ? "Scorpio" : "Libra";
    case 11:
      return (birthDay >= 23) ? "Sagittarius" : "Scorpio";
    case 12:
      return (birthDay >= 22) ? "Capricorn" : "Sagittarius";
    default:
      exit(1); // Unreachable.
  }
}

string getFortune() {
  // random fortune
  srand(time(NULL));
  return FORTUNES[rand() % FORTUNES.size()];
}

int main() {
  string rawDate;
  int day, month, year;

  cout << "Enter your birthdate (MM/DD/YYYY): ";
  getline(cin, rawDate);

  // check if date given has a valid format. (This is probably pretty naive)
  if (rawDate.length() != 10 || rawDate[2] != '/' || rawDate[5] != '/') {
    cout << "Invalid date format." << endl;
    return 1;
  }

  // Parse date into integers.
  day = stoi(rawDate.substr(3, 2));
  month = stoi(rawDate.substr(0, 2));
  year = stoi(rawDate.substr(6, 4));

  // Check if date is valid.
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
    cout << "Invalid input. Please enter a valid date." << endl;
    return 1;
  }

  // Create Date for birthdate.
  Date birthdate = {day, month, year};

  // Current day, month, year.
  int cDay, cMonth, cYear;

  // Using different method to get time because Appendix method isn't working.
  // https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  time_t rawTime = time(0);
  tm *timePtr = localtime(&rawTime);

  cDay = timePtr->tm_mday;
  cMonth = timePtr->tm_mon + 1;
  cYear = timePtr->tm_year + 1900;

  Date currentdate = {cDay, cMonth, cYear};

  // Getting age, sign and random fortune.
  int age = parseAge(birthdate, currentdate);
  string sign = getZodiac(birthdate);
  string fortune = getFortune();

  cout << "Your age is " << age << endl;
  cout << "Your sign is " << sign << endl;
  cout << "Your fortune is: " << fortune << endl;
    
  return 0;
}
