template<typename T>
struct functor_traits:public functor_traits<decltype(&T::operator())>{};
template<typename C,typename Ret,typename... Args>
struct functor_traits<Ret(C::*)(Args...)const>{
	template<size_t I>
	using nth_argument_type=typename tuple_element<I,tuple<Args...>>::type;
	using first_argument_type=nth_argument_type<0>;
};
template<typename Compare,typename T=typename decay<typename functor_traits<Compare>::first_argument_type>::type>
priority_queue<T,vector<T>,Compare> make_priority_queue(Compare comp){
	return priority_queue<T,vector<T>,Compare>(comp);
}
