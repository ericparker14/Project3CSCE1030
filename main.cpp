#include "etp0040_header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iomanip>


enum menu {Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6};
const int NUM_TESTS = 5;

struct Student{
    string firstN;
    string lastN;
    int studentID;
    int testsTaken;
    int* ptr = nullptr;
    double averageScore;
};
void add_Student(ofstream &outFS, Student* newStudent){
    int testScore;
    // get all info
    cout << "First name:";
    cin >> newStudent.firstN;
    cout << "Last name:";
    cin >> newStudent.lastN;
    cout << "Student ID:";
    cin >> newStudent.studentID;
    // create dyn array given # tests
    cout << "# Tests taken:";
    cin >> newStudent.testsTaken;
    newStudent.ptr = new int(newStudent.testsTaken);
    cout << "newStudent.ptr = " << *newStudent.ptr << endl;
    // take in test scores input
    cout << "Test scores:";
    for (int i = 0; i < newStudent.testsTaken; i++){
        cin >> testScore;
        newStudent.ptr[i] = testScore;
    }
    // open file to write to
    outFS.open("student.dat");
    if(!outFS.is_open()){
        cout << "File failed to open.";
        exit(1);
    }

    outFS <<newStudent.lastN<<","<<newStudent.firstN<<","
    <<newStudent.studentID<<","<<newStudent.testsTaken<<",";
    for(int i = 0; i < newStudent.testsTaken; i++){
        outFS << newStudent.ptr[i] << ",";
    }
    outFS.close();
}


void remove_Student(int remove_studentID){
	    /* call getNumber();
     * create dynamic array with Student
     * open student.dat to read
     * read one line at a time store data in array
     * while reading check if student id matches student id user entered
     * use bool
     * copy entire file to the dynamic array whether or not there is a match
     * close file*/
	ifstream inFS;
    int numStudents = getNumber();
	int i = 0;
	bool remove = false;
    cout << "numStudents = " << numStudents << endl;
	
	Student* studentArr = nullptr;
	studentArr = (Student*)malloc(numStudents * sizeof(Student));
	
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Error opening file.\nClosing Program.";
		exit(1);
	}
	string fromData;
	while(inFS.eof()){
		getline(inFS, fromData);

		istringstream inSS(fromData);
		string changeStrToInt;
		
		getline(inSS, studentArr[i].lastN, ',');
		getline(inSS, studentArr[i].firstN, ',');
		
		getline(inSS, changeStrToInt, ',');
		studentArr[i].studentID = stoi(changeStrToInt);
		if(remove_studentID == studentArr[i].studentID){
			remove = true;
			continue;
		}
		getline(inSS, changeStrToInt, ',');
		studentArr[i].testsTaken = stoi(changeStrToInt);
		studentArr[i].ptr = new int[studentArr[i].testsTaken];
		for(int num = 0; num < studentArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			studentArr[i].ptr[num] = stoi(changeStrToInt);
		}
		i++;
	}
	
	inFS.close();
	
	if(remove){
		ofstream outFS;
		i--;
		outFS.open("student.dat");
		if(!outFS.is_open()){
			cout << "Failed to open file.\nClosing Program.\n";
			exit(1);
		}
		for(int j = 0; j < i; j++){
			outFS << studentArr[j].lastN << "," << studentArr[j].firstN << "," << studentArr[j].studentID <<
			"," << studentArr[j].testsTaken << ",";
			for(int num; num < studentArr[j].testsTaken; num++){
				outFS << studentArr[j].ptr[num] << ",";
				
			}
			outFS << endl;
		}
		cout << "Data removed for student with ID#" << remove_studentID << endl;
		outFS.close();
	}
	else{
		cout << "Data for student with ID#" << remove_studentID << " not found.\n";
	}
}
void display(){
	ifstream inFS;
	string getData;
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing file.\n";
		exit(1);
	}
	int count = getNumber();
	int i = 0;
	Student* disArr = nullptr;
	disArr = (Student*)malloc(count * sizeof(Student));
	while(inFS.eof()){
		getline(inFS, getData);

		istringstream inSS(getData);
		string changeStrToInt;
		getline(inSS, disArr[i].lastN, ',');
		getline(inSS, disArr[i].firstN, ',');
		string name = disArr[i].lastN + "," + disArr[i].firstN;
		
		getline(inSS, changeStrToInt, ',');
		disArr[i].studentID = stoi(changeStrToInt);
		getline(inSS, changeStrToInt, ',');
		disArr[i].testsTaken = stoi(changeStrToInt);
		disArr[i].ptr = new int[disArr[i].testsTaken];
		for(int num = 0; num < disArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			disArr[i].ptr[num] = stoi(changeStrToInt);
		}
		cout << setw(30) << name;
		cout << setw(15) << disArr[i].studentID;
		for(int j = 0; j < disArr[i].testsTaken; j++){
			cout << setw(5) << disArr[i].ptr[j];
		}
		cout << endl;
		i++;
	}
	inFS.close();
	
}
void search(int ID){
	ifstream inFS;
	bool match = false;
	inFS.open("data.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing program\n";
		exit(1);
	}
	Student* lookFor = nullptr;
	do{
		string change;
		getline(inFS, lookFor.lastN, ',');
		getline(inFS, lookFor.firstN, ',');
		getline(inFS, change, ',');
		lookFor.studentID = stoi(change);
		getline(inFS, change, ',');
		lookFor.testsTaken = stoi(change);
		lookFor.ptr = new int[lookFor.testsTaken];
		for(int i = 0; i < lookFor.testsTaken; i++){
			getline(inFS, change, ',');
			lookFor.ptr[i] = stoi(change);
		}
		if(lookFor.studentID == ID){
			match = true;
			cout << "Student with ID#" << ID <<" was found:\n";
			cout << setw(30) << name;
			cout << setw(15) << lookFor.studentID;
			for(int j = 0; j < lookFor.testsTaken; j++){
				cout << setw(5) << lookFor.ptr[j];
			}
			cout << endl;
		}
	}while((!inFS.eof())||(!match));
	string name = lookFor.lastN + "," + lookFor.firstN;
	if(!match){
		cout << "No student found with ID#" << ID << endl;
	}
	
	}

