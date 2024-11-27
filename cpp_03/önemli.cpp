#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    
    ~Base() { // Sanal değil
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* dynamicArray;
public:
    Derived() {
        dynamicArray = new int[10]; // Dinamik bellek tahsisi
        cout << "Derived constructor" << endl;
    }

    ~Derived() {
        delete[] dynamicArray; // Dinamik bellek serbest bırakılır
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* b = new Derived(); // Temel sınıf işaretçisiyle türetilmiş sınıf nesnesi
    delete b; // Hatalı yıkım işlemi
    
    // Çıkış sırası:
    // Base constructor
    // Derived constructor
    // Base destructor
    // Derived destructor ÇAĞRILMAZ! -> Bellek sızıntısı oluşur.

    return 0;
}

/*
Ne Olur?
Bellek Tahsisi:
Derived sınıfında dynamicArray için dinamik bellek (new int[10]) ayrılır.
Silme İşlemi:
delete b; ifadesi çağrıldığında, Base sınıfının yıkıcısı çalışır.
Ancak, Base sınıfının yıkıcısı sanal olmadığı için, Derived sınıfının yıkıcısı çağrılmaz.
Sonuç:
Derived sınıfının yıkıcısı çalışmadığından, dynamicArray serbest bırakılmaz ve bellek sızıntısı oluşur.
*/

/*
2. Yıkıcı (Destructor) Fonksiyonların Çalışma Şekli
Genel Kurallar:
Türetilmiş sınıfın yıkıcısı temel sınıfın yıkıcısından önce çağrılır.

Nesne yıkılırken, yıkıcı çağrılma sırası yapıcının tersidir:
İlk olarak türetilmiş sınıfın yıkıcısı çalışır.
Daha sonra temel sınıfın yıkıcısı çalışır.
Yıkıcı çağrılma sırası:

Türetilmiş sınıf → Temel sınıf.
Sanal (virtual) yıkıcı:

Eğer bir temel sınıf işaretçisi ile türetilmiş sınıfın nesnesi yıkılıyorsa, yıkıcının sanal (virtual) olması gerekir.
Aksi takdirde, sadece temel sınıfın yıkıcısı çağrılır ve türetilmiş sınıfın yıkıcısı çalışmaz (bu, bellek sızıntısına neden olabilir).
*/