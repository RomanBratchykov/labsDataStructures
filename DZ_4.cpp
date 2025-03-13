#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>


struct train {
    std::string station;
    std::string departure;
    int distance;
    int num;
    std::string type;
};

const int SIZE = 10;

std::string stations[SIZE] = {
    "Kyiv", "Kharkiv", "Lviv", "Odesa", "Dnipro",
    "Zaporizhzhia", "Vinnytsia", "Poltava", "Chernihiv", "Cherkasy"
};

std::string departures[SIZE] = {
    "Kyiv", "Kharkiv", "Lviv", "Odesa", "Dnipro",
    "Zaporizhzhia", "Vinnytsia", "Poltava", "Chernihiv", "Cherkasy"
};

int distances[SIZE] = {
    500, 700, 300, 800, 600,
    400, 200, 100, 900, 1000
};

int nums[SIZE] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

std::string types[3] = {
    "Passenger", "Freight", "Highspeed"
};

int main()
{
    std::cout << "Enter number of trains: " << "\n";
    int num;
    std::cin >> num;
    
    train trains[num];
    for (int i = 0; i < num; i++){
        trains[i].station = stations[rand() % SIZE];
        trains[i].departure = departures[rand() % SIZE];
        trains[i].distance = distances[rand() % SIZE];
        trains[i].num = nums[rand() % SIZE];
        trains[i].type = types[rand() % 3];
    }
    std::cout << "Your trains: \n";
    std::cout << "Station\tDeparture\tDistance\tNumber\tType\n";
    double averageDistance = 0;
    int numOfPassenger = 0;
    int numOfFreight = 0;
    int numOfHighSpeed = 0;
    for (int i = 0; i < num; i++){
        if (trains[i].type == "Passenger")
            numOfPassenger++;
        if (trains[i].type == "Freight")
            numOfFreight++;
        if (trains[i].type == "Highspeed")
            numOfHighSpeed++;
        averageDistance += trains[i].distance;
        std::cout << trains[i].station << "\t" << trains[i].departure << "\t" << trains[i].distance << "\t" << trains[i].num << "\t" << trains[i].type << "\n";
    }
    std::cout << "=================================================================================\n";
    std::cout << "Average distance = " << averageDistance / num << "\n";\
    std::cout << "Number of passenger trains = " << numOfPassenger << "\n";
    std::cout << "Number of freight trains = " << numOfFreight << "\n";
    std::cout << "Number of highspeed trains = " << numOfHighSpeed << "\n";
}