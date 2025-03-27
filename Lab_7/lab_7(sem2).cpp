#include <iostream>
#include <iomanip>
#include <cmath>

std::string holders[5] = {"CD", "Vinyl", "Tape", "Digital", "Streaming"};
std::string names[5] = {"Symphony No. 5", "The Four Seasons", "Moonlight Sonata", "Clair de Lune", "The Nutcracker Suite"};
std::string authors[5] = {"Beethoven", "Vivaldi", "Beethoven", "Debussy", "Tchaikovsky"};
double prices[5] = {10.99, 15.50, 12.75, 8.99, 20.00};
double durations[5] = {35.5, 40.0, 30.0, 25.0, 50.0};

std::string cities[5] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
std::string commands[5] = {"Serve", "Set", "Spike", "Block", "Dig"};


struct Numbers {
    double number;
    Numbers* next;
}*top = nullptr;

bool areEqual(double a, double b){
    return fabs(a - b) < 1e-9;
}

void push(double number) {
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = top;
    top = newNumber;
}

void fillStack(int size){
    for (int i = 0; i < size; i++){
        push((rand() % 171-60) / 10.0);
    }
}

void popElements(Numbers*& top){
    Numbers* temp = top;
    top = top->next;
    delete temp;
}

void deleteLowerThan(Numbers*& top, double value) {
    while (top && top->number < value) {
        popElements(top);
    }
    
    if (top == nullptr) return;

    Numbers* temp = top;
    while (temp->next) {
        if (temp->next->number < value) {
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void clearStack(){
    Numbers* temp = top;
    while (temp){
        Numbers* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    top = nullptr;
}

void showStack(Numbers* top){
    while (top){
        std::cout << top->number << (top->next == nullptr ? " " : "->");
        top = top->next;
    }
    std::cout << "\n";
}

double getAverage(Numbers* top){
    Numbers* temp = top;
    double sum = 0;
    int counter = 0;
    while (temp != nullptr){
        sum += temp->number;
        counter++;
        temp = temp->next;
    }
    return sum / counter;
}



struct Compositions {
    std::string holder;
    std::string name;
    std::string author;
    double price;
    double duration;
    int numberOfCopies;
    Compositions* next;
}*compositionsTop = nullptr;

void pushComposition(std::string holder, std::string name, std::string author, double price, double duration, int numberOfCopies){
    Compositions* newComposition = new Compositions;
    newComposition->holder = holder;
    newComposition->name = name;
    newComposition->duration = duration;
    newComposition->price = price;
    newComposition->author = author;
    newComposition->numberOfCopies = numberOfCopies;
    newComposition->next = compositionsTop;
    compositionsTop = newComposition;
}

void fillCompositions(int size){
    for (int i = 0; i < size; i++){
        pushComposition(holders[rand() % 5], names[rand() % 5], authors[rand() % 5], prices[rand() % 5], durations[rand() % 5], rand() % 100 + 1);
    }
}

void showCompositions(Compositions* compositionsTop){
    while (compositionsTop){
        std::cout << "Holder: " << compositionsTop->holder << ", Name: " << compositionsTop->name << ", Author: " << compositionsTop->author << ", Price: " << std::fixed << std::setprecision(2) << compositionsTop->price << ", Duration: " << compositionsTop->duration << ", Number of Copies: " << compositionsTop->numberOfCopies << "\n";
        compositionsTop = compositionsTop->next;
    }
    std::cout << "\n";
}

double allTime(Compositions* compositionsTop, std::string name = "Beethoven"){
    Compositions* temp = compositionsTop;
    double sum = 0;
    while (temp){
        if (temp->author == name){
            sum += temp->duration * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum;
} 

double avgPrice(Compositions* compositionsTop, std::string holder= "Tape")   {
    Compositions* temp = compositionsTop;
    double sum = 0;
    int counter = 0; 
    while (temp){
        if (temp->holder == holder){
            counter++;
            sum += temp->price * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum / counter;
}

void popCompositions(Compositions* compositionsTop){
    Compositions* temp = compositionsTop;
    compositionsTop = compositionsTop->next;
    delete temp;
}

void clearCompositions(Compositions* compositionsTop){
    Compositions* temp = compositionsTop;
    while (temp){
        Compositions* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    compositionsTop = nullptr;
}


struct NumbersQueue {
    int number;
    NumbersQueue* next;
}*front = nullptr, *rear = nullptr;

void enqueue(int number) {
    NumbersQueue* newNumber = new NumbersQueue;
    newNumber->number = number;
    newNumber->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNumber;
        return;
    }
    rear->next = newNumber;
    rear = newNumber;
}

void dequeue(){
    if (front == nullptr) return;
    NumbersQueue* temp = front;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
}

void addElenentAfterValue(int number, int value){
    NumbersQueue* temp = front;
    while (temp != nullptr){
        if (temp->number == value){
            NumbersQueue* newNumber = new NumbersQueue;
            newNumber->number = number;
            newNumber->next = temp->next;
            temp->next = newNumber;
            if (newNumber->next == nullptr) rear = newNumber;
            return;
        }
        temp = temp->next;
    }
}

double averageGeometic(NumbersQueue* front){
    NumbersQueue* temp = front;
    double product = 1.0;
    int counter = 0;
    while(temp){
        product *= temp->number;
        counter++;
        temp = temp->next;
    }
    return pow(product, 1.0 / counter);

}

void clearQueueNums(NumbersQueue*& front){
    NumbersQueue* temp = front;
    while (temp){
        NumbersQueue* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    front = nullptr;
    rear = nullptr;
}
struct volleyballQueue{
    std::string commandName;
    std::string city;
    int numberOfPoints;
    volleyballQueue* next;
}*vFront = nullptr, *vRear = nullptr;

void vEnqueue(std::string name, std::string city, int points){
    volleyballQueue* newCommand = new volleyballQueue;
    newCommand->commandName = name;
    newCommand->city = city;
    newCommand->numberOfPoints = points;
    newCommand->next = nullptr;
    if (vRear == nullptr) {
        vFront = vRear = newCommand;
        return;
    }
    vRear->next = newCommand;
    vRear = newCommand;
}

void fillVolleyballQueue(int size){
    for (int i = 0; i < size; i++){
        vEnqueue(commands[rand() % 5], cities[rand() % 5], rand() % 100 + 1);
    }

}

void clearQueueVolleyball(volleyballQueue*& vFront){
    volleyballQueue* temp = vFront;
    while (temp){
        volleyballQueue* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    vFront = nullptr;
    vRear = nullptr;
}

int main() {
    srand(time(0));
    while (1)
    {
        std::cout << "Enter number of task(1-4, 0 for exit):\n";
        int num;
        std::cin >> num;
        switch (num)
        {
            case 0:
            return 0;
            case 1:
            {
                std::cout << "Enter number of elements in stack:\n";
                int numbers;
                std::cin >> numbers;
                if (numbers <= 0){
                    std::cout << "Stack should contain at least 1 element\n";
                    break;
                }
                fillStack(numbers);
                std::cout << "Your stack: ";
                showStack(top);
                std::cout << "Enter number and which elements are lower than that element will be deleted:\n";
                double number;
                std::cin >> number;
                deleteLowerThan(top, number);
                std::cout << "Stack after deleting elements lower than " << number << ":\n ";
                showStack(top);
                std::cout << "Average value: " <<std::fixed << std::setprecision(2) << getAverage(top) << "\n";
                clearStack();
            }
            break;
            case 2:
            {
                std::cout << "Enter number of elements in list:\n";
                int num;
                std::cin >> num;
                if (num <=0){
                    std::cout << "List should contain at least 1 element\n";
                    break;
                }
                fillCompositions(num);
                std::cout << "Your list: \n";
                showCompositions(compositionsTop);
                std::cout << "Total time of all compositions by Beethoven: " << allTime(compositionsTop) << "\n";
                std::cout << "Average price of all compositions on Tape: " << avgPrice(compositionsTop) << "\n";
                clearCompositions(compositionsTop);
            }
            break;
            case 3:
            {
                std::cout << "Enter number of elements in queue:\n";
                int num;
                std::cin >> num;
                if (num <= 0){
                    std::cout << "Queue should contain at least 1 element\n";
                    break;
                }
                for (int i = 0; i < num; i++){
                    enqueue(rand() % 98 + 1);
                }
                std::cout << "Your queue: ";
                NumbersQueue* temp = front;
                while (temp){
                    std::cout << temp->number << (temp->next == nullptr ? " " : "->");
                    temp = temp->next;
                }
                temp = front;
                while (temp){
                    if (temp->number % 2 == 0 && temp->number != 100){
                        addElenentAfterValue(100, temp->number);
                       
                    } 
                    temp = temp->next;
                }
                std::cout << "\nQueue after adding elements: ";
                temp = front;
                while (temp){
                    std::cout << temp->number << (temp->next == nullptr ? " " : "->");
                    temp = temp->next;
                }
                std::cout << "\nAverage geometric: " << averageGeometic(front) << "\n";
                clearQueueNums(front);
            }
            break;
            case 4:
            {
                std::cout << "Enter number of commands\n";
                int size;
                std::cin >> size;
                if (size <= 0){
                    std::cout << "Queue should contain at least 1 element\n";
                    break;
                }
                fillVolleyballQueue(size);
                std::cout << "Your queue:\n";
                volleyballQueue* temp = vFront;
                int winner = temp->numberOfPoints, outsider = temp->numberOfPoints;
                while (temp){
                    if (temp->numberOfPoints > winner){
                        winner = temp->numberOfPoints;
                    }
                    if (temp->numberOfPoints < outsider){
                        outsider = temp->numberOfPoints;
                    }
                    std::cout << "Command: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
                    temp = temp->next;
                }
                std::cout << "Cities from which commands were taken:\n";
                
                for (int i = 0; i < 5; i++){
                    bool alreadyExists = false;
                    temp = vFront;
                    while (temp)
                    {
                        if (temp->city == cities[i] && !alreadyExists){
                            std::cout << cities[i] << " ";
                            alreadyExists = true;
                            break;
                        }
                        temp = temp->next; 
                    }       
                }
                std::cout << "\n";
                temp = vFront;
                while (temp){
                    if (temp->numberOfPoints == winner){
                        std::cout << "Winner: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
                    }
                    if (temp->numberOfPoints == outsider){
                        std::cout << "Outsider: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
                    }
                    temp = temp->next;
                }
                clearQueueVolleyball(vFront);
            }
            break;
            default:
            std::cout << "Invalid number of task\n";
        }
    }
    return 0;
}