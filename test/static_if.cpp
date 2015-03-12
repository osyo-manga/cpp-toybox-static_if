#include "../lib/toybox/static_if.hpp"
#include <cassert>


using toybox::static_if;

template<int N>
int
test(){
	return static_if<(N > 0)>(
		[](auto n){
			return N + test<decltype(n){}-1>();
		},
		[](...){
			return N;
		}
	)(std::integral_constant<int, N>{});
}

template<typename T>
auto
is_int(T t){
	return static_if<std::is_same<T, int>{}>(
		[](auto t){
			return t + t;
		},
		[](...){
			return -1;
		}
	)(t);
}


int
main(){
	assert(test<5>() == 15);

	assert(is_int(3) == 6);
	assert(is_int("") == -1);
	
	int value = 0;
	auto f = [&]{ value = 42; };
	static_if<false>(f)();
	assert(value == 0);

	static_if<true>(f)();
	assert(value == 42);
	
	return 0;
}
