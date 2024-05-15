#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    " ",
    "\n\n\nJanuary", "\n\n\nFebruary", "\n\n\nMarch",
    "\n\n\nApril", "\n\n\nMay", "\n\n\nJune", "\n\n\nJuly",
    "\n\n\nAugust", "\n\n\nSeptember", "\n\n\nOctober",
    "\n\n\nNovember", "\n\n\nDecember"
};

int inputyear(void)
{
    int year;
    cout << "Please enter a year (example: 1999): ";
    cin >> year;
    return year;
}

int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

int determineleapyear(int year)
{
    if (year % 4 == FALSE && year % 100 != FALSE || year % 400 == FALSE)
    {
        days_in_month[2] = 29;
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        return FALSE;
    }
}

void calendar(int year, int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        cout << months[month];
        cout << "\n\nSun Mon Tue Wed Thu Fri Sat\n";
        for (day = 1; day <= 1 + daycode * 5; day++)
        {
            cout << " ";
        }
        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%2d", day);
            if ((day + daycode) % 7 > 0)
                cout << " ";
            else
                cout << "\n ";
        }
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void)
{
    int year, daycode;
    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calendar(year, daycode);
    cout << "\n";
    return 0;
}

