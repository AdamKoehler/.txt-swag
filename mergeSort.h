#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct teamData {
    string team1Name;
    string team2Name;
    string team1Score;
    string team2Score; // this program we are sorting based on name and we dont need to do math. only storage, so I chose string even though it should be int.
};

void processFile(ifstream& inputFile, teamData* list) {
    for (int i = 0; i < 10; i++) {
        if (inputFile >> list[i].team1Name >> list[i].team2Name >> list[i].team1Score >> list[i].team2Score) {
            continue;
        } else {
            cout << "Failed to read data for team " << i << endl;
            break;
        }
    }
    inputFile.close();
}

teamData list4[30];  // stored outside of function so main can access.

void merge(teamData* list1, teamData* list2, teamData* list3) {
    // merge the lists into  list 4
    
    for (int i = 0; i< 30; i++){
        if (i < 10){
            list4[i] = list1[i];
        } else if (i < 20){
            list4[i] = list2[i-10];
        } else {
            list4[i] = list3[i-20];
        }
    }
    // we have 3 sorted lists that have been combined into 1 list.
    // there needs to be a final sort to sort the list as a whole.
    // this final sort will be the mergeSort.
    // I will call mergeSort in main passing this list that we have created.
}
void sort(teamData* list){
    // lexicographically sort the list based on the name of the first team.
    // Bubble sort
    teamData temp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9-i; j++) {
            if (list[j].team1Name > list[j+1].team1Name) {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
void printList(teamData* list, int listNum) {
    // print list to the screen
    cout << "LIST "<< listNum << ":\n" << endl;
    for (int i = 0; i < 10; i++)
    {
    cout << "Team 1 Name: " << list[i].team1Name << ", ";
    cout << "Team 2 Name: " << list[i].team2Name << ", ";
    cout << "Team 1 Score: " << list[i].team1Score << ", ";
    cout << "Team 2 Score: " << list[i].team2Score << "\n" << endl;
    }
}

void finalSort(teamData* list4){ // same thing as the sort but this will handle the size needed for list 4.
    for (int i = 0; i < 29; i++) {
            for (int j = 0; j < 29-i; j++) {
                if (list4[j].team1Name > list4[j+1].team1Name) {
                    teamData temp;
                    temp = list4[j];
                    list4[j] = list4[j+1];
                    list4[j+1] = temp;
                }
            }
    }
}
void printFinalList(){
    cout << "LIST 4:\n" << endl;
    for (int i = 0; i < 30; i++)
    {
    cout << "Team 1 Name: " << list4[i].team1Name << ", ";
    cout << "Team 2 Name: " << list4[i].team2Name << ", ";
    cout << "Team 1 Score: " << list4[i].team1Score << ", ";
    cout << "Team 2 Score: " << list4[i].team2Score << "\n" << endl;
    }
}
void writeFinalList(){
    ofstream outputFile("C:/work/C++/C++ Projects/Homework 5/Koehler.txt");
    for (int i = 0; i < 30; i++)
    {
    outputFile << "Team 1 Name: " << list4[i].team1Name << ", ";
    outputFile << "Team 2 Name: " << list4[i].team2Name << ", ";
    outputFile << "Team 1 Score: " << list4[i].team1Score << ", ";
    outputFile << "Team 2 Score: " << list4[i].team2Score << "\n" << endl;
    }
    outputFile.close();
}