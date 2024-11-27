#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const std::string &idea);
		Brain(const Brain &other);
		Brain operator=(const Brain &other);

		void setIdeas(const std::string &idea);
		void setIdeas(unsigned int index, const std::string &idea);
		std::string getIdea(unsigned int &index) const;
	private:
		std::string ideas[100];
};


#endif

