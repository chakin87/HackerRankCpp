#include <iostream>
#include <string>



template<typename T>// typename is the template param
	//T is the variable name
void print(T value) {
	std::cout << value << std::endl;
}



template<typename T, int N>
//look at alloc a for array init 
class Array {
private:
	T m_Array[];
public:
	int GetSize() const { return N; }
};


int main() {
	
	Array<int, 5> array1;

	int j;

	//Array<j> array2;

	print("hello");
	print(55);
	print(6.45f);

	print<int>(5.5); // can define type  <type> 

	std::cin.get();
	return 0;
}