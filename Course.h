//============================================================================
// Name        : Course.h
// Author      : Devin Criswell
// Date        : 2/17/2024
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Project Two 
//============================================================================
#pragma once
#ifndef PROJECT_2_COURSE_H
#define PROJECT_2_COURSE_H

#include <string>
#include <vector>

class Course {
private:
	std::string courseId;
	std::string courseName;
	std::vector<std::string> coursePrerequisites;
public:
	Course() = default;
	Course(std::string& id, std::string& name, std::vector<std::string>& prerequisites);
	std::string getCourseId();
	std::string getCourseName();
	std::vector<std::string> getCoursePrerequisites();
	std::string courseToString();
};

#endif 
