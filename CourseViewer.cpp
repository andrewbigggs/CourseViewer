//
//  CourseViewer.cpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#include "CourseViewer.hpp"

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::addNode(Course course) {
    if (root == nullptr) {
        root = new Node(course);
        return;
    }
    Node* curNode = root;
    while (curNode != nullptr) {
        if (course.courseNumber < curNode->data.courseNumber)
            curNode = curNode->left;
        if (course.courseNumber > curNode->data.courseNumber)
            curNode = curNode->right;
    }
    curNode->data = course;
}

void BinarySearchTree::inorderTraversalWithPrint(Node* node) {
    if (node->left != nullptr)
        inorderTraversalWithPrint(node->left);
    
    cout << node->data.courseNumber << ": " << node->data.courseName << endl;
    
    if (node->right != nullptr)
        inorderTraversalWithPrint(node->right);
}

void BinarySearchTree::searchNode(Node* node) {
    
}

void BinarySearchTree::Insert(Course course) {
    addNode(course);
}

void BinarySearchTree::DisplayCourseList() {
    inorderTraversalWithPrint(root);
}

void BinarySearchTree::DisplayACourse(string courseNum) {
    
}
