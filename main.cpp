//
//  main.cpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#include "CourseViewer.hpp"
#include "FileReader.hpp"
#include <time.h>

using namespace std;

/**
 * Function to check each prerequisite is also in the list of courses
 *
 *@param curPrereq Course prerequisite to check
 *@param courseNumList List of courseNumbers to check curPrereq against
 */
int CheckPrereq(string curPrereq, vector<string> courseNumList) {
    unsigned int i;
    unsigned int counter = 0;
    for (i = 0; i < courseNumList.size(); ++i) {
        if (curPrereq == courseNumList[i])
            counter++;
    }
    if (!counter) {
        cout << "Prerequisite not in course list." << endl;
        return 0;
    }
    else
        return 1;
}

/**
 * Function to display number of clock ticks since
 *
 *@param ticks initial clock() tick count
 */
void DisplayClockTicks(clock_t ticks) {
    ticks = clock() - ticks; // current clock ticks minus starting clock ticks
    cout << "time: " << ticks << " clock ticks" << endl;
    cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
}

int main() {
    clock_t ticks; /// Timer variable
    BinarySearchTree* tree = new BinarySearchTree(); /// Pointer to the BST
    Course curCourse; /// Recycled variable that holds each course before it is added to a tree node
    vector<vector<string>> fileData; /// Each element is a vector that holds data for one line from CSV file
    vector<string> courseNumList; /// Each element the courseNumber from each line from CSV file
    string lavatory; /// 'Cleaner' variable to hold getline to clear the input buffer in case wrong input is entered.
    string userInput;
    unsigned int menuChoice = 8;
    unsigned int i;
    bool flag = false;
    
    while (menuChoice != 9) {
        cout << "Main Menu:" << endl;
        cout << "1. Load file data" << endl;
        cout << "2. Display list of all courses" << endl;
        cout << "3. Display data for one course" << endl;
        cout << "9. Exit the program" << endl;
        cout << "Enter the corresponding digit to make a menu selection." << endl;
        cin >> menuChoice;
        if (menuChoice != 9 && menuChoice != 1 &&
            menuChoice != 2 && menuChoice != 3) {
            cout << "Invalid menu selection." << endl;
            cin.clear();
            getline(cin, lavatory);
            continue;
        }
        cin.ignore();
        switch (menuChoice) {
            case 1: /// 1. Load file data
                ticks = clock();
                
                storeFileData(fileData, flag);
                if (flag) {
                    menuChoice = 9;
                    break;
                }
                /// Create list of all courseNumbers
                for (i = 0; i < fileData.size(); ++i)
                    courseNumList.push_back(fileData[i][0]);
                /// Store course data in Course objects,
                /// check to make sure all prerequisites are also courseNumbers
                for (i = 0; i < fileData.size(); ++i) {
                    curCourse.courseNumber = fileData[i][0];
                    curCourse.courseName = fileData[i][1];
                    if (fileData[i].size() > 2) {
                        curCourse.prereq1 = fileData[i][2];
                        if(!CheckPrereq(curCourse.prereq1, courseNumList)) {
                            menuChoice = 9;
                            break;
                        }
                    }
                    else
                        curCourse.prereq1 = "";
                    if (fileData[i].size() > 3) {
                        curCourse.prereq2 = fileData[i][3];
                        if(!CheckPrereq(curCourse.prereq2, courseNumList)) {
                            menuChoice = 9;
                            break;
                        }
                    }
                    else
                        curCourse.prereq2 = "";
                    if (fileData[i].size() > 4) {
                        curCourse.prereq3 = fileData[i][4];
                        if(!CheckPrereq(curCourse.prereq3, courseNumList)) {
                            menuChoice = 9;
                            break;
                        }
                    }
                    else
                        curCourse.prereq3 = "";
                    tree->Insert(curCourse);
                }
                DisplayClockTicks(ticks);
                break;
            case 2: /// 2. Display list of all courses
                ticks = clock();
                tree->DisplayCourseList();
                cout << endl;
                DisplayClockTicks(ticks);
                break;
            case 3: /// 3. Display data for one course
                cout << "Enter the Course Number you wish to view the details of: ";
                cin >> userInput;
                ticks = clock();
                tree->DisplayACourse(userInput);
                cout << endl;
                DisplayClockTicks(ticks);
                break;
            case 9:
                cout << "Thank you for using the CourseViewer program!" << endl;
                break;
        }
    }
    return 0;
}
