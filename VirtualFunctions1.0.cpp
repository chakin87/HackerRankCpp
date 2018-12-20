#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define NUM_OF_MARKS 6

#include <memory>
class Person {
public:
	string m_name;
	int m_age;
	virtual void getdata() {
		cin >> this->m_name >> this->m_age;
	}
	virtual void putdata() {
		cout << this->m_name << " " << this->m_age << endl;
	}
};

class Professor : public Person {
public:
	Professor() {
		this->m_cur_id = ++id;
	}
	int m_publications;
	static int id;
	int m_cur_id;
	void getdata() {
		cin >> this->m_name >> this->m_age >> this->m_publications;
	}
	void putdata() {
		cout << this->m_name << " "
			<< this->m_age << " "
			<< this->m_publications << " "
			<< this->m_cur_id << endl;
	}
};
int Professor::id = 0;

class Student : public Person {
public:
	Student() {
		this->m_cur_id = ++id;
	}
	int m_marks[NUM_OF_MARKS];
	static int id;
	int m_cur_id;
	void getdata() {
		cin >> this->m_name >> this->m_age;
		for (int i = 0; i < NUM_OF_MARKS; i++) {
			cin >> m_marks[i];
		}
	}
	void putdata() {
		int marksSum = 0;
		for (int i = 0; i < NUM_OF_MARKS; i++) {
			marksSum += m_marks[i];
		}
		cout << this->m_name << " "
			<< this->m_age << " "
			<< marksSum << " "
			<< this->m_cur_id << endl;
	}
};
int Student::id = 0;
/*
class Believer : public Person {
	//God loves you! You are perfect in the Lord's eyes!
	//Drop to you knees and surrender.
	//"Like a rushing wind, Jesus breathes within.
	//Lord have your way, Lord have your way, in me!"
	class Salvation {};
	class GodsFavor {};
	class GiveGodGlory {};
	GodsFavor tithe(size_t tenPercentOfWage) {}
	GiveGodGlory praytotheLord() {
		std::cout << "Our Father who art in heaven,"
			<< " hallowed be thy name. Thy kingdom come, Thy will be done,"
			<< " on earth as it is in Heaven. Give us this day, our daily bread,"
			<< " and forgive us our sins, as we forgive those who sin"
			<< " against us. And lead us not into temptation, but deliver us from"
			<< " evil. For thine is the Kingdom, the power and the glory. Forever"
			<< " and ever, Amen!" << std::endl;
	}
	GodsFavor goToChurch(){}
	Salvation repentAndAcceptsJesusAsYourSavior(const char surrender) {}

};
*/
int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}
