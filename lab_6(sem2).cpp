#include <iostream>


std::string cities[10] = {
    "Bento",
    "Canoas",
    "Caxias",
    "Erechim",
    "Kola",
    "Lajeado",
    "Bruhn",
    "Pato",
    "Poetto",
    "Slell"
};

std::string cars[10] = {
    "Audi",
    "BMW",
    "Chevrolet",
    "Fiat",
    "Ford",
    "Honda",
    "Hyundai",
    "Kia",
    "Mazda",
    "Mercedes"
};
struct Numbers {
    int number;
    Numbers* next;
}*head = nullptr, *tail = nullptr;

struct Cities {
    std::string name;
    int distance;
    Cities* next;
}*citiesHead = nullptr, *citiesTail = nullptr;

struct Cars {
    std::string brand;
    int year;
    int price;
    Cars* next;
}*carsHead = nullptr, *carsTail = nullptr;

void addCity(std::string name, int distance) {
    Cities* newCity = new Cities;
    newCity->name = name;
    newCity->distance = distance;
    newCity->next = nullptr;
    if (citiesHead == nullptr)
    {
        citiesHead = newCity;
        citiesTail = newCity;
    }
    else
    {
        citiesTail->next = newCity;
        citiesTail = newCity;
    }
}

void addCar(std::string brand, int year, int price){
    Cars* newCar = new Cars;
    newCar->brand = brand;
    newCar->year = year;
    newCar->price = price;
    newCar->next = nullptr;
    if (carsHead == nullptr)
    {
        carsHead = newCar;
        carsTail = newCar;
    }
    else
    {
        carsTail->next = newCar;
        carsTail = newCar;
    }

}

void addNumber(int number) {
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = nullptr;
    if (head == nullptr)
    {
        head = newNumber;
        tail = newNumber;
    }
    else
    {
        tail->next = newNumber;
        tail = newNumber;
    } 
}

void fillList(int size){
    for (int i = 0; i < size; i++){
        addNumber(rand() % 100);
    }
}

double findAverage(Numbers* head){
    Numbers* temp = head;
    double sum = 0;
    int count = 0;
    while (head != nullptr){
        sum += head->number;
        count++;
        head = head->next;
    }
    return sum / count;
}

