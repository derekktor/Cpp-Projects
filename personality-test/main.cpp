#include <iostream>
#include <fstream>

int main(void) {
    std::string name;
    int age;

    int open = 0;
    int con = 0;
    int ext = 0;
    int agr = 0;
    int neu = 0;

    int answer;

    std::cout << "Your name: ";
    std::cin >> name;
    std::cout << "Your age: ";
    std::cin >> age;

    std::cout << "I have a kind word for everyone." << std::endl;
    std::cin >> answer;
    if (answer == 1) open++; ext++; agr++;


    std::cout << "I am always prepared." << std::endl;
    std::cin >> answer;
    if (answer == 1) con++; neu++;


    std::cout << "I feel comfortable around people." << std::endl;
    std::cin >> answer;
    if (answer == 1) ext++; open++;


    std::cout << "I often feel blue." << std::endl;
    std::cin >> answer;
    if (answer == 1) neu++;


    std::cout << "I believe in the importance of art." << std::endl;
    std::cin >> answer;
    if (answer == 1) open++; agr++;


    std::cout << "I feel I am better than other people." << std::endl;
    std::cin >> answer;
    if (answer == 1) con++; open++; ext++;


    std::cout << "I avoid taking on a lot of responsibility." << std::endl;
    std::cin >> answer;
    if (answer == 1) ext++; neu++;


    std::cout << "I make friends easily." << std::endl;
    std::cin >> answer;
    if (answer == 1) ext++; open++;


    std::cout << "There are many things that I do not like about myself." << std::endl;
    std::cin >> answer;
    if (answer == 1) neu++; con++;


    std::cout << "I am interested in the meaning of things." << std::endl;
    std::cin >> answer;
    if (answer == 1) con++; open++;


    std::cout << "I treat everyone with kindness and sympathy." << std::endl;
    std::cin >> answer;
    if (answer == 1) open++; ext++;


    std::cout << "I get chores done right away." << std::endl;
    std::cin >> answer;
    if (answer == 1) con++; neu++;


    std::cout << "I am skilled in handling social situations." << std::endl;
    std::cin >> answer;
    if (answer == 1) open++; ext++;


    std::cout << "I am often troubled by negative thoughts." << std::endl;
    std::cin >> answer;
    if (answer == 1) neu++;


    std::cout << "I enjoy going to art museums." << std::endl;
    std::cin >> answer;
    if (answer == 1) open++;


    std::cout << "I accept people the way they are." << std::endl;
    std::cin >> answer;
    if (answer == 1) agr++;


    std::cout << "It’s important to me that people are on time." << std::endl;
    std::cin >> answer;
    if (answer == 1) con++;


    std::cout << "I am the life of the party." << std::endl;
    std::cin >> answer;
    if (answer == 1) ext++;


    std::cout << "My moods change easily." << std::endl;
    std::cin >> answer;
    if (answer == 1) neu--;


    std::cout << "I have a vivid imagination" << std::endl;
    std::cin >> answer;
    if (answer == 1) open++;

    std::cout << "Go to file output.txt to see your results\n";

    std::string inFName = "base.txt";
    std::ofstream inFPtr;

    inFPtr.open(inFName.c_str(), std::ios_base::app);

    // inFPtr << "Name\tAge\t\tOp\tCo\tEx\tAg\tNe\n";

    if (inFPtr.is_open())
    {
        std::cout << inFName << " is open.\n";

        inFPtr << name << "\t" << age << "\t\t"
                << open << "\t" << con << "\t"
                << ext << "\t" << agr << "\t"
                << neu << std::endl;

    }
    else
        std::cout << "Error: " << inFName << " can't be opened!\n";

    inFPtr.close();
    std::cout << inFName << " is closed.\n";
    return 0;
}