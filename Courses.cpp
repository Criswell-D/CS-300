//============================================================================
// Name        : Courses.cpp
// Author      : Devin Criswell
// Date        : 2/17/2024
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Project Two 
//============================================================================
#include <iostream>
#include <regex>
#include "Courses.h"

/**
 * Default constructor
 */
Courses::Courses() {
	root = nullptr;
}

/**
 * Destructor
 */
Courses::~Courses() {
	destroyRecursive(root);
}

/**
 * Traverse the tree in order
 */
void Courses::InOrder() {
	inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void Courses::PostOrder() {
	postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void Courses::PreOrder() {
	preOrder(root);
}

/**
 * Insert a course
 */
void Courses::Insert(Course course) {
	if (root == nullptr) {
		root = new Node(course);
	}
	else {

		this->addNode(root, course);
	}
}

/**
 * Remove a course
 */
void Courses::Remove(std::string courseId) {
	this->removeNode(root, courseId);
}

/**
 * Search for a course
 */
Course Courses::Search(std::string courseId) {
	transform(courseId.begin(), courseId.end(), courseId.begin(), ::toupper);
	Node* cur = root;
	while (cur != nullptr) {
		if (cur->course.getCourseId().compare(courseId) == 0) {
			return cur->course;
		}
		else if (courseId.compare(cur->course.getCourseId()) < 0) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
	Course course;
	return course;
}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void Courses::addNode(Node* node, Course course) {
	if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) > 0)) {
		if (node->left == nullptr) {
			node->left = new Node(course);
			return;
		}
		else {
			this->addNode(node->left, course);
		}
	}
	else if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) < 0)) {
		if (node->right == nullptr) {
			node->right = new Node(course);
			return;
		}
		else {
			this->addNode(node->right, course);
		}
	}
}

void Courses::destroyRecursive(Node* node) {
	if (node != nullptr) {
		destroyRecursive(node->left);
		destroyRecursive(node->right);
		delete node;
		node = nullptr;
	}
}

void Courses::inOrder(Node* node) {
	if (node != nullptr) {
		inOrder(node->left);
		std::cout << node->course.getCourseId() << ", "
			<< node->course.getCourseName() << std::endl;
		inOrder(node->right);
	}
}

void Courses::postOrder(Node* node) {
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->course.getCourseId() << ", "
			<< node->course.getCourseName() << std::endl;
	}
}

void Courses::preOrder(Node* node) {
	if (node != nullptr) {
		std::cout << node->course.getCourseId() << ", "
			<< node->course.getCourseName() << std::endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

Node* Courses::removeNode(Node* node, const std::string courseId) {
	if (node == nullptr) {
		return node;
	}
	else if (courseId.compare(node->course.getCourseId()) < 0) {
		node->left = removeNode(node->left, courseId);
	}
	else if (courseId.compare(node->course.getCourseId()) > 0) {
		node->right = removeNode(node->right, courseId);
	}
	else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		else if (node->left != nullptr && node->right == nullptr) {
			Node* tmp = node;
			node = node->left;
			delete tmp;
			tmp = nullptr;
		}
		else if (node->left == nullptr && node->right != nullptr) {
			Node* tmp = node;
			node = node->right;
			delete tmp;
			tmp = nullptr;
		}
		else {
			Node* tmp = node;
			while (tmp->left != nullptr) {
				tmp = tmp->left;
			}
			node->course = tmp->course;
			node->right = removeNode(node->right, tmp->course.getCourseId());
		}
	}
	return node;
}