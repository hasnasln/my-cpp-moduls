#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

template <typename T>
std::vector<T> get_Jacobsthal(size_t n)
{
	std::vector<T> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (size_t i = 2; i < n; i++)
		jacobsthal.push_back(jacobsthal[i - 1] + (2 * (jacobsthal[i - 2])));
	return jacobsthal;
}

template <typename Container>
Container split_container(const Container& cont, size_t len) {
	typename Container::const_iterator it = cont.begin();
	std::advance(it, len);
	return Container(cont.begin(), it);
}

template <typename Container>
std::vector<Container> split_vector(const Container& vec) {
	std::vector<Container> result;
	
	if (vec.empty()) {
		result.push_back(Container());
		result.push_back(Container());
		return result;
	}

	size_t len = vec.size() / 2;
	
	Container first_half = split_container(vec, len);
	Container second_half;
	typename Container::const_iterator it = vec.begin();
	std::advance(it, len);
	second_half.assign(it, vec.end());
	
	result.push_back(first_half);
	result.push_back(second_half);
	
	return result;
}


template <typename Container>
void mergeSort(Container &arr)
{
	if (arr.size() == 1)
		return;
	if (arr.size() == 2)
	{
		typename Container::iterator first = arr.begin();
		typename Container::iterator second = arr.end();
		second --;
		if (*first > *second)
			std::iter_swap(first, second);
		return;
	}
	std::vector<Container> containers = split_vector(arr);
	mergeSort(containers[0]);
	mergeSort(containers[1]);
	Container result(containers[0].begin(), containers[0].end());
	for (typename Container::iterator it = containers[1].begin(); it != containers[1].end(); ++it)
	{
		typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), *it);
		result.insert(pos, *it);
	}
	arr = result;
}

template <typename Container>
void ford_johnson(Container &arr)
{
	Container large;
	Container smals;
	typename Container::iterator it = arr.begin();
	while(it != arr.end())
	{
		typename Container::value_type a = *it;
		it++;
		if (it == arr.end())
		{
			large.push_back(a);
			break;
		}
		typename Container::value_type  b = *it;
		if (a > b)
		{
			large.push_back(a);
			smals.push_back(b);
		}else
		{
			large.push_back(b);
			smals.push_back(a);
		}
		it++;
	}
	mergeSort(large);
	std::vector<size_t> jacobsthal_number = get_Jacobsthal<size_t>(15);
	for (size_t i = 2; i < jacobsthal_number.size() && jacobsthal_number[i] < smals.size(); i++)
	{
		typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), smals[jacobsthal_number[i]]);
		large.insert(pos, smals[jacobsthal_number[i]]);

		typename Container::iterator erase_it = smals.begin();
		std::advance(erase_it, jacobsthal_number[i]);
		smals.erase(erase_it);
	}
	for (typename Container::iterator it = smals.begin(); it != smals.end(); ++it) {
		typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), *it);
		large.insert(pos, *it);
	}
	arr = large;
}

template <typename C>
double PmergeMe(C& container) {
	clock_t start;//ı Başlangıç zamanı
	clock_t end; // Bitiş zaman
	start = clock();
	ford_johnson(container); // Algoritmayı çalıştır
	end = clock();
	return (1000.0 * (end - start) / CLOCKS_PER_SEC);
}
#endif //PMERGEME_HPP