void exportResults(){
	ofstream outFS;
	ifstream inFS;
	
	outFS.open("averages.dat");
	if(!outFS.is_open()){
		cout << "Failed to open file.\nClosing program";
		exit(1);
	}
	inFS.open("student.dat");
	if(!inFS.is_open()){
		cout << "Failed to open file.\nClosing program";
		exit(1);
	}
	int size = getNumber();
	Student* resultsArr = nullptr;
	resultsArr = (Student*)malloc(size*sizeof(Student));
	string resData;
	string name;
	int i = 0;
	while(inFS.eof()){
		getline(inFS, resData);

		istringstream inSS(resData);
		string changeStrToInt;
		
		getline(inSS, resultsArr[i].lastN, ',');
		getline(inSS, resultsArr[i].firstN, ',');
			
		getline(inSS, changeStrToInt, ',');
		resultsArr[i].studentID = stoi(changeStrToInt);
		
		getline(inSS, changeStrToInt, ',');
		resultsArr[i].testsTaken = stoi(changeStrToInt);
		
		resultsArr[i].ptr = new int[resultsArr[i].testsTaken];
		
		for(int num = 0; num < resultsArr[i].testsTaken; num++){
			getline(inSS, changeStrToInt, ',');
			resultsArr[i].ptr[num] = stoi(changeStrToInt);
		}
		
		i++;
	}

	for(int j = 0; j < size; j++){
		int sum = 0;
		double avg = 0;
		for (int k = 0; k < resultsArr[j].testsTaken; k++){
			sum = sum + resultsArr[j].ptr[k];
			findMinimum(); //fix me
		}
		avg = sum / static_cast<double>(resultsArr[j].testTaken);
		outFS << setw(15) << resultsArr[j].studentID;
		outFS << avg << endl;
	}
	outFS.close();
	inFS.close();
}
		
		
	
		
	
	
	


int main(){

    ofstream outFS;
	


    int userChoice;
    // print menu out


    do{
	cout << "Student Records menu:\n";
    cout <<"1.Add\n2.Remove\n3.Display\n4.Search\n5.Results\n6.Quit\n";

    // ask the user for input
    cout << "Enter your choice:";
    cin >> userChoice;
    switch(userChoice){
        case Add:
        //call addStudent function
		Student* newStudent = nullptr;
		newStudent = new Student;
        add_Student(outFS, &newStudent);
            return 0;
        case Remove:
		int removeStudent;
		cout << "Please enter the ID# of student to remove:";
		cin >> removeStudent;
            remove_Student(removeStudent);
        //call remove_Student
            return 0;
        case Display: // call getNumber and display
		display();
            return 0;
        case Search:
		int searchID
            cout << "Please enter student ID:";
			cin << searchID;
			search(searchID);
        // take in studentID
        // display()
            return 0;
        case Results:
        // exportResults()
            return 0;
        case Quit:
        cout << "Goodbye!" << endl;
        return 0;
		
        default:
            cout << "Enter a valid choice." << endl;
            sleep(1.5);
			break;


    }
    }while(!(userChoice == Quit));



    return 0;
}
