#include <iostream>
#include <vector>
#include <algorithm>
struct Food {
    std::wstring name;
    int index;
    double volume;
    double calories;
    double caloriesPer;
    Food(std::wstring name, int index, double volume, double calories)
        : name(name), index(index), volume(volume), calories(calories) {
        caloriesPer = calories / volume;
    }
};


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