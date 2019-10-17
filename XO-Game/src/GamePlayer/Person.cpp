#pragma once
#include <iostream>
#include <String>
using std::cout; using std::endl;
class Person
{
private:
	std::string Name;
	std::string emailId;
	int phoneNumber;

public:
	Person(std::string Name, std::string emailId, int phoneNumber)
	{
		this->Name = Name;
		this->emailId = emailId;
		this->phoneNumber = phoneNumber;
	}

	//get person name
	std::string getName() { return this->Name; }
	//get person emailid
	std::string getEmailId() { return this->emailId; }
	//get person phone number
	int getPhoneNumber() { return this->phoneNumber; }
	//display person details
	void displayDetails()
	{
		cout << "Name is" << Name << endl;
		cout << "Email Id is" << emailId << endl;
		cout << "Phone Number is" << phoneNumber << endl;
	}
};