/*

*/


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Box {
public:
	Box(int length = 0, int breadth = 0, int height = 0):
		m_length(length), m_breadth(breadth), m_height(height){}
	//copy constructor
	Box(const Box& B) : m_length(B.m_length),
		m_breadth(B.m_breadth), m_height(B.m_height){}

	int getLength() { return m_length; }
	int getBreadth() { return m_breadth; }
	int getHeight() { return m_height; }
	long long CalculateVolume() { 
		long long res = m_length; res *= m_breadth;
		res *= m_height;
		return res;
	}

	friend bool operator< (Box& A, Box& B) {
		if ((A.m_length < B.m_length) 
			|| (A.m_length == B.m_length && A.m_breadth < B.m_breadth)
			|| (A.m_length == B.m_length && A.m_breadth == B.m_breadth
				&& A.m_height < B.m_height)) { return true; }
		else { return false; }
	}
	friend std::ostream& operator<< (ostream &out, const Box &B) {
		out << B.m_length << " " << B.m_breadth << " " << B.m_height;
		return out;
	}
private:
	long m_length;
	long m_height;
	long m_breadth;
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}


