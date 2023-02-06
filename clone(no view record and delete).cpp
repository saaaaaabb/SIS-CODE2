// Project Proposal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"
#include <map>
using ordered_json = nlohmann::ordered_json;
using namespace std;
string firstname, lastname, course, address, student;
int p_grade, c_grade, m_grade, e_grade, cs_grade;

map<string, string>studentdata;

map<string, map<string, string>>studentlist =
{
	{student, studentdata}

};
ordered_json studentdb;
void viewAll() {
	for (auto const& students : studentlist) {
		if (students.first.empty()) continue;
		cout << students.first << endl;
		cout << "First Name: " << studentlist[students.first]["First Name"] << endl;
		cout << "Last Name: " << studentlist[students.first]["Last Name"] << endl;
		cout << "Course: " << studentlist[students.first]["Course"] << endl;
		cout << "Address: " << studentlist[students.first]["Address"] << endl;
		cout << "Physics: " << studentlist[students.first]["Physics"] << endl;
		cout << "Chemistry: " << studentlist[students.first]["Chemistry"] << endl;
		cout << "Math: " << studentlist[students.first]["Math"] << endl;
		cout << "English: " << studentlist[students.first]["English"] << endl;
		cout << "Computer Science: " << studentlist[students.first]["Computer Science"] << endl;
		cout << endl;
	}
}
void updateMap(string id) {
	studentlist[id] =
	{
	{"First Name", firstname},
	{"Last Name", lastname},
	{"Course", course},
	{"Address", address},
	{"Physics",to_string(p_grade)},
	{"Chemistry", to_string(c_grade)},
	{"Math", to_string(m_grade)},
	{"English", to_string(e_grade)},
	{"Computer Science", to_string(cs_grade)}
	};
}
void serialize() {
	ofstream userout;
	studentdb.clear();
	for (auto const& id : studentlist) {
		if (id.first.empty()) continue;
		studentdb[id.first]["First Name"] = studentlist[id.first]["First Name"];
		studentdb[id.first]["Last Name"] = studentlist[id.first]["Last Name"];
		studentdb[id.first]["Course"] = studentlist[id.first]["Course"];
		studentdb[id.first]["Address"] = studentlist[id.first]["Address"];
		studentdb[id.first]["Physics"] = studentlist[id.first]["Physics"];
		studentdb[id.first]["Chemistry"] = studentlist[id.first]["Chemistry"];
		studentdb[id.first]["Math"] = studentlist[id.first]["Math"];
		studentdb[id.first]["English"] = studentlist[id.first]["English"];
		studentdb[id.first]["Computer Science"] = studentlist[id.first]["Computer Science"];
	}
	userout.open("studentdb.json", ios::out);
	userout << std::setw(4) << studentdb << std::endl;
	userout.close();
}
void deserialize() {
	ifstream studentin("studentdb.json");
	studentin >> studentdb;
	for (auto& id : studentdb.items()) {
		studentlist[id.key()]["First Name"] = studentdb[id.key()]["First Name"].get<string>();
		studentlist[id.key()]["Last Name"] = studentdb[id.key()]["Last Name"].get<string>();
		studentlist[id.key()]["Course"] = studentdb[id.key()]["Course"].get<string>();
		studentlist[id.key()]["Address"] = studentdb[id.key()]["Address"].get<string>();
		studentlist[id.key()]["Physics"] = studentdb[id.key()]["Physics"].get<string>();
		studentlist[id.key()]["Chemistry"] = studentdb[id.key()]["Chemistry"].get<string>();
		studentlist[id.key()]["Math"] = studentdb[id.key()]["Math"].get<string>();
		studentlist[id.key()]["English"] = studentdb[id.key()]["English"].get<string>();
		studentlist[id.key()]["Computer Science"] = studentdb[id.key()]["Computer Science"].get<string>();
	}
	studentin.close();
}
int login()
{
	string username;
	string password;
	int loginAttempt = 0;

	while (loginAttempt < 5) {
		cout << "*****************************************" << endl;
		cout << "                  Login                  " << endl;
		cout << "*****************************************" << endl;
		cout << "\nEnter Username :";
		cin >> username;
		cout << "\nEnter Password :";
		cin >> password;

		if (username == "user" && password == "pass") {
			cout << "Welcome" << endl;
			break;
		}
		else {
			cout << "Please check your username or password" << endl;
			loginAttempt++;
		}
	}
	if (loginAttempt == 5) {
		cout << "Too many login";
		return 0;
	}
	system("cls");
}
float calculate(int p_grade, int c_grade, int m_grade, int e_grade, int cs_grade) {

	return (p_grade + c_grade + m_grade + e_grade + cs_grade) / (float)5;
}
void searchRecord() {
	string id;
	cout << "Enter Student ID: ";
	cin >> id;
	if (studentlist.contains(id)) {
		cout << "First Name: " << studentlist[id]["First Name"] << endl;
		cout << "Last Name: " << studentlist[id]["Last Name"] << endl;
		cout << "Course: " << studentlist[id]["Course"] << endl;
		cout << "Address: " << studentlist[id]["Address"] << endl;
		cout << "Physics: " << studentlist[id]["Physics"] << endl;
		cout << "Chemistry: " << studentlist[id]["Chemistry"] << endl;
		cout << "Math: " << studentlist[id]["Math"] << endl;
		cout << "English: " << studentlist[id]["English"] << endl;
		cout << "Computer Science: " << studentlist[id]["Computer Science"] << endl;
	}
}
void removeStudent() {
	string id;
	cout << "Enter Student ID Number: ";
	cin >> id;
	if (studentlist.erase(id) <= 0)cout << "Failed" << endl;
	else { 
		studentlist.erase(id);
		cout << "Deletion Success" << endl; 
	}
}
void editStudent() {

	cout << "Enter Student ID Number: ";
	getline(cin, student);
	cout << "First Name: ";
	getline(cin, firstname);
	cout << "Last Name: ";
	getline(cin, lastname);
	cout << "Course: ";
	getline(cin, course);
	cout << "Address: ";
	getline(cin, address);
	cout << "Enter marks in Physics out of 100 : ";
	cin >> p_grade;
	cout << "Enter marks in Chemistry out of 100 : ";
	cin >> c_grade;
	cout << "Enter marks in Maths out of 100 : ";
	cin >> m_grade;
	cout << "Enter marks in English out of 100 : ";
	cin >> e_grade;
	cout << "Enter marks in Computer science out of 100 : ";
	cin >> cs_grade;
	cout << "Your Average Grade is: " << calculate(p_grade, c_grade, m_grade, e_grade, cs_grade) << endl;

	updateMap(student);
}
int main() {
	deserialize();
	login();

	while (true) {
		cout << "***************************" << endl;
		cout << "Student Information System" << endl;
		cout << "1.ADD/EDIT STUDENT RECORD" << endl;
		cout << "2.SEARCH STUDENT" << endl;
		cout << "3.REMOVE STUDENT" << endl;
		cout << "4.VIEW ALL" << endl;
		cout << "5.EXIT" << endl;
		int userinput;
		cin >> userinput;
		switch (userinput) {
		case 1:
			system("cls");
			cin.ignore();
			editStudent();
			serialize();
			continue;
		case 2:
			system("cls");
			searchRecord();
			continue;		
		case 3:
			system("cls");
			removeStudent();
			serialize();
			continue;
		case 4:
			system("cls");
			viewAll();
			continue;
		case 5:
			system("cls");
			cout << "THANK YOU" << endl;
			break;
		default:
			cout << "NOT IN THE CHOICES";
			continue;
		}
		break;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