void deleteEvenNumbers(Numbers*& head){ 
    while (head && head->number % 2 == 0){
        Numbers* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    if (!head)
        return;
    Numbers* temp = head;
    while (temp != nullptr && temp->next != nullptr){
        if (temp->next->number % 2 == 0){
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
            temp = temp->next;
    }
}

void deleteNumberWithValue(Numbers*& head, int value){
    Numbers* temp = head;
    while (temp != nullptr){
        if (temp->number == value){
            Numbers* toDelete = temp;
            temp = temp->next;
            head = temp;
            delete toDelete;
            return;
            break;
        }
        if (temp->next->number == value){
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
            break;
        }
        temp = temp->next;
    }
}

void clearList(){
    Numbers* temp = head;
    while (temp != nullptr){
        Numbers* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

void showList(Numbers* head){
    Numbers* temp = head;
    while (temp != nullptr){
        std::cout << temp->number << (temp->next == nullptr ? " " : "->");
        temp = temp->next;
    }
    std::cout << "\n";
}


int main() {
    srand(time(0));
    while (1)
    {
        std::cout << "Enter number of task(1-3, 0 for exit):\n";
        int num;
        std::cin >> num;
        switch (num)
        {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter number of cities:\n";
                int num;
                std::cin >> num;
                if (num <=0){
                    std::cout << "List should contain at least 1 element\n";
                    break;
                }
                for (int i = 0; i < num; i++){
                    addCity(cities[rand() % 10], rand() % 10000 + 200);
                }
                Cities* temp = citiesHead;
                Cities* maxDistance = temp;
                Cities* secondMaxDistance = temp;
                while (temp != nullptr){
                    if (temp->distance > maxDistance->distance){
                        secondMaxDistance = maxDistance;
                        maxDistance = temp;
                    }
                    else if (temp->distance > secondMaxDistance->distance){
                        secondMaxDistance = temp;
                    }
                    std::cout << "City: " << temp->name << "\nDistance: " << temp->distance << "\n";
                    temp = temp->next;
                }
                std::cout << "City with max distance: " << maxDistance->name << " " << maxDistance->distance << "\n";
                std::cout << "City with second max distance: " << secondMaxDistance->name << " " << secondMaxDistance->distance << "\n";
                std::cout << "Enter name of city and distance to add:\n";
                std::string name;
                int distance;
                std::cin >> name >> distance;
                if (distance <= 0){
                    std::cout << "Distance should be greater than 0\n";
                    break;
                }
                addCity(name, distance);
                temp = citiesHead;
                while (temp != nullptr){
                    std::cout << "City: " << temp->name << "\nDistance: " << temp->distance << "\n";
                    temp = temp->next;
                }
                clearList();
            }   
            break;
            case 2:
            {
                std::cout << "Enter number of cars and current year:\n";
                int num, currentYear;
                std::cin >> num >> currentYear;
                if (currentYear < 1965){
                    std::cout << "Cars in our garage only from after 1965\n";
                    break;
                }
                if (num <=0){
                    std::cout << "List should contain at least 1 element\n";
                    break;
                }
                for (int i = 0; i < num; i++){
                    addCar(cars[rand() % 10], rand() % 61 + 1965, rand() % 10000 + 2000);
                }
                Cars* temp = carsHead;
                std::cout << "List of cars:\n";
                int counterForCars = 0;
                while (temp){
                    if (temp->year < currentYear - 10 && temp->price < 5000)
                        counterForCars++;
                    std::cout << "----------------\n";
                    std::cout << "Brand: " << temp->brand << "\nYear: " << temp->year << "\nPrice: " << temp->price << "\n";
                    temp = temp->next;

                }
                if (counterForCars == 0){
                    std::cout << "There are no cars older than 10 years and cheaper than 5000\n";
                    break;
                }
                else{
                    std::cout << "List with cars older than 10 years and cheaper than 5000:\n";
                    temp = carsHead;
                    while (temp){
                        if (temp->year < currentYear - 10 && temp->price < 5000){
                            std::cout << "----------------\n";
                            std::cout << "Brand: " << temp->brand << "\nYear: " << temp->year << "\nPrice: " << temp->price << "\n";
                        }
                        temp = temp->next;
                    }
                }   
                clearList();
            }
            break;
            case 3:
            {
                std::cout << "Enter number of elements in list:\n";
                int num;
                std::cin >> num;
                if (num <=0){
                    std::cout << "List should contain at least 1 element\n";
                    break;
                }
                fillList(num);
                std::cout << "Your list: \n";
                showList(head);
                Numbers* temp = head;
                std::cout << "numbers with duplicates: \n";
                int* duplicates = new int[num];
                int i = 0;
                int counter = 0;
                while (temp){
                    bool foundDuplicate = false;
                    Numbers* secondTemp = temp->next;
                    while(secondTemp){
                        if (temp->number == secondTemp->number){
                            foundDuplicate = true;
                            break;
                        }
                        secondTemp = secondTemp->next;
                    }

                    if (foundDuplicate) {
                        bool alreadyPrinted = false;
                        for (int j = 0; j < i; j++) {
                            if (duplicates[j] == temp->number) {
                                alreadyPrinted = true;
                                break;
                            }
                        }
                        if (!alreadyPrinted) {
                            std::cout << temp->number << " ";
                            duplicates[i++] = temp->number;
                        }
                    }
                    temp = temp->next;
                }
                std::cout << "\n";
                deleteEvenNumbers(head);
                std::cout << "List after deleting even numbers: \n";
                showList(head);
                clearList();
                delete[] duplicates;
            }
            break;
            default:
            std::cout << "Invalid number of task\n";
        }
    }
    return 0;
}