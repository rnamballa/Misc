// Num2s.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>

// Program to calculate number of 2's (digits) in numbers from 0 to n. 
// For example, number of 2's in 0 to 3 is 1.
// Number of 2's in 0 to 23 is 7 - 2, 12, 20, 21, 22, 23.
int main(int argc, char* argv[])
{
    if (argc < 2)
        return -1;

    int n = atoi(argv[1]);
    int count = 0;

    // Iterate through each digit of the number and aggregate the number of 2's.
    for (int i = 0; i <= log10(n); i++)
    {
        int pos = pow(10, i);
        int nextPos = pow(10, i + 1);

        int div = n / pos;
        int div1 = n / (pos * 10);
        //int digit = div - div1 * 10;

        int digit = (n / pos) % 10;

        int roundDown = n - n % nextPos;
        int roundUp = roundDown + nextPos;

        if (digit < 2)
        {
            count += roundDown / 10;
        }
        else if (digit > 2)
        {
            count += roundUp / 10;
        }
        else if (digit == 2)
        {
            count += roundDown / 10 + n % pos + 1;
        }
    }

    std::cout << "Num 2s in 1 to " << std::to_string(n) << " = " + std::to_string(count) << "\n";
}
