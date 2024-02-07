#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef std::vector<std::string> Strings;
typedef std::map<char, Strings> Text;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments\n";
		return 1;
	}

	std::ifstream in(argv[1]);
	if (!in.is_open()) {
		std::cerr << "Failed to open input file!\n";
		return 1;
	}

	Text text;
	std::string line = "";

	while (getline(in, line))
		text[line[0]].push_back(line);
	in.close();

	for (auto& it : text)
		std::sort(it.second.begin(), it.second.end());

	char symbol;
	std::cout << "Enter symbol: ";
	std::cin >> symbol;

	if (text.find(symbol) == text.end()) {
		std::cout << "There are no lines starting with this character\n";
	}
	else {
		std::cout << "Strings start with " << symbol << ":\n";
		for (auto& it : text[symbol])
			std::cout << it << "\n";
	}

	return 0;
}