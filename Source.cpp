//Sumeed_Jawad_Kanwar_22i-2651_Assignment2
#include "Header.h"

int main()
{
    //Creating Project
    Project* project = new Project();
    char input;
    // Menu
    Menu();
    cin >> input;
    while (input != '0')
    {
        switch (input)
        {
        case '1':
            project->addResource();
            break;
        case '2':
            project->addTask();
            break;
        case '3':
            project->setTaskDuration();
            break;
        case '4':
            project->set_nth_TaskDuration();
            break;
        case '5':
            project->printTaskDependencyList();
            break;
        case '6':
            project->calculateBasicSchedule();
            break;
        case '7':
            project->printCriticalPath();
            break;
        case '8':
            project->completionTimeWithResources();
            break;
        case '9':
            project->completionTimeWithResourceProficiency();
            break;
        default:
            cout << "Invalid input, please try again." << endl;
            break;
        }
        Menu();
        cin >> input;
    }
    //Deleting Project
    delete project;
    return 0;
}