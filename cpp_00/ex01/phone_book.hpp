
#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void add_someone(int);
		void search_someone(int);
		
	private:
		Contact data[8];
		int registred;
};