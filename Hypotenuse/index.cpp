#include <iostream>
#include <cmath>

int main()
{
    double a;
    double b;
    double c;
    std::string proceed;
    
    do 
    {
        std::cout << "Enter a value for a: ";
        std::cin >> a;
        std::cout << "\nEnter a value for b: ";
        std::cin >> b;
        
        c = sqrt(pow(a, 2) + pow(b, 2));

        std::cout << "\nThe Hypotenuse is: " << c;

        std::cout << "\nDo you wish to proceed (yes/no): ";
        std::getline(std::cin >> std::ws, proceed);
    } while (proceed == "yes");

    std::cout << "Thanks!";

    return 0;
}