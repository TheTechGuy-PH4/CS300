// Project One - Practice Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Courses {

private:
	string courseNumber;
	string title;
	string prereq1;
	string prereq2;
public:
	void setCourseNum(string cn) {
		courseNumber = cn;
	}
	void setTitle(string t) {
		title = t;
	}
	void setPrereq1(string pr1) {
		prereq1 = pr1;
	}
	void setPrereq2(string pr2) {
		prereq2 = pr2;
	}
	string GetCourseNumber() {
		return courseNumber;
	}
	string GetTitle() {
		return title;
	}
	string GetPrereq1() {
		if (!prereq1.empty()) {
			return prereq1;
		}
		else {
			return "None";
		}
	}
	string GetPrereq2() {
		if (!prereq2.empty()) {
			return prereq2;
		}
		else {
			return "None";
		}
	}
	int Count() {
		int count = 0;
		if (!prereq1.empty() && !prereq2.empty()) {
			count = count + 2;
			return count;
		}
		else if (!prereq1.empty() && prereq2.empty()) {
			count++;
			return count;
		}
		else {
			return count;
		}
	}

	void printCourseInformation() {
		cout << endl;
		cout << "Course Number: " << GetCourseNumber() << " | Title: " << GetTitle() << " | Prereq #1: " << GetPrereq1() << " | Prereq #2: " << GetPrereq2() << endl;
		cout << endl;
		cout << "==========================================================================================================================" << endl;
		cout << endl;
	}
};


int main(int argc, char* argv[])
{
	vector<Courses> curriculum;
	Courses currCourse;
	ifstream file;
	string crNum;
	string title;
	string prereq1;
	string prereq2;
	string line;
	int count = 0;
	int i;
	int choice;
	int sumPre = 0;

	while (choice != 0) {
		cout << "Menu:" << endl;
		cout << "1. Load Curriculum" << endl;
		cout << "2. Search Specific Course" << endl;
		cout << "3. Print Full Curriculum" << endl;
		cout << "4. Sum of Prerequisites" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				file.open("Curriculum.txt");
				if (!file.is_open()) {
					cout << "Could not open file Document" << endl;
				}

				while (!file.eof()) {

					getline(file, line);

					for (int i = 0; i < line.size(); i++) {
						if (line[i] == ',') {
							count++;
						}
					}
					while (!line.empty()) {

						int ch;

						if (count == 3) {

							crNum = " ";
							ch = line.find(',');
							crNum = line.substr(0, ch);
							currCourse.setCourseNum(crNum);
							line = line.erase(0, ch + 1);

							title = " ";
							ch = line.find(',');
							title = line.substr(0, ch);
							currCourse.setTitle(title);
							line = line.erase(0, ch + 1);

							prereq1 = " ";
							ch = line.find(',');
							prereq1 = line.substr(0, ch);
							currCourse.setPrereq1(prereq1);
							line = line.erase(0, ch + 1);

							prereq2 = " ";
							ch = line.find('\n');
							prereq2 = line.substr(0, ch);
							currCourse.setPrereq2(prereq2);
							line = line.erase(0, ch);
						}
						else if (count == 2) {
							crNum = " ";
							ch = line.find(',');
							crNum = line.substr(0, ch);
							currCourse.setCourseNum(crNum);
							line = line.erase(0, ch + 1);

							title = " ";
							ch = line.find(',');
							title = line.substr(0, ch);
							currCourse.setTitle(title);
							line = line.erase(0, ch + 1);

							prereq1 = " ";
							ch = line.find('\n');
							prereq1 = line.substr(0, ch);
							currCourse.setPrereq1(prereq1);
							prereq2 = " ";
							currCourse.setPrereq2(prereq2);
							line = line.erase(0, ch);


						}
						else if (count == 1) {
							crNum = " ";
							ch = line.find(',');
							crNum = line.substr(0, ch);
							currCourse.setCourseNum(crNum);
							line = line.erase(0, ch + 1);

							title = " ";
							ch = line.find('\n');
							title = line.substr(0, ch);
							currCourse.setTitle(title);
							prereq1 = " ";
							currCourse.setPrereq1(prereq1);
							prereq2 = " ";
							currCourse.setPrereq2(prereq2);
							line = line.erase(0, ch);



						}
					}

					curriculum.push_back(currCourse);
					count = 0;
				}
				cout << "Curriculum Loaded Successfully" << endl;
				break;

			case 2: 
				cout << "Enter Course Number" << endl;
				cin >> crNum;
				for (i = 0; i < curriculum.size(); i++) {
					if (crNum == curriculum.at(i).GetCourseNumber()) {
						curriculum.at(i).printCourseInformation();
					}

					if (i == curriculum.size() - 1 && crNum != curriculum.at(i).GetCourseNumber())
						cout << "Error: Course Not Found" << endl;
				}
				break;

			case 3:
				for (i = 0; i < curriculum.size(); i++) {
					curriculum.at(i).printCourseInformation();
				}
				break;
			
			case 4: 
				cout << endl;
				cout << "Enter Course Number" << endl;
				cin >> crNum;
				for (i = 0; i < curriculum.size(); i++) {
					if (crNum == curriculum.at(i).GetCourseNumber()) {
						sumPre = sumPre + curriculum.at(i).Count();
						cout << endl;
						cout << "Prerequisite Total For Course: " << sumPre << endl;
						cout << endl;
						curriculum.at(i).printCourseInformation();
					}
					
					if (i == curriculum.size() - 1 && crNum != curriculum.at(i).GetCourseNumber())
						cout << "Error: Course Not Found" << endl;

				}
				break;

		}

		
	}
	cout << "Good bye." << endl;


	

	
}
