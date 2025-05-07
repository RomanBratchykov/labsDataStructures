#include <iostream>
#include <string>
#include <sstream>
std::string stations[10] = {"Chatanooga", "Bridgeton", "New York", "Kyiv", "London", "Madrid", "Heplew", "Katarines", "Tokyo", "Chernivtsi"};
struct Time {
    int hours;
    int minutes;
    int seconds;

    void fix(){
        if (seconds < 0) {
            int borrow = (abs(seconds) + 59) / 60;
            minutes -= borrow;
            seconds += borrow * 60;
        } else if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
    
        if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        } else if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    
        hours = ((hours % 24) + 24) % 24;
    }
    Time(int h = 0, int m = 0, int s = 0){
        hours = h;
        minutes = m;
        seconds = s;
        fix();
    }
    ~Time(){}
    void setTime(){
        int h, m, s;
        std::cout << "Enter time (hours, minutes, seconds)\n";
        std::cin >> h >> m >> s;
        hours = h;
        minutes = m;
        seconds = s;
        fix();
    }

    std::string getTime() {
        std::stringstream ss;
        ss << (hours < 10 ? "0" : "") << hours << ":"
        <<  (minutes < 10 ? "0" : "") << minutes << ":"
           << (seconds < 10 ? "0" : "") << seconds;
        return ss.str();
    }

    Time operator+(const Time& t2) {return Time(this->hours + t2.hours, this->minutes + t2.minutes, this->seconds + t2.seconds);}
    Time operator-(const Time& t2){return Time(this->hours - t2.hours, this->minutes - t2.minutes, this->seconds - t2.seconds);}

    bool operator<(const Time& t2){
        if (this->hours < t2.hours) return true;
        if (this->hours > t2.hours) return false;
        if (this->minutes < t2.minutes) return true;
        if (this->minutes > t2.minutes) return false;
        if (this->seconds < t2.seconds) return true;
        return false;
    }
    bool operator>(const Time& t2)
    {
        if (this->hours > t2.hours) return true;
        if (this->hours < t2.hours) return false;
        if (this->minutes > t2.minutes) return true;
        if (this->minutes < t2.minutes) return false;
        if (this->seconds > t2.seconds) return true;
        return false;
    }
    bool operator<=(const Time& t2){
        if (this->hours <= t2.hours) return true;
        if (this->hours >= t2.hours) return false;
        if (this->minutes <= t2.minutes) return true;
        if (this->minutes >= t2.minutes) return false;
        if (this->seconds <= t2.seconds) return true;
        return false;
    }
    bool operator>=(const Time& t2)
    {
        if (this->hours >= t2.hours) return true;
        if (this->hours <= t2.hours) return false;
        if (this->minutes >= t2.minutes) return true;
        if (this->minutes <= t2.minutes) return false;
        if (this->seconds >= t2.seconds) return true;
        return false;
    }
    bool operator==(const Time& t2)
    {
        if (this->hours == t2.hours && this->minutes == t2.minutes && this->seconds == t2.seconds) return true;
        return false;
    }
};  

struct Train{
    int number;
    std::string station;
    Time timeOfDeparture;
    Time timeOfArrival;
    Time timeInRoad;
    Train(){
        number = 1;
        station = "Shevchenka 243";
        timeOfDeparture = Time(12, 30, 00);
        timeOfArrival = Time (16, 00, 00);
        timeInRoad = timeOfArrival - timeOfDeparture;
    }
    Train(int number, std::string station, Time timeOfDeparture, Time timeOfArrival){
        this->number = number;
        this->station = station;
        this->timeOfDeparture = timeOfDeparture;
        this->timeOfArrival = timeOfArrival;
        this->timeInRoad = timeOfArrival - timeOfDeparture;
    }
    int toMinutes(){
        return timeInRoad.minutes + timeInRoad.hours * 60;
    }
    void printTrain(){
        std::cout << "Train number " << this->number << " go from " << this->timeOfDeparture.getTime() << " to " << this->timeOfArrival.getTime() << " with station of arrival " << this->station << "( roadtime = "<< this->timeInRoad.getTime() <<")\n";
    }
};

Train longestRoadtime(Train* array, int size){
    int max = array[0].toMinutes();
    for (int i = 0; i < size; i++){
        if (array[i].toMinutes() > max){
            max = array[i].toMinutes();
        }
    }
    for (int i = 0; i < size; i++){
        if (array[i].toMinutes() == max){
            return array[i];
        }
    }
    return array[0];
}

int partition(Train* arr, int start, int end){
    Train pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if (arr[j].timeInRoad <= pivot.timeInRoad){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(Train* arr, int start, int end){
    if (start < end){
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
} 

int main(){
    srand(time(0));
    while (1){
        std::cout << "Enter number of task(1-2, 0 for exit)\n";
        int num;
        std::cin>> num;
        if (num == 0){
            return 0;
        }
        switch(num){
            case 1:{
                std::cout << "Enter number of trains\n";
                int size;
                std::cin >> size;
                Train* arr = new Train[size];
                for (int i = 0; i < size; i++){
                    std::string station = stations[rand() % 10];
                    Time timeOfDeparture = Time(rand() % 100, rand() % 100, rand() % 100);
                    Time timeOfArrival = Time(rand() % 100, rand() % 100, rand() % 100); 
                    arr[i] = Train(i, station, timeOfDeparture, timeOfArrival);
                    if (timeOfArrival < timeOfDeparture){
                        i--;
                    }
                }
                   
                std::cout << "Your array of trains\n";
                for (int i = 0; i < size; i++){
                    std::cout << "---------------------------------\n";
                    arr[i].printTrain();
                }
                std::cout << "\n";
                std::cout << "Train with longest roadtime with fuction\n";
                Train longest = longestRoadtime(arr, size);
                longest.printTrain();
                std::cout << "In minutes " << longest.toMinutes() << "\n";
                std::cout << "Sorted array\n";
                quickSort(arr, 0, size - 1);
                for (int i = 0; i < size; i++){
                    std::cout << "---------------------------------\n";
                    arr[i].printTrain();
                }
                std::cout << "\n";
                std::cout << "Train with longest roadtime with sorting\n";
                arr[size - 1].printTrain();
            }
            break;
            case 2:
            break;
            default:
                std::cout << "wrong choice\n";
            break;
        }
    }
    return 0;
}