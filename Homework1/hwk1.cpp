/*
*   Author: Ethan El-Zayaty
*   Date: 01/23/2023
*   Instructor: Dr Maharjan
*   Description: 
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;
struct Student{
    int id; //student ID
    string first;
    string last; //first and last name
    int exam1; 
    int exam2; 
    int exam3; //grades for each exam
    double mean; //average of three exam grades
};

void printStart();
void printMenu();

using namespace std;
int main() {
    //call starting print function to print class information
    printStart();
    Student students[20]; //students array
    int index = 0; //counter
    int choice = 1; //track user choice
    double sum; //used for mean calculations
    int alterID = 0; //used to determine the id of the student to alter.
    int alterIndex = -1;
    float minAvg;
    float maxAvg;
    //infinitely loop

    while(0 == 0) {
        printMenu();
        cin >> choice;
        switch(choice) {
            case 1: //print student info
                if(index == 0) {
                    cout << "Error. No students in database." << endl;
                    break;
                }
                else {
                    //setw() did not want to work, so instead I use a long cout to print the appropriate amount of asterisks
                    cout << "*************************** Students *****************************" << endl;
                    cout << "ID        First        Last               Exam1 Exam2  Exam3  Mean" << endl;
                    cout << "------------------------------------------------------------------" << endl;
                    std::cout.setf(std::ios::left);
                    for(int i = 0; i < index; i++) {
                        //print all student data
                        cout << setfill(' ') << setw(10) << students[i].id;
                        cout << setw(13) << students[i].first;
                        cout << setw(19) << students[i].last;
                        cout << setw(7) << students[i].exam1;
                        cout << setw(7) << students[i].exam2;
                        cout << setw(6) << students[i].exam3;
                        cout << students[i].mean << endl;
                    }
                    cout << endl;
                }
                break;
            case 2: // add student
                //catch if the database is too full
                if(index > 19) {
                    cout << "Databse full. Cannot add a new student." << endl;
                    break;
                }
                //collect new info
                index++;
                cout << "Enter student's information\n Id: ";
                cin >> students[index - 1].id;
                cout << "First name: ";
                cin >> students[index - 1].first;
                cout << "Last name: ";
                cin >> students[index - 1].last;
                cout << "Exam 1 score: ";
                cin >> students[index - 1].exam1;
                cout << "Exam 2 score: ";
                cin >> students[index - 1].exam2;
                cout << "Exam 3 score: ";
                cin >> students[index - 1].exam3;
                students[index - 1].mean = ((students[index - 1].exam1 + students[index - 1].exam2 + students[index - 1].exam3) / 3.0); //calculate mean
                cout << "New student with id " << students[index - 1].id << " created." << endl;
                break;
            case 3: // update student
                //catch if there are no students
                if (index == 0)
                {
                    cout << "Error. No students in database." << endl;
                    break;
                }
                cout << "Please enter the id of the student you would like to alter: ";
                cin >> alterID;
                alterIndex = -1;
                //iterate through students array to find the desired ID
                for(int i = 0; i < index; i++) {
                    if(alterID == students[i].id) {
                        alterIndex = i;
                        break;
                    }
                }
                if(alterIndex == -1) {
                    cout << "No student exists in the database with id " << alterID << endl;
                }
                else {
                    //prompt user to update the information of a given student
                    cout << "Update information: " << endl;
                    cout << "Id: " << alterID << endl;
                    cout << "First name: ";
                    cin >> students[alterIndex].first;
                    cout << "Last name: ";
                    cin >> students[alterIndex].last;
                    cout << "Exam 1 score: ";
                    cin >> students[alterIndex].exam1;
                    cout << "Exam 2 score: ";
                    cin >> students[alterIndex].exam2;
                    cout << "Exam 3 score: ";
                    cin >> students[alterIndex].exam3;
                    students[alterIndex].mean = (students[alterIndex].exam1 + students[alterIndex].exam2 + students[index].exam3) / 3.0;
                    cout << "Student with id " << alterID << " has been updated." << endl;
                }
                break;
            case 4: // compute mean of all exams for all students
                if (index == 0)
                {
                    cout << "Error. No students in database." << endl;
                    break;
                }
                sum = 0.0;
                for(int i = 0; i < index; i++) {
                    sum += students[i].mean;
                }
                cout << "Mean of all exams: " << (sum / (index));
                break;
            case 5: // find the minimum of all exams for all students
                if (index == 0)
                {
                    cout << "Error. No students in database." << endl;
                    break;
                }
                minAvg = students[0].mean;
                for (int i = 0; i < index; i++)
                {
                    if(students[i].mean < minAvg) {
                        minAvg = students[i].mean;
                    }
                }
                cout << "Minimum of the mean of the exams: " << minAvg << endl;
                break;
            case 6: // find the maximum of all exams for all students
                if (index == 0)
                {
                    cout << "Error. No students in database." << endl;
                    break;
                }
                maxAvg = students[0].mean;
                for (int i = 0; i < index; i++)
                {
                    if (students[i].mean > maxAvg)
                    {
                        maxAvg = students[i].mean;
                    }
                }
                cout << "Maximum of the mean of the exams: " << maxAvg << endl;
                break;
            case 7: // exit the program
                cout << "Thank you for using this program. Goodbye." << endl;
                exit(1);
                break;
            default:
                cout << "Error. Improper value. Please Try Again" << endl;
                break;
        }
    }

    

    return 0;
}

/*
*   Description: Print out main menu
*   Arguements: None
*   Return: Void
*/
void printMenu() {
    cout << "\n*********************** Menu ********************** " << endl;
    cout << "\n| 1. Display list of students' information        |" << endl;
    cout << "\n| 2. Add student information                      |" << endl;
    cout << "\n| 3. Update student's information                 |" << endl;
    cout << "\n| 4. Compute mean of list of students exams       |" << endl;
    cout << "\n| 5. Compute minimum of the mean of the exams     |" << endl;
    cout << "\n| 6. Compute maximum of the mean of the exams     |" << endl;
    cout << "\n| 7. Exit program                                 |" << endl;
    cout << "\n***************************************************" << endl;
}

/*
*   Description: Print beginning class information
*   Arguements: None
*   Return: Void
*/
void printStart() {
    //print class information
    cout << "+" << setfill('-') << setw(65) << "+" << endl;
    cout << "|" << setfill(' ') << setw(65) << "|" << endl;
    cout << "   Computer Science and Engineering    " << endl;
    cout << "|" << setfill(' ') << setw(65) << "|" << endl;
    cout << "   CSCE 1040 - Computer Science II     " << endl;
    cout << "|" << setfill(' ') << setw(65) << "|" << endl;
    cout << "   Ethan El-Zayaty     ele0066     ethanel-zayaty@my.unt.edu   " << endl;
    cout << "|" << setfill(' ') << setw(65) << "|" << endl;
    cout << "+" << setfill('-') << setw(65) << "+" << endl;
}