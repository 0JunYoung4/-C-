#include <iostream>
#include <string>

using namespace std;

// ���ڿ��� �޾� ���ڿ��� ���̸�ŭ �޸𸮸� �����Ҵ��Ͽ� ���������� ����.


class STRING {
	size_t num;
	char* p;
public:
	STRING(const char* str) : num{ strlen(str) } {
		p = new char[num];
		memcpy(p, str, num);

		cout << "������(const char*) - " << num << ", �޸�: " << (void*)p << '\n';
	}

	size_t size() const {		// �б⸸ �ҰŴϱ� const �ٿ��ֱ�
		return num;
	}
	void show() const {		// �б⸸ �ҰŴϱ� const �ٿ��ֱ�
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}
};

int main()
{
	STRING s{ "���� STRING Ŭ������" };
	cout << "���ڿ��� ���� - " << s.size() << '\n';
	s.show();
}