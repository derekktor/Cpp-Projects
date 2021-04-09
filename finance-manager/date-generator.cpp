// Random date generator

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> // setw(int)
#include <stdlib.h> // srand(int seed), rand()

class Day
{
private:
    int year;
    int month;
    int day;
public:
    void getDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
};

int main(void) {

    Day d[10];
    float t[10];

    for (int i = 0; i < 10; i++)
    {
        int yRand = rand() % 2 + 2019;
        int mRand = rand() % 12 + 1;
        int dRand = rand() % 31 + 1;
        t[i] = rand() % 100;
        d[i].getDate(yRand, mRand, dRand);
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << d[i].getYear() << "/" << d[i].getMonth() << "/" << d[i].getDay() << "\t" << t[i] << "\n";
    }
    
    std::string myFile = "query.txt";
    std::ofstream outFile;

    outFile.open(myFile.c_str());

    if (outFile.is_open())
    {
        std::cout << "It is open\n";
        outFile << "Date" << "\t\t\t"
                << "Total" << "\t\t\t"
                << "List" << std::endl;

        for (int i = 0; i < 10; i++)
        {
            outFile << d[i].getYear() << "/" << d[i].getMonth() << "/" << d[i].getDay() << "\t\t" << t[i] << std::endl;
        }
        
    }


    outFile.close();

    return 0;
}