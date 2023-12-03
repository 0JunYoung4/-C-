#include <iostream>
#include <random>
using namespace std;

default_random_engine dre;
uniform_int_distribution uid{ 1,999 };

class MemoryMonster {
	int size;
	int* p;
public:
	MemoryMonster(int n) : size{ n } {
		p = new int[n];
		for (int i = 0; i < n; ++i)
			p[i] = uid(dre);
		cout << "생성(int) - " << size << ", [0] - " << p[0] << '\n';
	}
	MemoryMonster(const MemoryMonster& other) : size(other.size) {
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = other.p[i];
		cout << "복사생성 - " << size << ", [0] - " << p[0] << '\n';
	}
	~MemoryMonster() {
		cout << "소멸직전 - " << size << ", [0] - " << p[0] <<'\n';
		delete[] p;
	}
	void show() {
		cout << "내가 관리하는 int의 수 - " << size << ", [0] - " << p[0] << '\n';
	}

};

int main() {
	MemoryMonster a[3]{ 1,4,5 };

	cout << "\n\n\n";
	
	for (MemoryMonster& mon : a)			// &를 안붙이면 각 객체를 복사를 하기에 소멸자가 2번 실행이 된다.
										// 하지만 &를 붙이면 만들어둔 객체를 참조하기에 복사하는 과정이 필요 없어진다.
		mon.show();
	cout << "\n\n\n";
}