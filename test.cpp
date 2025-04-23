#include <list>
#include <iostream>
#include <chrono>
#include <thread>

int main(){
    for (int i = 0; i < 10; i++){
        std::cout << "\rProcessing. " << std::flush;
        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);
        std::cout << "\rProcessing.. " << std::flush;
        std::this_thread::sleep_for(timespan);
        std::cout << "\rProcessing... " << std::flush;
        std::this_thread::sleep_for(timespan);
    }
    std::cout << "\rProcesssing... Done!" << "\n";
}