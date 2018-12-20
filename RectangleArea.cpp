#include <iostream>
#include <string>


class Rectangle {
public:
	Rectangle() {}
	Rectangle(int width, int height): m_width(width), m_height(height) {

	}

	void display() {
		std::cout << m_width << " " << m_height << std::endl;
	}

	void setWidthHeight(int width, int height) {
		m_width = width;
		m_height = height;
	}
	int get_area() {
		return m_width * m_height;
	}
private:
	int	m_width;
	int m_height;

};

class RectangleArea : public Rectangle {
public:
	void read_input() {
		int w, h;
		std::cin >> w >> h;
		setWidthHeight(w, h);
	}

	void display() {
		std::cout << get_area();
	}

private:


};




int main(int argc, char** argv[]) {
//int  main(){

		/*
	 * Declare a RectangleArea object
	 */
	RectangleArea r_area;

	/*
	 * Read the width and height
	 */
	r_area.read_input();

	/*
	 * Print the width and height
	 */
	r_area.Rectangle::display();

	/*
	 * Print the area
	 */
	r_area.display();


	system("pause");
	return 0;



}