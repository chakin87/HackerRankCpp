/*
Printed Line 1

The manipulators I used here are hex (which will output the number in hexadecimal format), left (which will align the number to the left), showbase (which will make sure the hexadecimal number has a '0x' at the beginning), and nouppercase (which converts all alphabetic hexadecimal values to lowercase).

Printed Line 2 In this section, I actually have to undo some of the previous manipulations.

dec: switches numbers from hexadecimal back to decimal.
right: aligns values to the right instead of the left
setw(15): sets a fixed width of 15, as the effect from the initial code only impacts the first printed line.
setfill('_'): by default, when you have a fixed width, if your printed value doesn't fill up the entire length (for example, if you have a width of 15 and only print 7 characters), the extra characters used to pad are whitespaces. This function lets you change the padding to whatever character you want.
showpos: Makes sure there is a plus sign before any positive numbers
fixed: ensures that number is printed out entirely and that scientific notation isn't used for larger numbers
setprecision(2): sets the number of decimal places to 2.
Printed Line 3

scientific: Prints output in scientific notation format
uppercase: Undoes previous nouppercase manipulator and ensures that the 'E' in the scientific notation is capitalised
noshowpos: Undoes previous showpos manipulator and gets rid of the plus at the start of positive values
setprecision: Changes the number of digits after the decimal place from 2 to 9.
*/


#include <iostream>
#include <iomanip> 





int main() {
	int T; std::cin >> T;
	std::cout << std::setiosflags(std::ios::uppercase);
	std::cout << std::setw(0xf) << std::internal;
	while (T--) {
		double A; std::cin >> A;
		double B; std::cin >> B;
		double C; std::cin >> C;

		std::cout << std::hex << std::showbase << std::nouppercase << std::left;
		std::cout << (long long)A << std::endl;


		std::cout << std::setw(15) << std::showpos << std::setfill('_') << std::setprecision(2) << std::fixed << std::right;
		std::cout << B << std::endl;


		std::cout << std::scientific << std::setw(15) << std::setprecision(9) << std::uppercase << std::noshowpos;
		std::cout << C << std::endl;

	}
	system("pause");
	return 0;
}