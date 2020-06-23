#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template<typename T>
std::enable_if_t<std::is_integral<T>::value, void>
print(T ip)
{
	std::vector<size_t> buff;
	size_t size = sizeof(T);
	buff.reserve(size);
	for (size_t i = 0; i < size; ++i)
	{
		buff.push_back(ip & 0xFF);
		ip >>= 8;
	}

	std::cout << *buff.rbegin();
	for (auto it = std::next(buff.rbegin()); it != buff.rend(); ++it)
		std::cout << "." << *it;
}

template<typename T>
std::enable_if_t<std::is_same<typename std::string, T>::value, void>
print(T ip)
{
	std::cout << ip;
}


template<typename T>
std::enable_if_t<
	std::is_same<typename std::vector<typename T::value_type>, T>::value ||
	std::is_same<typename std::list<typename T::value_type>, T>::value,
	void>
	print(T ip)
{
	if (ip.empty())
		return;

	std::cout << ip.front();
	for (auto it = std::next(ip.begin()); it != ip.end(); ++it)
		std::cout << "." << *it;
}

// ----------------------------------------------------------------------------------------------
// tuple without verification

template<typename Tuple, std::size_t N>
struct PrintTuple {
	static void print(const Tuple& t)
	{
		PrintTuple<Tuple, N - 1>::print(t);
		std::cout << "." << std::get<N - 1>(t);
	}
};

template<typename Tuple>
struct PrintTuple<Tuple, 1> {
	static void print(const Tuple& t)
	{
		std::cout << std::get<0>(t);
	}
};

template<typename T0, typename ...Args>
void print(const std::tuple<T0, Args...>& ip)
{
	PrintTuple<decltype(ip), sizeof...(Args) + 1>::print(ip);
}
// ----------------------------------------------------------------------------------------------

template<typename T>
void print_ip(T ip)
{
	print(ip);
	std::cout << std::endl;
}
