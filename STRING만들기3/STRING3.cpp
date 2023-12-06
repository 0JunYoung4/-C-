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
	STRING t = s;

	s.show();
	t.show();

	// �� �ڵ� �츮�°� �߿���. �� �װ� ��� ����� �Ǵ��� �����غ���

}
// ��������ڰ� ���ٸ� ���� ���簡 �̷����
// t��� ��ü�� s��� ��ü���� �����ϰ� �����ν� t�� s�� ����� freestore�� �޸� �ּҸ� ����Ų��.
// t�� �Ҹ�ɶ� �ش� �޸𸮵� ������Ƿ� ������ �߻��ϰ� �ȴ�.	(��۸�������)
// �̸� �ذ��ϱ� ���� ���ο� �޸𸮸� �޾Ƽ� �ű⿡ s�� ���� �������ִ� ���� ���簡 �ʿ��ϴ�.