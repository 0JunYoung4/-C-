#include <iostream>
#include <string>

using namespace std;
class STRING {
	size_t num;
	char* p;

public:
	STRING() = default;		// ����Ʈ �����ڴ� �ʼ�
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "������(const char*) - " << num << ", �޸�: " << (void*)p << '\n';
	}

	STRING(const STRING& other) : num{ other.num } {
		p = new char[num];
		memcpy(p, other.p, num);

		cout << "���� ������ - " << num << ", �޸�: " << (void*)p << '\n';
	}

	~STRING() {

		cout << "�Ҹ��� - " << num << ", �޸�: " << (void*)p << "\n";
		delete[] p;
	}

	// ���� �����ڶ� copy assignment operator�� ��Ʈ��.
	STRING& operator=(const STRING& other) {
		// �ڱ� �ڽ��� �Ҵ����� �ʵ��� �ϱ� ���� ���� Ȯ������ߵ�
		if (this == &other)
			return*this;
		delete[] p;
		num = other.num;
		p = new char[num];
		memcpy(p, other.p, num);

		cout << "copy assignment operator - " << num << ", �޸�: " << (void*)p << '\n';

	}

	// �̵��� �̵��Ҵ�
	STRING(STRING&& other) : num{ other.num }, p{ other.p } {		//&& - rvalue�� ���� ������ �����͸� �����ؾ� �Ǳ⿡
		// move�� �Ͽ����� ������ ������ �ٸ� ��ü�� �Ѱ��ְ� ���� ��ü�� �� ������ ���� �������� ������
		other.num = 0;
		other.p = nullptr;
	}

	// ������ �����ε�
	// (lhs)��ü + (rhs)const char*
	STRING operator+(const char* str) {
		STRING temp;

		temp.num = num + strlen(str);
		temp.p = new char[temp.num];

		memcpy(temp.p, p, num);
		memcpy(temp.p + num, str, strlen(str));
		return temp;
	}
	//(lhs)��ü + (rhs)��ü
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
		return os;		// os�� p�� ���� ���� �Ŀ� �����ؼ� ���
	}

};

void a() { cout << "�ȳ� �� a��"; }
void b() { cout << "�ȳ� �� b��"; }

int main()
{
	STRING s{ "C++ Programming Lnguage" };

	//// [����] s�� �����ִ� ������ ������������ �����϶�	
	//qsort(&s[0], s.size(), sizeof(char), [](const void* a, const void* b) {	// s�� ����Ű�� ������ ��ġ�� �˷���ߵ�
	//	return *(char*)a - *(char*)b;		// ������ ���ϴϱ� char*�� ��ȯ����ߵ�
	//	});
	//cout << s << '\n';

	void (*sw)() = a;

	sw();
}