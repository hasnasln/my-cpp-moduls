#include "Brain.hpp"

Brain::Brain(): ideas{}
{
	std::cout << "Brain deafult constructre called" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructre called" << std::endl;
}
Brain::Brain(const std::string &idea)
{
	this->setIdeas(idea);
	std::cout << "Brain constructre called" << std::endl;
}
Brain::Brain(const Brain &other)
{
	for (unsigned int i = 0; i < 100; i++)
		this->setIdeas(i, other.getIdea(i));
}
Brain Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (unsigned i = 0; i < 100; i++)
			this->setIdeas(i, other.getIdea(i));
	}
	return *this;
}
void Brain::setIdeas(unsigned int index, const std::string &idea)
{
	this->ideas[index] = idea;
}
void Brain::setIdeas(const std::string &idea)
{
	for (unsigned i = 0; i < 100; i++)
		this->setIdeas(i, idea);
}
std::string Brain::getIdea(unsigned int &index) const
{
	return this->ideas[index];
}