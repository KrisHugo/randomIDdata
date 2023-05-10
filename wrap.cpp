#include <iostream>
#include "constant.cpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>
#include "calender.cpp"

// 将随机的身份信息存储到json格式中
#include "import/configor/json.hpp"
using namespace configor;

// random ID numbers
using namespace std;

int main(){
    json j = json::parse("[{\"name\":\"阿3\",\"people\":{\"address\":\"安徽省淮北市市辖区\",\"addressID\":\"340601\",\"birth\":\"1994-01-06\",\"gender\":\"1\",\"id\":\"340601199401068714\"}},{\"name\":\"阿4\",\"people\":{\"address\":\"广西壮族自治区桂林市龙胜各族自治县\",\"addressID\":\"450328\",\"birth\":\"1929-12-09\",\"gender\":\"0\",\"id\":\"450328192912098103\"}}]");
    std::cout << j;
}