template<typename Map, typename Target>
typename Map::const_reverse_iterator	lowerBound(const Map& c, const Target& t)
{
	typedef typename Map::const_reverse_iterator Iter;
	Iter iter = c.rbegin();
	for (; iter!=c.rend(); ++iter) {
		if (iter->first <= t)
			break ;
	}
	return (iter);
}
