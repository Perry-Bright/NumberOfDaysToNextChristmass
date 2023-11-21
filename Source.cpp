#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;

 
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    Date() : year(0000), month(00), day(00) {}
};

int daysInMonth(int month, int year) {
    /*
    * 1 = JANUARY
    * 2 = FEBRUARY [28/29 depending]
    * 3 = MARCH 
    * 4 = APRIL [30 days]
    * 5 = MAY
    * 6 = JUNE [30 days]
    * 7 = JULY
    * 8 = AUGUST 
    * 9 = SEPTEMBER [30 days]
    * 10 = OCTOBER
    * 11 = NOVEMBER
    * 12 = DECEMBER
    
    */
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

int daysToNextChristmas(const Date& currentDate) {

   
    Date nextChristmas(currentDate.year, 12, 25);

    int daysRemaining = 0;
    // when christmas has passed 
    if (currentDate.month == 12 && currentDate.day > 25) {
        // we get the days left in december
        daysRemaining = 31 - currentDate.day;

        for (int month = 1; month < 12; ++month) {
            //the year section checks if the next years is a leap year, starting from the year other the current year
            daysRemaining += daysInMonth(month,currentDate.year+1);

        }

        // add 25 days to get to get to christ as we are in december anyhow you get it bro
        daysRemaining += nextChristmas.day;
    }

    else if (currentDate.month == 12 && currentDate.day < 25) {
       
        return daysRemaining = nextChristmas.day - currentDate.day;
    }

    else {
       
        daysRemaining += daysInMonth(currentDate.month, currentDate.year) - currentDate.day;
      for (int month = currentDate.month + 1; month < 12; ++month) {
            daysRemaining += daysInMonth(month,currentDate.year);

        }
      daysRemaining += nextChristmas.day;
    }


    return daysRemaining;
}

int main() {
    Date currentDate;
    cout << "Enter the current date (YYYY MM DD): ";
    cin >> currentDate.year >> currentDate.month >> currentDate.day;

    if (currentDate.month == 12 && currentDate.day == 25) {
        cout << "Merry Christmas \n";
    }
    else {
        int daysRemaining = daysToNextChristmas(currentDate);
        cout << daysRemaining << "Days remaining until  Christmas " << currentDate.year++  << endl;
    }
       

    return 0;
}
