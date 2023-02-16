//
//  main.cpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#include "CourseViewer.hpp"
#include "FileReader.hpp"

using namespace std;

/**
 * Function to check each prerequisite is also in the list of courses
 */
int CheckPrereq(Course curCourse, vector<string> courseNumList) {
    unsigned int i;
    unsigned int counter = 0;
    for (i = 0; i < courseNumList.size(); ++i) {
        if (curCourse.prereq1 == courseNumList[i])
            counter++;
    }
    if (!counter) {
        cout << "Prerequisite not in course list." << endl;
        return 0;
    }
    else
        return 1;
}

int main() {
    BinarySearchTree tree;
    Course curCourse;
    vector<vector<string>> fileData;
    vector<string> courseNumList;
    string lavatory;
    unsigned int menuChoice = 8;
    unsigned int i;
    bool flag = false;
    
    while (menuChoice != 9) {
        cout << "Main Menu:" << endl;
        cout << "1. Load file data" << endl;
        cout << "2. Display list of all course numbers" << endl;
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
            case 1:
                storeFileData(fileData, flag);
                if (flag) {
                    menuChoice = 9;
                    break;
                }
                
                for (i = 0; i < fileData.size(); ++i)
                    courseNumList.push_back(fileData[i][0]);
                /// Store course data in Course objects
                for (i = 0; i < fileData.size(); ++i) {
                    curCourse.courseNumber = fileData[i][0];
                    curCourse.courseName = fileData[i][1];
                    if (fileData[i].size() > 2) {
                        curCourse.prereq1 = fileData[i][2];
                        if(!CheckPrereq(curCourse, courseNumList)) {
                            menuChoice = 9;
                            break;
                        }
                    }
                    else
                        curCourse.prereq1 = "";
                    if (fileData[i].size() > 3)
                        curCourse.prereq2 = fileData[i][3];
                    else
                        curCourse.prereq2 = "";
                    if (fileData[i].size() > 4)
                        curCourse.prereq3 = fileData[i][4];
                    else
                        curCourse.prereq3 = "";
                }
                break;
            case 2:
                tree.DisplayCourseList();
                break;
            case 3:
                break;
            case 9:
                cout << "Thank you for using the CourseViewer program!" << endl;
                break;
        }
    }
    return 0;
}
