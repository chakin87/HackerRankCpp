#include <iostream>
#include <sstream>
//using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
public://constructors
	Student() //:
		//m_age(15), m_first_name("john"),
		//m_last_name("carmack"), m_standard(10)
	{
		//std::cout << __FUNCTION__ << " Constructed\n" << std::endl;

	};
	~Student()
	{
		//std::cout << __FUNCTION__ << " Destructed\n" << std::endl;
	};
public://methods
	   //accessors
	int            get_age() { return m_age; };
	std::string    get_first_name() { return m_first_name; };
	std::string    get_last_name() { return m_last_name; };
	int            get_standard() { return m_standard; };
	void        to_string() {
		std::stringstream strStream;
		strStream << m_age;
		strStream << ",";
		strStream << m_first_name << "," << m_last_name << ",";
		strStream << m_standard;
		cout_inputs();
		std::cout << "\n" << strStream.str();
	}
	//mutators
	void set_age(int age) {
		this->m_age = age;
	};
	void set_first_name(std::string firstName) {
		this->m_first_name = firstName;
	};
	void set_last_name(std::string lastName) {
		this->m_last_name = lastName;
	};
	void set_standard(int standard) {
		this->m_standard = standard;
	};
	void set_all() {
		int iAge, iStd;
		std::string strFname, strLname;

		std::cin >> iAge;
		set_age(iAge);
	
		std::cin >> strFname;
		set_first_name(strFname);

		std::cin >> strLname;
		set_last_name(strLname);
		
		std::cin >> iStd;
		set_standard(iStd);

		
	};
private://methods
	void cout_inputs() {
		std::cout << get_age() << "\n";
		std::cout << get_last_name() << ", " << get_first_name() << "\n";
		std::cout << get_standard() << "\n";

	};
private://members
	int            m_age;
	std::string    m_first_name;
	std::string    m_last_name;
	int            m_standard;

};

int main() {
	{
		Student st;
		st.set_all();
		st.to_string();
	}
	    char pause;
	    std::cin >> pause;
	return 0;
}

