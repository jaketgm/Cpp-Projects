#include <iostream>
#include <cmath>

int main()
{
    int guess;
    int num = 5;
    int numGuesses = 0;
    bool result = true;

    do
    {
        std::cout << "Enter a num: ";
        std::cin >> guess;

        if (guess == num)
        {
            result = true;
            std::cout << "You found the number!!";
        }
        else
        {
            result = false;
            numGuesses++;
        }

    } while (result == false && numGuesses < 3);

    if (numGuesses == 3)
    {
        std::cout << "You ran out of guesses :(";
    }

    return 0;
}