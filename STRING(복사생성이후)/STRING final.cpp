#include <iostream>
#include <string>

using namespace std;
class STRING {
	size_t num;
	char* p;

public:
	STRING() = default;		// 디폴트 생성자는 필수
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "생성자(const char*) - " << num << ", 메모리: " << (void*)p << '\n';
	}

	STRING(const STRING& other) : num{ other.num } {
		p = new char[num];
		memcpy(p, other.p, num);

		cout << "복사 생성자 - " << num << ", 메모리: " << (void*)p << '\n';
	}

	~STRING() {

		cout << "소멸자 - " << num << ", 메모리: " << (void*)p << "\n";
		delete[] p;
	}

	// 복사 생성자랑 copy assignment operator은 세트임.
	STRING& operator=(const STRING& other) {
		// 자기 자신을 할당하지 않도록 하기 위해 먼저 확인해줘야됨
		if (this == &other)
			return*this;
		delete[] p;
		num = other.num;
		p = new char[num];
		memcpy(p, other.p, num);

		cout << "copy assignment operator - " << num << ", 메모리: " << (void*)p << '\n';

	}

	// 이동과 이동할당
	STRING(STRING&& other) : num{ other.num }, p{ other.p } {		//&& - rvalue를 쓰는 이유는 포인터를 참조해야 되기에
		// move를 하였을때 기존의 정보를 다른 객체에 넘겨주고 기존 객체는 그 정보에 대한 소유권을 포기함
		other.num = 0;
		other.p = nullptr;
	}

	// 연산자 오버로딩
	// (lhs)객체 + (rhs)const char*
	STRING operator+(const char* str) {
		STRING temp;

		temp.num = num + strlen(str);
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, str, strlen(str));
		return temp;
	}
	//(lhs)객체 + (rhs)객체
	STRING operator+(STRING& other) {
		STRING temp;
		temp.num = num + other.num;
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, other.p, other.num);

		return temp;
	}
	// free function
	friend STRING operator+(const char* p, STRING& s) {
		STRING temp;
		temp.num = strlen(p) + s.num;
		temp.p = new char[temp.num];

		memcpy(temp.p, p, strlen(p));
		memcpy(temp.p + strlen(p), s.p, s.num);

		return temp;
	}

	char operator[](int idx) const {
		return p[idx];
	}

	char& operator[] (int idx){
		return p[idx];
	}

	size_t size() const {
		return num;
	}

	void show() const {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}

	friend ostream& operator<<(ostream& os, const STRING& s) {
		for (int i = 0; i < s.num; ++i)
			os << s.p[i];
		return os;		// os에 p의 값을 넣은 후에 리턴해서 출력
	}

};

void a() { cout << "안녕 난 a야"; }
void b() { cout << "안녕 난 b야"; }

int main()
{
	STRING s{ "C++ Programming Lnguage" };

	//// [문제] s가 갖고있는 문장을 오름차순으로 정렬하라	
	//qsort(&s[0], s.size(), sizeof(char), [](const void* a, const void* b) {	// s가 가리키는 포인터 위치를 알려줘야됨
	//	return *(char*)a - *(char*)b;		// 문장을 비교하니까 char*로 변환해줘야됨
	//	});
	//cout << s << '\n';

	void (*sw)() = a;

	sw();
}