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

/**
 * Add a Course to some node (recursive)
 *
 * @param curNode Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node* curNode, Course course) {
    /// Find the bid's spot in the Tree by recursive searching the nodes for its appropriate location
    /// Add node to left subtree
    if (curNode->data.courseNumber > course.courseNumber) {
        if (curNode->left == nullptr) {
            curNode->left = new Node(course);
        }
        else
            this->addNode(curNode->left, course);
    }
    /// Add node to right subtree
    else {
        if (curNode->right == nullptr) {
            curNode->right = new Node(course);
        }
        else
            this->addNode(curNode->right, course);
    }
}

void BinarySearchTree::inorderTraversalWithPrint(Node* node) {
    if (node->left != nullptr)
        inorderTraversalWithPrint(node->left);
    
    cout << node->data.courseNumber << ": " << node->data.courseName << endl;
    
    if (node->right != nullptr)
        inorderTraversalWithPrint(node->right);
}

int BinarySearchTree::searchNode(string courseNum) {
    Node* node = root;
    while (node != nullptr) {
        if (courseNum < node->data.courseNumber)
            node = node->left;
        if (courseNum > node->data.courseNumber)
            node = node->right;
        if (courseNum == node->data.courseNumber) {
            cout << courseNum << ": " << node->data.courseName << endl;
            if (node->data.prereq1 == "")
                cout << "No Prerequisites" << endl;
            else {
                cout << "Prerequisites: " << node->data.prereq1 << endl;
                if (node->data.prereq2 != "") {
                    cout << "               " << node->data.prereq2 << endl;
                    if (node->data.prereq3 != "") {
                        cout << "               " << node->data.prereq3 << endl;
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

void BinarySearchTree::Insert(Course course) {
    if (root == nullptr)
        root = new Node(course);
    else
        addNode(root, course);
}

void BinarySearchTree::DisplayCourseList() {
    inorderTraversalWithPrint(root);
}

void BinarySearchTree::DisplayACourse(string courseNum) {
    if (!searchNode(courseNum))
        cout << courseNum << " not found in database." << endl;
}
