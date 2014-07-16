// https://ideone.com/TimImn

template<typename Functor>
struct functor_traits{
	template<typename C,typename Ret,typename Arg,typename... Args>
	static Arg helper(Ret(C::*)(Arg,Args...));
	template<typename C,typename Ret,typename Arg,typename... Args>
	static Arg helper(Ret(C::*)(Arg,Args...)const);
	using first_argument_type=decltype(helper(&Functor::operator()));
};

template<typename Compare,typename T=typename functor_traits<Compare>::first_argument_type>
priority_queue<T,vector<T>,Compare> make_priority_queue(Compare comp){
	return priority_queue<T,vector<T>,Compare>(move(comp));
}
