//Author: Erin Keith
//Date: 6/5/23
//Purpose: HW 2

#include <iostream>
#include <string>
using namespace std;

#include "linkedlist.h"
#include "arraylist.h"

int getMenuChoice();
void displayList(ListInterface<string>&);
void clearList(ListInterface<string>&);
void replaceTask(ListInterface<string>&);
void removeTask(ListInterface<string>&);
void completeTodoTask(LinkedList<string>&, ArrayList<string>&);
void addTodoTask(LinkedList<string>&);

using namespace std;

int main(void){
    int menuChoice;
    LinkedList<string> todoList;
    ArrayList<string> doneList;

    do {
        menuChoice = getMenuChoice();

        switch(menuChoice){
            case 1:
                addTodoTask(todoList);
                break;
            case 2:
                completeTodoTask(todoList, doneList);
                break;
            case 3:
                cout << endl << "To Do: " << endl;
                displayList(todoList);
                break;
            case 4:
                cout << endl << "Completed: " << endl;
                displayList(doneList);
                break;
            case 5:
                replaceTask(todoList);
                break;
            case 6:
                replaceTask(doneList);
                break;
            case 7:
                removeTask(todoList);
                break;
            case 8:
                removeTask(doneList);
                break;
            case 9:
                cout << endl << "Cleared!" << endl;
                clearList(todoList);
                break;
            case 10:
                cout << endl << "Cleared!" << endl;
                clearList(doneList);
                break;
            case 0:
                break;
            default:
                cout << endl << "Invalid option!" << endl;
                break;
        }
    }while(menuChoice != 0);

    return 0;
}

int getMenuChoice(){
    int userChoice;

    cout << endl << "TODO APP" << endl;
    cout << "1. Add task to do" << endl;
    cout << "2. Complete task" << endl;
    cout << "3. Display TODO list" << endl;
    cout << "4. Display DONE list" << endl;
    cout << "5. Replace TODO task" << endl;
    cout << "6. Replace DONE task" << endl;
    cout << "7. Remove TODO task" << endl;
    cout << "8. Remove DONE task" << endl;
    cout << "9. Clear TODO list" << endl;
    cout << "10. Clear DONE list" << endl;
    cout << "0. Exit " << endl;

    cin >> userChoice;
    return userChoice;
}

void displayList(ListInterface<string>& list){
    if(list.isEmpty()){
        cout << "No tasks currently!" << endl;
        return;
    }

    for(int pos = 1; pos <= list.getLength(); pos++){
        cout << pos << ": " << list.getEntry(pos) << endl;
    }
}

void clearList(ListInterface<string>& list) {
    if (list.isEmpty()) {
        cout << "No tasks currently!" << endl;
        return;
    }

    list.clear();
}

void completeTodoTask(LinkedList<string>& todo, ArrayList<string>& done){
    int pos;
    string completedTask;

    cout << endl << "To Do: " << endl;
    displayList(todo);

    if(!todo.isEmpty()){
        cout << "Please select which task you've completed: " << endl;
        cin >> pos;

        try{
            completedTask = todo.getEntry(pos);
        }
        catch(const char* e){
            cout << endl << "Could not complete task." << endl;
            return;
        }

        todo.remove(pos);

        if(todo.isEmpty()){
            cout << endl << "GREAT JOB! You finished all your tasks :D";
        }

        cout << endl << "Completed: " << endl;
        done.insert(done.getLength() + 1, completedTask);
        displayList(done);
    }
}

void addTodoTask(LinkedList<string>& todo){
    int priority;
    string newTask;

    displayList(todo);

    cout << endl << "What is the priority of your new task?" << endl;
    cin >> priority;

    while(priority < 1 || priority > todo.getLength() + 1){
        cout << "Choose a priority 1 through " << todo.getLength() + 1 << endl;
        cin >> priority;
    }

    cout << "What is your new task?" << endl;
    getline(cin, newTask);
    getline(cin, newTask);

    todo.insert(priority, newTask);
}

void replaceTask(ListInterface<string>& list)
{
    if (list.isEmpty()) {
        cout << "No tasks currently!" << endl;
        return;
    }

    int task_number;
    string replacement_task;

    displayList(list);

    cout << endl << "Which task would you like to replace?" << endl;
    cin >> task_number;

    while (task_number < 1 || task_number > list.getLength()) {
        cout << "Choose a task 1 through " << list.getLength() << endl;
        cin >> task_number;
    }

    cout << "What is your replacement task?" << endl;
    getline(cin, replacement_task);
    getline(cin, replacement_task);

    list.replace(task_number, replacement_task);
}

void removeTask(ListInterface<string>& list)
{
    if (list.isEmpty()) {
        cout << "No tasks currently!" << endl;
        return;
    }

    int task_number;

    displayList(list);

    cout << endl << "Which task would you like to remove?" << endl;
    cin >> task_number;

    while (task_number < 1 || task_number > list.getLength()) {
        cout << "Choose a task 1 through " << list.getLength() << endl;
        cin >> task_number;
    }

    list.remove(task_number);
}