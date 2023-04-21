#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

typedef std::vector<std::string> Strings;
typedef std::map<char, Strings> Text;

int main(int argc, char* argv[])
{
	std::ifstream in(argv[1]);
	if (!in.is_open())
	{
		throw std::runtime_error("Failed to open input file!");
		return 1;
	}

	Text text;

	std::string line = "";

	while (getline(in, line))
	{
		text[line[0]].push_back(line);
	}

	for (auto& it : text)
	{
		std::cout << "Letter: " << it.first << "\n";

		for (auto& it2 : it.second)
		{
			std::cout << it2 << "\n";
		}
		std::cout << "\n";
	}

	in.close();

	return 0;
}