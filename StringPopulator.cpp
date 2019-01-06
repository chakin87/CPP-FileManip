#include "StringPopulator.h"




StringPopulator::StringPopulator()
{
}


StringPopulator::~StringPopulator()
{
}

std::string StringPopulator::rand_lowercase_al_str(int length_of_string = 8)
{
	const std::string lwrcs = "abcdefghijklmnopqrstuvwxyz";
	std::string str = "";
	while (str.size() < length_of_string) str += lwrcs[rand()%lwrcs.size()];
	return str;
}

std::string StringPopulator::rand_uppercase_al_str(int length_of_string = 8)
{
	const std::string uprcs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string str = "";
	//std::default_random_engine ran(std::time(0));
	//std::uniform_int_distribution<int> distribution(0, uprcs.size() - 1);
	while (str.size() < length_of_string) str += uprcs[rand()% uprcs.size()/*distribution(ran)*/];
	return str;
}

std::string StringPopulator::rand_lowercase_alnum_str(int length_of_string = 8)
{
	const std::string lwrcsalnum = "abcdefghijklmnopqrstuvwxyz1234567890";
	std::string str = "";
	while (str.size() < length_of_string) str += lwrcsalnum[rand()% lwrcsalnum.size()];
	return str;
}

std::string StringPopulator::rand_uppercase_alnum_str(int length_of_string = 8)
{
	const std::string uprcsalnum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string str = "";
	while (str.size() < length_of_string) str += uprcsalnum[rand()% uprcsalnum.size()];
	return str;
}

std::string StringPopulator::rand_num_str(int length_of_string = 8)
{
	const std::string num = "1234567890";
	std::string str = "";
	while (str.size() < length_of_string) str += num[rand()% num.size()];
	return str;
}

bool StringPopulator::is_char_instring(const char char_to_find, const std::string& string_to_search_in)
{
	for (auto it : string_to_search_in) {
		if (it == char_to_find) {
			return true;
		}
	}
	return false;
}
