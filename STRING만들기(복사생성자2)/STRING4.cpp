#include <iostream>
#include <string>

using namespace std;
class STRING {
	size_t num;
	char* p;

public:
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

	size_t size() const {
		return num;
	}

	void show() const {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}

};

int main()
{
	
	STRING s{ "��Ʈ��" };
	STRING t{ "2023. 11. 09" };

	s.show();
	t.show();

	t = s;		// ������� ����

	cout << "\n\n\ns�� ������ t" << "\n\n\n";
	t.show();
}

// ���� ��ġ��
// t�� s�� �޸𸮸� ����Ű�� �Ǹ鼭 ������ �޸𸮿��� ������ ��������µ� �� �޸𸮴� ������� �ʰ� 
// ������ ����. ���� t�� ������鼭 ��۸������Ͱ� �Ǿ� ������ �߻