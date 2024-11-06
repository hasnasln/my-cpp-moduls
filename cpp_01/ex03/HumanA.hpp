#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

/*
sınıf üyesi olarak tanımlanana referaslar sınıfın yapıcı fonksiyonunda başlatılmalıdır.
aksi takride derleyici hata verir.
Bu yüzden constructor da başlatma listesi kullanılarak referanslar başlatılmalıdır.
Diğer türlü nesne oluşmuş sonra değer ataması yapılmış oluyor.
*/
class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack(void);
		
	private:
		std::string	_name;
		Weapon&		_Weapon;
};
#endif