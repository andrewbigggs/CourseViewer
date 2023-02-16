//
//  CourseViewer.hpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#ifndef CourseViewer_hpp
#define CourseViewer_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Course {
    string courseNumber;
    string courseName;
    string prereq1;
    string prereq2;
    string prereq3;
};

struct Node {
    Course data;
    Node* left;
    Node* right;
    
    Node() {
        left = nullptr;
        right = nullptr;
    }
    /// Initialize with a course
    Node(Course course) : Node() {
        data = course;
    }
};

class BinarySearchTree {
private:
    void addNode(Node* curNode, Course course);
    void inorderTraversalWithPrint(Node *node);
    int searchNode(string courseNum);
    
    Node* root;
    
public:
    BinarySearchTree();
    void Insert(Course course);
    void DisplayCourseList();
    void DisplayACourse(string courseNum);
};


#endif /* CourseViewer_hpp */
