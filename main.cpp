#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void saveTasks(const vector<string>& tasks) {
    ofstream file("tasks.txt");

    for (const string& task : tasks) {
        file << task << "\n";
    }

    file.close();
}

int main() {
    vector<string> tasks;

    ifstream file("tasks.txt");

    string savedTask;

    while (getline(file, savedTask)) {
        tasks.push_back(savedTask);
    }

    file.close();

    int choice;

    while (true) {
        cout << "\n=== Task Manager ===\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Complete task\n";
        cout << "4. Delete task\n";
        cout << "5. Exit\n";

        cout << "\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            string task;

            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);

            tasks.push_back(task);
            saveTasks(tasks);

            cout << "Task added!\n";
        }

        else if (choice == 2) {
            cout << "\n=== Your Tasks ===\n";

            if (tasks.empty()) {
                cout << "No tasks yet.\n";
            }
            else {
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << "\n";
                }
            }
        }

        else if (choice == 3) {
            int taskNumber;

            cout << "Enter task number to complete: ";
            cin >> taskNumber;

            if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                if (tasks[taskNumber - 1].find(" [COMPLETED]") == string::npos) {
                    tasks[taskNumber - 1] += " [COMPLETED]";
                    saveTasks(tasks);

                    cout << "Task completed!\n";
                }
                else {
                    cout << "Task is already completed.\n";
                }
            }
            else {
                cout << "Invalid task number.\n";
            }
        }

        else if (choice == 4) {
            int taskNumber;

            cout << "Enter task number to delete: ";
            cin >> taskNumber;

            if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNumber - 1);
                saveTasks(tasks);

                cout << "Task deleted!\n";
            }
            else {
                cout << "Invalid task number.\n";
            }
        }

        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}