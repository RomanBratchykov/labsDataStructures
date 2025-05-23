#include <iostream>
#include <vector>
#include <algorithm>
struct Food {
    std::string name;
    int index;
    double volume;
    double weight;
    double calories;
    double caloriesPer;
    
    Food(std::string name, int index, double volume, double weight, double calories)
        : name(name), index(index), volume(volume), weight(weight), calories(calories) {
        caloriesPer = calories / volume;
    }
};

std::vector<Food> setupFoods() {
    return {
        {"Meat", 0, 1, 1, 1500},
        {"Flour", 1, 1.5, 1, 5000},
        {"Milk", 2, 2, 1, 5000},
        {"Sugar", 3, 1, 1, 4000}
    };
}

bool isValidCombination(const std::vector<double>& quantities, const std::vector<Food>& foods, 
                       double maxVolume, double maxWeight) {
    double totalVolume = 0, totalWeight = 0;
    for (int i = 0; i < foods.size(); i++) {
        totalVolume += quantities[i] * foods[i].volume;
        totalWeight += quantities[i] * foods[i].weight;
    }
    
    if (totalVolume > maxVolume || totalWeight > maxWeight)
        return false;
    
    if (quantities[0] * foods[0].weight < 2 * quantities[1] * foods[1].weight)
        return false;
    
    if (quantities[1] * foods[1].weight < quantities[2] * foods[2].weight)
        return false;
    
    if (quantities[2] * foods[2].weight < 8 * quantities[3] * foods[3].weight)
        return false;
    
    return true;
}

void solveExpeditionProblem() {
    std::vector<Food> foods = setupFoods();
    const double maxVolume = 45.0;
    const double maxWeight = 35.0;
    
    std::vector<double> bestQuantities(foods.size(), 0.0);
    double bestCalories = 0.0;
    
    for (int meat = 0; meat <= 15; meat++) {
        for (int flour = 0; flour <= 15; flour++) {
            for (int milk = 0; milk <= 15; milk++) {
                for (int sugar = 0; sugar <= 5; sugar++) {
                    std::vector<double> quantities = {
                        static_cast<double>(meat),
                        static_cast<double>(flour),
                        static_cast<double>(milk),
                        static_cast<double>(sugar)
                    };
                    
                    if (isValidCombination(quantities, foods, maxVolume, maxWeight)) {
                        double totalCalories = 0;
                        for (int i = 0; i < foods.size(); i++) {
                            totalCalories += quantities[i] * foods[i].calories;
                        }
                        
                        if (totalCalories > bestCalories) {
                            bestCalories = totalCalories;
                            bestQuantities = quantities;
                        }
                    }
                }
            }
        }
    }
    
    std::cout << "Optimal solution:\n";
    std::cout << "Total calories: " << bestCalories << " calories\n\n";
    
    double totalVolume = 0, totalWeight = 0;
    for (size_t i = 0; i < foods.size(); i++) {
        totalVolume += bestQuantities[i] * foods[i].volume;
        totalWeight += bestQuantities[i] * foods[i].weight;
        
        std::cout << foods[i].name << ": " << bestQuantities[i] 
                   << " units, " << (bestQuantities[i] * foods[i].weight) 
                   << " kg, " << (bestQuantities[i] * foods[i].volume) 
                   << " dm³, " << (bestQuantities[i] * foods[i].calories) 
                   << " calories\n";
    }
    
    std::cout << "\nTotal volume: " << totalVolume << " / " << maxVolume << " dm³\n";
    std::cout << "Total weight: " << totalWeight << " / " << maxWeight << " kg\n";
}
struct Activity {
    int index;
    int start;
    int end;
    Activity(int index, int start, int end)
        : index(index), start(start), end(end) {}
    void print() {
        std::cout << "Activity " << index << ": " << start << " - " << end << "\n";
    }
};

std::vector<Activity> getSchedule(std::vector<Activity>& activities){
    std::sort(activities.begin(), activities.end(), [](const Activity& a, const Activity& b) {
        return a.end < b.end;
    });
    std::vector<Activity> schedule;
    int currentTime = 0;
    for (auto& activity : activities) {
        if (activity.start >= currentTime) {
            schedule.push_back(activity);
            currentTime = activity.end;
        }
    }
    return schedule;
}

int main() {
    while (1){
        std::cout << "Choose a task (1-2, 0 for exit): \n";
        int task;
        std::cin >> task;
        if (task == 0) break;
        if (task == 1){
            solveExpeditionProblem();
        }
        else if (task == 2){
            std::cout << "Enter number of activities: ";
            int n;
            std::cin >> n;
            std::cout << "Enter activities (index, start, end):\n";
            std::vector<Activity> activities;
            for (int i = 0; i < n; ++i) {
                int index, start, end;
                std::cin >> index >> start >> end;
                activities.push_back(Activity(index, start, end));
            }

            std::vector<Activity> schedule = getSchedule(activities);
            for (auto& activity : schedule) {
                activity.print();
            }
        }
        else {
            std::cout << "Invalid task number.\n";
        }
    }
    return 0;
}