#include <stdio.h>

int isYearLeap (int year) {
    return ( ( year % 4 == 0 && year % 100 != 0 && year % 4000 != 0) || (year % 100 == 0 && year % 400 == 0 && year % 4000 != 0) );
}

int dayOfWeek ( int year, int month, int day ) {
    int yearCode, centuryCode, counter = 0, yearLastDigits, dayCode;
    int monthsCode[13] = {0, 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    int centuriesCode[4] = {4, 2, 0, 6};
    int century = year / 100;
    for ( int i = 0; i < century - 17; i++ ) {
        counter ++;
    }
    centuryCode = centuriesCode[counter % 4];
    yearLastDigits = year % 100;
    yearCode = (centuryCode  + yearLastDigits + (yearLastDigits / 4)) % 7;
    dayCode = (day + monthsCode[month] + yearCode) % 7;
    
  
    if ( dayCode <= 1 )
        dayCode += 6;
       else
           dayCode -= 1;
             
    if (isYearLeap(year) && month <= 2 ) {
        dayCode -= 1;
    }
    
    if ( dayCode == 0 ) {
        dayCode = 7;
    }
    return dayCode;
}


int main ( void ) {
    int day = dayOfWeek ( 2024, 6, 7);
    // priklad, 7.6.2024 je patek
    printf ( "7.6.2024 je %d\n", day);
}
