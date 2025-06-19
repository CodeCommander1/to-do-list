#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

// Function to add a task
void addTask(const string& desc) {
    tasks.emplace_back(desc);
    cout << "Task added successfully.\n";
}

// Function to view all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

// Function to remove a task
void removeTask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully.\n";
}

int main() {
    int choice;
    string desc;
    int index;

    do {
        cout << "\n=== TO-DO LIST MENU ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                addTask(desc);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markTaskCompleted(index);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(index);
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
