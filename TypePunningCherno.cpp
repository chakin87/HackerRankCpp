#include <iostream>

//type punning
//get the type as a pointer and cast it as a different pointer;			


struct Entity {
	int x, y;

	int* GetPostions() {
		return &x;
	}
};

int main(int argc, char** argv) {

	Entity e = { 5, 8 };

	int* position = (int*)&e;

	int* position2 = e.GetPostions();
	position2[0] = 2;

	int y = *(int*)((char*)&e + 4);//int y = e.x;
	//this code should probably nexer exist

	std::cout << position[0] << ", " << position[1] << std::endl;
	
	std::cout << "y: " << y << std::endl;
	std::cin.get();
	return 0;
}