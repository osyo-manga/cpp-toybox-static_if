#include <toybox/static_if.hpp>
#include <boost/type_traits/has_plus.hpp>
#include <iostream>
#include <string>

template<typename T>
auto
twice(T t){
	toybox::static_if<boost::has_plus<T, T>::value>(
		[](auto t){
			std::cout << t + t << std::endl;
		},
		[](...){
			std::cout << "Error" << std::endl;
		}
	)(t);
}


int
main(){
	twice(10);
	// => 20
	twice(std::string("homu"));
	// => "homuhomu"
	twice("mami");
	// => Error
	return 0;
}
