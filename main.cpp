#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include "getNumber.cpp"
using namespace std;


void add_Student(ofstream &outFS){
    cout << "Fix Me Pls" << endl;
}

void remove_Student(ifstream &inFS){
    int numStudents;
    numStudents = getNumber("student.dat");
    // call getNumber();
    // create dynamic array with Student
    // open student.dat to read
    // read one line at a time store data in array
    // while reading check if student id matches student id user entered
    // use bool
    // copy entire file to the dynamic array whether or not there is a match
    // close file
    cout << "Fix Me Pls" << endl;
}

enum menu {Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6};
const int NUM_TESTS = 5;

struct Student{
    string firstN;
    string lastN;
    int studentID;
    int testsTaken;
    int *Student = new int (NUM_TESTS);
    double averageScore;
};

int main(){
    ifstream inFS;
    ofstream outFS;

    int userChoice;
    // print menu out

    do{
    system("clear");

    cout <<"1.Add"<<endl<<"2.Remove"<<endl<<"3.Display"<<endl<<
    "4.Search"<<endl<<"5.Results"<<endl<<"6.Quit"<<endl;

    // ask the user for input
    cout << "Enter your choice:";
    cin >> userChoice;
    switch(userChoice){
        case Add:
        //call addStudent function
            return 0;
        case Remove:
        //call remove_Student
            return 0;
        case Display:
            return 0;
        case Search:
            cout << "Please enter student ID:";
        // take in studentID
        // display()
            return 0;
        case Results:
        // exportResults()
            return 0;
        case Quit:
        cout << "Goodbye!" << endl;
        break;
            return 0;
        default:
            cout << "Enter a valid choice." << endl;
            sleep(1.5);


    }
    }while(!(userChoice == Quit));



    return 0;
}