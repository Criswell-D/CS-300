//============================================================================
// Name        : Course.cpp
// Author      : Devin Criswell
// Date        : 2/17/2024
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Project Two 
//============================================================================
#include "Course.h"

///  Course object
Course::Course(std::string& id, std::string& name, std::vector<std::string>& prerequisites) {
	this->courseId = id;
	this->courseName = name;
	this->coursePrerequisites = prerequisites;
}

/// gets course id
std::string Course::getCourseId() {
	return this->courseId;
}

/// gets course name.
std::string Course::getCourseName() {
	return this->courseName;
}

/// gets course prerequisites.
std::vector<std::string> Course::getCoursePrerequisites() {
	return this->coursePrerequisites;
}

/// returns string of course values.
std::string Course::courseToString() {
	return this->courseId + ", " + this->courseName;
}