#ifndef EASYFIND_HPP
 #define EASYFIND_HPP


 #include <algorithm>
 #include <stdexcept>

 #define BOLD_CRIMSON "\033[1m\033[38;2;220;20;60m"
 #define RESET "\033[0m"

 template<typename T>
 typename T::iterator easyfind(T & non_associative_integer_container, 
								int const & integer_value_to_find)
 {
	typename T::iterator res = std::find(non_associative_integer_container.begin(), 
												non_associative_integer_container.end(), 
												integer_value_to_find);

	if (res == non_associative_integer_container.end())
		throw ( std::runtime_error(BOLD_CRIMSON "Value not found in the container" RESET) );

	return (res);
 }


#endif