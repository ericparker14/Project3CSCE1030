#include "etp0040_header.h"
using namespace std;


int main(){

    int userChoice;
    // print menu out


    do{
	cout << "Student Records menu:\n";
    cout <<"1.Add\n2.Remove\n3.Display\n4.Search\n5.Results\n6.Quit\n";

    // ask the user for input
    cout << "Enter your choice:";
    cin >> userChoice;
    switch(userChoice){
        case Add:{
        //call addStudent function
		add_Student();
        }
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
		int searchID;
            cout << "Please enter student ID:";
			cin >> searchID;
			search(searchID);
        // take in studentID
        // display()

	return 0;
        case Results:
        exportResults();
  
	return 0;
        case Quit:
        cout << "Goodbye!" << endl;

	return 0;
		
        default:
            cout << "Enter a valid choice." << endl;
            sleep(1.5);
			return 0;


    }
    }while(!(userChoice == Quit));



    return 0;
}
