/*
 * Author: Ryan Dougherty
 *
 * Description:
 This program checks whether argv[1] is already contained within a specific file.

 * Versions:
 v0.1: Initial Commit (Dec. 17, 2013)
 
 *
 *
*/

#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>

// input name is argv[1]
int main(int argc, const char * argv[])
{
	const char* file_name = "input.txt";
	std::ifstream inFile(file_name);
	if (!inFile) {
		std::cerr << "Problem reading file!\n";
		return EXIT_FAILURE;
	}
	std::vector<std::string> vec;
	std::string str;
	while (std::getline(inFile, str)) {
		vec.push_back(str);
	}
	if (std::find(vec.begin(), vec.end(), argv[1]) != std::end(vec)) {
		std::cout << "Company exists already\n";
		return EXIT_SUCCESS;
	} else {
		vec.push_back(argv[1]);
		std::sort(vec.begin(), vec.end());
		std::ofstream outFile(file_name);
		std::ostream_iterator<std::string> outIterator(outFile, "\n");
		std::copy(vec.begin(), vec.end(), outIterator);
	}
}