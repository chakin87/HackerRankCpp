#include <algorithm>
#include <string>
#include <map>
#include <iostream>

//Here the pair is inserted into the map where the key 
//is "hello" and the value associated with it is 9
/*m.insert(make_pair("hello",9)); 

//Erases the pair from the map where the key_type is val.
m.erase(val); 

//Gives the iterator to the element val if it is found
//otherwise returns m.end() .
map<string,int>::iterator itr=m.find(val);

//If Maps is not present as the key value then itr==m.end().
Ex: map<string,int>::iterator itr=m.find("Maps"); 

To get the value stored of the key "MAPS" we can do m["MAPS"] or
we can get the iterator using the find function and then by itr->second 
we can access the value.
*/

/*
"Do not grieve, for the joy of the Lord is your strength."
		Nehemiah 8:10
*/


int main(int argc, char** argv[]) {

	size_t a, b, c, d, e, f, g;

	std::string s;

	std::map<std::string, size_t> m;

	scanf_s("%zu", &a);

	for (b = 0; b < a; ++b) {
		
		std::cin >> c >> s;

		switch (c) {
		case 1:
			std::cin >> d;
			m[s] += d;
			break;
		case 2:
			m[s] = 0;
			break;
		case 3:
			std::cout << m[s] << std::endl;
			break;
		default:
			std::cout << "I don't know what to do!"
				<< "I better say a prayer that "
				<< "my program doesn't CRASH!"
				<< std::endl;
			break;
		}
	}
	system("pause");

	return 0;
}