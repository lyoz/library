template<typename T,typename Compare>
auto make_priority_queue(const Compare& comp)
{
	return priority_queue<T,vector<T>,Compare>(comp);
}
