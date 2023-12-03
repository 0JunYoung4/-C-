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
		cout << "소멸직전 - " << size << ", [0] - " << p[0] << '\n';
		delete[] p;
	}
	void show() const {			// const를 붙임으로서 읽기만 하겠다고 보장함. 이때 값을 바꾸는 시도를 하면 오류
		cout << "내가 관리하는 int의 수 - " << size << ", [0] - " << p[0] << '\n';
	}

};

int main() {
	MemoryMonster a[3]{ 1,4,5 };

	cout << "\n\n\n";

	for (const MemoryMonster& mon : a)			// const를 사용한다는건 읽기만 한다는 것이기에 함수 내에서 읽기만 한다는
												// 보장을 해줘야 한다.
		mon.show();				
	cout << "\n\n\n";
}