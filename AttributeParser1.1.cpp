
#include <iostream>//std::cout, std::cin, std::getline
#include <cstdio>
#include <string>//needed for string work, 
#include <map>
#include <iterator>
#include <cctype>//isdigit()


struct apStruct {
	unsigned int crs;		//cursor
	unsigned int l;         //lines given
	unsigned int q;         //queries given
	unsigned int keylen;    //map key length
	unsigned int spc;       //count wich spc has been caught in line
	unsigned int taglen = 0;
	unsigned int recenttl = 0;

	std::string str;
	std::string keystr;
	std::string tkeystr;
	std::string valuestr;

	std::string namestr; // builds up tags ta1, tag1.tag2.tag3

	bool istag = false;

	std::map < std::string, std::string> mp;

	void resmems() {//-------------------------------------------------------START OF resmems();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		keylen = 0; spc = 0; taglen = 0;
		str = ""; keystr = ""; valuestr = "";
		bool istag = false;
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
	}//-------------------------------------------------------END OF resmems();-------------------------------------------------------

	void resnmstr() {//-------------------------------------------------------START OF resnmstr();-------------------------------------------------------
		//pop a ".tag" off of namestr
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		for (int z = 0; z < (recenttl + 1); ++z) {
			if (namestr.size() > 0) { namestr.pop_back(); }
			else { istag = false; }
		}
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
	}//-------------------------------------------------------END OF resnmstr();-------------------------------------------------------

	void setlq() {//-------------------------------------------------------START OF setlq();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		scanf_s("%d %d", &l, &q);
		std::cin.ignore(256, '\n');
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
	}//-------------------------------------------------------END OF setlq();-------------------------------------------------------

	void getnset() {//-------------------------------------------------------START OF getnset();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		resmems();
		std::getline(std::cin, str);
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
		gettag();
	}//-------------------------------------------------------END OF getnset();-------------------------------------------------------

	void gettag() {//-------------------------------------------------------START OF gettag();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '<') { ++i;
				if (str[i] == '/') {
					resnmstr();
					//std::cout << __FUNCDNAME__ << " ended vie if '/' " << std::endl;
					break;
				}
				else {
					if (istag) { namestr += '.'; }
					while (str[i] != ' ' && str[i] != '>') {
						if (!istag) { istag = true; }
						++taglen; namestr += str[i]; ++i;
					}
					if (str[i] == '>') {
						recenttl = taglen;
						return;
					}
					recenttl = taglen;
					++spc; crs = i;
					//std::cout << __FUNCDNAME__ << " ended vie if ' '" << std::endl;
					getkey();
				}
			}
		}
	}//-------------------------------------------------------END OF gettag();-------------------------------------------------------

	void getkey(){//------------------------------------------------------ - START OF getkey(); ------------------------------------------------------ -
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		++crs;
		while (str[crs] != ' ') {
			keystr += str[crs]; ++crs;

		}
		crs += 4;
		tkeystr = namestr; tkeystr += '~'; tkeystr += keystr;
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
		getval();
	}//-------------------------------------------------------END OF getkey();-------------------------------------------------------

	void getval() {//-------------------------------------------------------START OF getval();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		while (str[crs] != '"') {
			valuestr += str[crs]; ++crs;
		}
		++crs;
		//std::cout << "valuestr: " << valuestr << std::endl;
		//std::cout << "keystr:  " << keystr << std::endl;
		if (str[crs] == '>') {
			//std::cout << __FUNCDNAME__ << ", if '>' entered" << std::endl;
			//std::cout << tkeystr <<" " << valuestr << std::endl;
			mp[tkeystr] = valuestr;
			//std::cout << __FUNCDNAME__ << " , if '>' ended" << std::endl;
			return;
		}
		else if (str[crs] == ' ') {
			//std::cout << __FUNCDNAME__ << ", if ' ' entered" << std::endl;
			mp[tkeystr] = valuestr;;
			keystr = ""; valuestr = "";
			getkey();
		}
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
		return;
	}//----------------------------------------------END OF getval();-------------------------------------------------------

	void getq() {//-------------------------------------------------------START OF getq();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		{
			std::getline(std::cin, str);

			if (mp.find(str) == mp.end())
				std::cout << "Not Found!" << std::endl;
			else
				std::cout << mp[str] << std::endl;
		}
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
	}//-------------------------------------------------------END OF getq();-------------------------------------------------------

	void run() {//-------------------------------------------------------START OF run();-------------------------------------------------------
		//std::cout << __FUNCDNAME__ << " entered" << std::endl;
		setlq();

		for (int i = 0; i < l; ++i) {
			getnset();
		}
		for (int i = l; i < (l + q); ++i) {
			getq();
		}
		//std::cout << __FUNCDNAME__ << " ended" << std::endl;
	}//-------------------------------------------------------END OF run();-------------------------------------------------------

};


int main(int argc, char* argv[]) 
{
	
	apStruct a;

	a.run();

	system("pause");

	return 0;

}