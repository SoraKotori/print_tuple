#include <tuple>
#include <iostream>
#include <array>
#include <utility>
#include <tuple>

template<class Ch, class Tr, class Tuple, std::size_t... Index>
decltype(auto) print_tuple_impl(std::basic_ostream<Ch, Tr>& os, const Tuple& tuple, std::index_sequence<Index...>)
{
	return ((os << (Index == 0 ? "(" : ", ") << std::get<Index>(tuple)), ...) << ")";
}

template<class Ch, class Tr, class... Args>
decltype(auto) operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& tuple)
{
	return print_tuple_impl(os, tuple, std::index_sequence_for<Args...>{});
}

int main()
{
	auto tuple = std::make_tuple(1, 2, 3, 4);

	std::cout << tuple << std::endl;
}