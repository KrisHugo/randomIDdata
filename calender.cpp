
int isLeapYear(int year)
{
    if (year % 4 == 0)
        if (year % 100 == 0)
            if (year % 400 == 0) return 1;
            else return 0;
        else return 1;
    else return 0;
}

int getDays(int year, int month)
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return months[month-1] + isLeapYear(year);
}
