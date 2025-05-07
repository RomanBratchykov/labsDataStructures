#include <list>
#include <iostream>
#include <chrono>
#include <thread>
#include <exception>
#include <vector>
#include <iomanip>

class Transport{
    public:
    std::string type;
    std::string name;
    int year;
    Transport(std::string type, std::string name, int year){
        this->type = type;
        this->name = name;
        this->year = year;
    }
    ~Transport(){}
};

class Car : public Transport{
    int runningTotal;

    public:
    Car(std::string name, int year, int runningTotal) : Transport("Car", name, year){
        this->runningTotal = runningTotal;
    }
    void showCar(){
        std::cout << "Car name: " << name << ", year: " << year << ", running total: " << runningTotal << "\n";
    }
};
int main(){



}