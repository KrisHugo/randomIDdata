#include <iostream>
#include "constant.cpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include "calender.cpp"
#include <fstream>
// 将随机的身份信息存储到json格式中
// #include "import/configor/configor_serializer.hpp"
#include "import/configor/json.hpp"

using namespace configor;

// random ID numbers
using namespace std;

string randomID();
string jsonRandomID();
string GetCheckDigit(string id);
int randomInt(int max, int min);
string GetRandomNums(int num, int length);
string fillNumLength(string str, int length);
int main()
{
    int nums;
    cin >> nums;
    srand(time(0));
    vector<json> jsonIDs;
    json IDs;
    for (int i = 0; i < nums; i++)
    {
        // string id = randomID();
        // if (id.empty())
        // {
        //     cout << "random ID goes wrong";
        //     exit(-1);
        // }
        // else
        //     cout << "ID: " << id << endl;
        json temp = jsonRandomID();
        if (temp.empty())
        {
            cout << "random ID goes wrong";
            exit(-1);
        }
        else
        {
            cout << "ID: " << temp << endl;
            // json user = {{"name","阿"+to_string(i+1)}, {"people", temp}};
            // IDs.push_back(user);
            // jsonIDs.push_back(user);
            IDs.push_back(json(temp));
            // IDs.push_back(json(user));
        }  

        // std::ofstream ofstream("./output.json");
        // ofstream << IDs << endl;
    }
    IDs.dump(); 
    cout << IDs;

    std::ofstream ofs("./output.json");
    ofs << IDs << endl;

}
/*
ID 430 210 1998 01 01 00 0 1
6 + 4 + 4 + 2 + 1 + 1
address(6)[xxx-xxx] + birth(8)[xxxx-xx-xx] + order(2)[00-99] + gender(1)[0-1] + check_digit(1)[0-9X]
*/
string jsonRandomID()
{
    // json ID;
    int area_id = AREA_ID[rand() % AREA_ID.size()];
    string address_digit = fillNumLength(to_string(area_id), 6);
    cout << "addressID:" << address_digit << ", address:" << AREA_INFO[area_id] << endl;
    int year = randomInt(2022, 1900);
    string birth_year_digit = GetRandomNums(year, 4);
    int month = randomInt(12, 1);
    string birth_month_digit = GetRandomNums(month, 2);
    string birth_day_digit = GetRandomNums(randomInt(getDays(year, month), 1), 2);
    string birth_digit = birth_year_digit + birth_month_digit + birth_day_digit;
    // cout << "year:" << birth_year_digit << endl;
    // cout << "month:" << birth_month_digit << endl;
    // cout << "day:" << birth_day_digit << endl;
    cout << "birth:" << birth_digit << endl;
    string order_digit = GetRandomNums(randomInt(99, 0), 2);
    cout << "order:" << order_digit << endl;
    string gender_digit = to_string(rand() % 2);
    cout << "gender:" << gender_digit << endl;
    string id = address_digit + birth_digit + order_digit + gender_digit;

    string check_digit = GetCheckDigit(id);
    if (check_digit.empty())
    {
        return json();
    }
    cout << "check:" << check_digit << endl;
    id += check_digit;

    // ID["id"] = id;
    // ID["addressID"] = address_digit;
    // ID["address"] = AREA_INFO[area_id];
    // ID["birth"] = birth_year_digit + "-" + birth_month_digit + "-" + birth_day_digit;
    // ID["gender"] = gender_digit;
    return id;
    // return string(id);
}

string randomID()
{
    int area_id = AREA_ID[rand() % AREA_ID.size()];
    string address_digit = fillNumLength(to_string(area_id), 6);
    cout << "addressID:" << address_digit << ", address:" << AREA_INFO[area_id] << endl;
    int year = randomInt(2022, 1900);
    string birth_year_digit = GetRandomNums(year, 4);
    int month = randomInt(12, 1);
    string birth_month_digit = GetRandomNums(month, 2);
    string birth_day_digit = GetRandomNums(randomInt(getDays(year, month), 1), 2);
    string birth_digit = birth_year_digit + birth_month_digit + birth_day_digit;
    // cout << "year:" << birth_year_digit << endl;
    // cout << "month:" << birth_month_digit << endl;
    // cout << "day:" << birth_day_digit << endl;
    cout << "birth:" << birth_digit << endl;
    string order_digit = GetRandomNums(randomInt(99, 0), 2);
    cout << "order:" << order_digit << endl;
    string gender_digit = to_string(rand() % 2);
    cout << "gender:" << gender_digit << endl;
    string id = address_digit + birth_digit + order_digit + gender_digit;

    string check_digit = GetCheckDigit(id);
    if (check_digit.empty())
    {
        return string();
    }
    cout << "check:" << check_digit << endl;
    id += check_digit;
    return string(id);
}

int randomInt(int max, int min)
{
    return rand() % (max - min + 1) + min;
}

string GetRandomNums(int num, int length)
{
    string str = fillNumLength(to_string(num), length);
    return str;
}

string fillNumLength(string str, int length)
{
    while (str.size() < length)
    {
        str = "0" + str;
    }
    return str;
}

string GetCheckDigit(string id)
{
    if (id.length() < 17)
    {
        return string();
    }
    int sum = 0, digit;
    for (int i = 0; i < 17; i++)
    {
        sum += (((1 << (17 - i)) % 11) * int(id[i]));
    }
    digit = (12 - (sum % 11)) % 11;
    return (digit < 10) ? to_string(digit) : "X";
}
