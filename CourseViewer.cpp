//
//  CourseViewer.cpp
//  CourseViewer
//
//  Created by Andrew J Biggs on 2/13/23.
//

#include "CourseViewer.hpp"

/**
 * Default constructor
 */
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

/**
 * Visit each node, display courseNumber and courseName
 *
 *@param node Node to begin the traversal from (effective root node)
 */
void BinarySearchTree::inorderTraversalWithPrint(Node* node) {
    if (node->left != nullptr)
        inorderTraversalWithPrint(node->left);
    
    cout << node->data.courseNumber << ": " << node->data.courseName << endl;
    
    if (node->right != nullptr)
        inorderTraversalWithPrint(node->right);
}

/**
 * Determine if a courseNumber matches the courseNumber of a node in the tree,
 * display that node's info.
 *
 *@param courseNum The courseNumber to search for
 */
void BinarySearchTree::searchNode(string courseNum) {
    Node* node = root;
    while (node != nullptr) {
        if (courseNum < node->data.courseNumber) {
            node = node->left;
            continue;
        }
        if (courseNum > node->data.courseNumber) {
            node = node->right;
            continue;
        }
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
            return;
        }
    }
    cout << courseNum << " not found in database." << endl;
}

/**
 * Insert a node in the appropriate position in the tree.
 *
 *@param course The course object that will belong to the node being inserted
 */
void BinarySearchTree::Insert(Course course) {
    if (root == nullptr)
        root = new Node(course);
    else
        addNode(root, course);
}

/**
 * Display all courses
 */
void BinarySearchTree::DisplayCourseList() {
    inorderTraversalWithPrint(root);
}

/**
 * Search for a specific course by its courseNumber
 *
 *@param courseNum The courseNumber to search for
 */
void BinarySearchTree::DisplayACourse(string courseNum) {
    searchNode(courseNum);
}
