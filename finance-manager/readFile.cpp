#include <iostream>
#include <fstream>
#include <string>

int main(void) {
    const char* inFileName = "input.txt";
    std::ifstream inFilePtr(inFileName);

    std::string presentFileName = "presentation.txt";
    std::ofstream presentFilePtr;
    presentFilePtr.open(presentFileName.c_str());

    if (presentFilePtr.is_open())
    {
        presentFilePtr << "Date\t\t\tType\t\t\tCost\t\t\tDescription\n";
    } else
        std::cout << "Error: File can't be opened <" << presentFileName << ">\n";
    

    std::string bFileName = "balance.txt";
    std::ofstream balanceFilePtr;
    balanceFilePtr.open(bFileName.c_str());

    if (balanceFilePtr.is_open())
    {
        balanceFilePtr << "Month\t\tCost\n";
    } else
        std::cout << "Error: File can't be opened <" << bFileName << ">\n";

    int dates;
    int year, month, day;
    std::string type;
    std::string description;
    double costs;
    double total = 0;

    double balMonthly[13];

    if (inFilePtr.is_open())
    {
        std::cout << "File opened: " << inFileName << std::endl;

        while (!inFilePtr.eof())
        {
            inFilePtr >> dates;
            inFilePtr.ignore();

            std::getline(inFilePtr, type);

            inFilePtr >> costs;
            inFilePtr.ignore();

            std::getline(inFilePtr, description);

            year = dates / 10000;
            month = dates / 100 % 100;
            day = dates % 100;

            if (type == "plus")
            {
                total += costs;
                balMonthly[month] += costs;
            }
            else
            {
                total -= costs;
                balMonthly[month] -= costs;
            }

            presentFilePtr << year << "/" << month << "/" << day << "\t\t"
                    << type << "\t\t\t"
                    << total << "\t\t\t"
                    << description << std::endl;
        }
        for (int i = 0; i < 12; i++)
        {
            balanceFilePtr << i + 1 << "\t\t\t" << balMonthly[i] << std::endl;
        }
        
        balanceFilePtr << "Total\t\t" << total << std::endl;
    }
    else
        std::cout << "Error: " << inFileName << " can't be opened!!!\n";

    std::cout << "File closed: " << presentFileName << std::endl;
    presentFilePtr.close();
    std::cout << "File closed: " << bFileName << std::endl;
    balanceFilePtr.close();
    std::cout << "File closed: " << inFileName << std::endl;
    inFilePtr.close();

    return 0;
}