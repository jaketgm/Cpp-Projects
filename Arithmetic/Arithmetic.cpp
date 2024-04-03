#include <iostream>
using namespace std;

int main() 
{
    int firstNum, secondNum, thirdNum, fourthNum, sumOfNums;

    cout << "Enter first two integers: ";
    cin >> firstNum >> secondNum;
    cout << "Enter another two integers: ";
    cin >> thirdNum >> fourthNum;

    sumOfNums = firstNum + secondNum / thirdNum + fourthNum;

    cout << firstNum << " + " << secondNum << " / " << thirdNum << " + " << fourthNum << " = " << sumOfNums;

    return 0;
}