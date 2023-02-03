// Project Proposal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
	string filename =  id + ".txt";
	fstream myFile;
	myFile.open(filename, ios::in);
	if (myFile.is_open()) {
		string line;
		while (getline(myFile, line)) {
			cout << line << endl;
		}
		myFile.close();
	}
}
void removeStudent() {
	string id;
	cout << "Enter Student ID Number: ";
	cin >> id;
	string filename = "C:\\Users\\TONI\\source\\repos\\clone(no view record and delete)\\" + id + ".txt";
	const char* filenamechar = filename.c_str();
	if (remove(filenamechar) != 0)cout << "Failed" << endl;
	else cout << "Deletion Success" << endl;
}
void editStudent() {
	string firstname, lastname, course, address, student;
	int p_grade, c_grade, m_grade, e_grade, cs_grade;

	cout << "Enter Student ID Number: ";
	getline(cin, student);
	cout << "New First Name: ";
	getline(cin, firstname);
	cout << "New Last Name: ";
	getline(cin, lastname);
	cout << "New Course: ";
	getline(cin, course);
	cout << "New Address: ";
	getline(cin, address);
	cout << "Enter New marks in Physics out of 100 : ";
	cin >> p_grade;
	cout << "Enter New marks in Chemistry out of 100 : ";
	cin >> c_grade;
	cout << "Enter New marks in Maths out of 100 : ";
	cin >> m_grade;
	cout << "Enter New marks in English out of 100 : ";
	cin >> e_grade;
	cout << "Enter New marks in Computer science out of 100 : ";
	cin >> cs_grade;
	cout << "Your New Average Grade is: " << calculate(p_grade, c_grade, m_grade, e_grade, cs_grade) << endl;

	string filename = student + ".txt";
	ofstream myFile2;
	myFile2.open(filename, ios::out);
	if (myFile2.is_open()) {

		myFile2 << "New Student ID Number: " << student << endl;
		myFile2 << "New First Name: " << firstname << endl;
		myFile2 << "New Last Name: " << lastname << endl;
		myFile2 << "New Course: " << course << endl;
		myFile2 << "New Address: " << address << endl;
		myFile2 << "New Marks in Physics: " << p_grade << endl;
		myFile2 << "New Marks in Chemistry: " << c_grade << endl;
		myFile2 << "New Marks in Maths: " << m_grade << endl;
		myFile2 << "New Marks in English: " << e_grade << endl;
		myFile2 << "New Marks in Computer Science: " << cs_grade << endl;
		myFile2 << "Your New Average is: " << calculate(p_grade, c_grade, m_grade, e_grade, cs_grade) << endl;
		myFile2.close();
	}
}
int main() {
	login();

	while (true) {
		cout << "***************************" << endl;
		cout << "Student Information System" << endl;
		cout << "1.ADD/EDIT STUDENT RECORD" << endl;
		cout << "2.SEARCH STUDENT" << endl;
		cout << "3.REMOVE STUDENT" << endl;
		cout << "4.EXIT" << endl;
		int userinput;
		cin >> userinput;
		switch (userinput) {
		case 1:
			system("cls");
			cin.ignore();
			editStudent();
			continue;
		case 2:
			system("cls");
			searchRecord();
			continue;		
		case 3:
			system("cls");
			removeStudent();
			continue;
		case 4:
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
