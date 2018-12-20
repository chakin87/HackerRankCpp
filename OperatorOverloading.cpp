#ifndef _POINT_H_
#define _POINT_H_

#include <string>

using namespace std;

//uses math cartesian coordinated

class Point
{
public:
	Point() { m_x = 0.0; m_y = 0.0; }
	Point(int x, int y) { m_x = x; m_y = y; }
	void setX(double data) { m_x = data; }
	void setY(double data) { m_y = data; }
	double getX() { return m_x; }
	double getY() { return m_y; }
	string toString();

private:
	double m_x;
	double m_y;
};

//>>>>>>>>>>MAY NEED FRIEND
MAY NEED FRIEND
MAY NEED FRIEND
MAY NEED FRIEND
MAY NEED FRIEND
MAY NEED FRIEND




// calling cout << point;
ostream& operator<<(ostream& o, Point p);
double operator-(Point p, Point q);

bool operator<(Point p, Point q);
bool operator==(Point p, Point q);

bool operator!=(Point p, Point q);
bool operator>=(Point p, Point q);
bool operator<=(Point p, Point q);
bool operator>(Point p, Point q);

#endif

#include <iostream>
#include <sstream>
#include <cmath>
#include "point.h"

using namespace std;

string Point::toString()
{
	stringstream theOutput;
	theOutput << "(" << m_x << ", " << m_y << ")";
	return theOutput.str();
}

ostream& operator<<(ostream& o, Point p)
{
	o << p.toString();
	return o;
}

double operator-(Point p, Point q)
{
	double xdiff = p.getX() - q.getX();
	double ydiff = p.getY() - q.getY();
	return sqrt(xdiff*xdiff + ydiff * ydiff);
}

bool operator<(Point p, Point q)
{
	Point origin(0, 0);
	double pdist = p - origin;
	double qdist = q - origin;
	//  return pdist < qdist;
	if (pdist < qdist)
		return true;
	else
		return false;
}

bool operator==(Point p, Point q)
{
	return (p.getX() == q.getX()) && (p.getY() == p.getY());
}

bool operator!=(Point p, Point q) { return !(p == q); }
bool operator>=(Point p, Point q) { return !(p < q); }
bool operator<=(Point p, Point q) { return (p < q) || p == q; }
bool operator>(Point p, Point q) { return !(p <= q); }



Following is complete C++ program to demonstrate overloading of <> operators.

#include <iostream> 
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0)
	{
		real = r;   imag = i;
	}
	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imagenory Part ";
	in >> c.imag;
	return in;
}

int main()
{
	Complex c1;
	cin >> c1;
	cout << "The complex object is ";
	cout << c1;
	return 0;
}


std::ostream& operator<<(std::ostream& os, const T& obj)
{
	// write obj to stream

	return os;
}

std::istream& operator>>(std::istream& is, T& obj)
{
	// read obj from stream

	if ( /* no valid object of T found in stream */)
		is.setstate(std::ios::failbit);

	return is;
}

inline bool operator==(const X& lhs, const X& rhs) { /* do actual comparison */ }
inline bool operator!=(const X& lhs, const X& rhs) { return !operator==(lhs, rhs); }
inline bool operator< (const X& lhs, const X& rhs) { /* do actual comparison */ }
inline bool operator> (const X& lhs, const X& rhs) { return  operator< (rhs, lhs); }
inline bool operator<=(const X& lhs, const X& rhs) { return !operator> (lhs, rhs); }
inline bool operator>=(const X& lhs, const X& rhs) { return !operator< (lhs, rhs); }
