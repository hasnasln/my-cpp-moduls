#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>


class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span operator=(const Span& other);

		void addNumber(int value);
		int shortestSpan();
		int longestSpan();

		class AlredyHaveNvalue :public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Alredy have N value";
				}
		};

		class DontHaveValue :public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Dont have value";
				}
		};

		class HaveOneValue :public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Have one value";
				}
		};
	private:
		unsigned int _N;
		unsigned int _datalen;
		std::vector<int> data;
};



#endif // SPAN_HPP
