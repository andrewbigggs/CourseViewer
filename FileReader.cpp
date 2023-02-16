//
//  FileReader.cpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#include "FileReader.hpp"

/**
 * @param allData Reference to a vector, containing a vector of strings for each line in the CSV file
 * @param flag Boolean variable that will be set to true if the main program should exit
 *
 * Credit: https://www.geeksforgeeks.org/csv-file-management-using-c/
 * Credit: https://stackoverflow.com/a/37957126/21148021
 */
void storeFileData(vector<vector<string>>& allData, bool& flag) {
    fstream fin;
    string userInput;
    string cell, line;
    vector<string> row;
    
    cout << "Type the filename (including extension) you'd like to open." << endl;
    cin >> userInput;
    fin.open(userInput);
    if (!fin.is_open()) {
        cout << "Failed to open file " << "\"" << userInput << "\"" << endl;
        return;
    }
    
    while (getline(fin, line)) {
        row.clear();
        stringstream ss(line);
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
            cout << cell << endl;
        }
        allData.push_back(row);
        if (row.size() < 2) {
            cout << "Error: A line in the CSV file contains less than two values." << endl;
            flag = true;
            return;
        }
    }
}
