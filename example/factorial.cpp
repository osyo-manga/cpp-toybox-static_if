#include <toybox/static_if.hpp>
#include <iostream>

template<int N>
int
factorial(){
	return toybox::static_if<(N > 0)>(
		[](auto n){
			return N + factorial<decltype(n){}-1>();
		},
		[](...){
			return N;
		}
	)(std::integral_constant<int, N>{});
}


int
main(){
	std::cout << factorial<10>() << std::endl;
	return 0;
}
