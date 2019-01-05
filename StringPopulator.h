#ifndef STRINGPOPULATOR_H
#define STRINGPOPULATOR_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

class StringPopulator
{
public: // Constructors/Destructor - not really  needed...
	StringPopulator();
	~StringPopulator();

public: // Methods
	// Random string generators
	static std::string rand_lowercase_al_str(int length_of_string);
	static std::string rand_uppercase_al_str(int length_of_string);
	static std::string rand_lowercase_alnum_str(int length_of_string);
	static std::string rand_uppercase_alnum_str(int length_of_string);
	static std::string rand_num_str(int length_of_string);
	// Boolean string functions
	bool is_char_instring(const char char_to_find, const std::string& string_to_search_in);

private: // Members
	// string pools
	
	
	
	
	

	// Other goodies
	;
	
};

#endif //STRINGPOPULATOR_H
