#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

vector<Task> taskList;

void addTask()
{
    cout << "Enter task description: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    taskList.push_back(Task(desc));
    cout << "Task added successfully.\n";
}

void viewTasks()
{
    if (taskList.empty())
    {
        cout << "No tasks in the list.\n";
        return;
    }
    cout << "\nTask List:\n";
    for (size_t i = 0; i < taskList.size(); ++i)
    {
        cout << i + 1 << ". " << taskList[i].description
             << " [" << (taskList[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted()
{
    viewTasks();
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size())
    {
        cout << "Invalid task number.\n";
    }
    else if (taskList[taskNumber - 1].isCompleted)
    {
        cout << "Task is already marked as completed.\n";
    }
    else
    {
        taskList[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask()
{
    viewTasks();
    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskList.size())
    {
        cout << "Invalid task number.\n";
    }
    else
    {
        taskList.erase(taskList.begin() + (taskNumber - 1));
        cout << "Task removed successfully.\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskAsCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
