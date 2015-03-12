#ifndef TOYBOX_STATIC_IF_H
#define TOYBOX_STATIC_IF_H

#include <utility>

namespace toybox{

template<typename Then, typename Else>
auto
static_if(std::integral_constant<bool, true>, Then then, Else){
	return then;
}


template<typename Then, typename Else>
auto
static_if(std::integral_constant<bool, false>, Then, Else else_){
	return else_;
}


template<bool Cond, typename Then, typename Else>
auto
static_if(Then then, Else else_){
	return static_if(std::integral_constant<bool, Cond>{}, then, else_);
}


template<bool Cond, typename Then>
auto
static_if(Then then){
	return static_if<Cond>(then, [](...){});
}


}  // namespace toybox

#endif /* TOYBOX_STATIC_IF */
