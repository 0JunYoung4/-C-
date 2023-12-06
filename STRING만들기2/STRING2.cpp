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
		
		cout << "������(const char*) - " << num << ", �޸�: " << (void*)p << '\n';		// void*�� ����� �� ��� �޸𸮰� ����
	}
	~STRING() {
		cout << "�Ҹ��� - " << num << ", �޸�: " << (void*)p << "\n";
		delete[] p;		// new�� ����� ������ �� ����� ��ߵ�
	}
	size_t size() {
		return num;
	}
	void show() {
		for (int i = 0; i < num; ++i)
			cout << p[i];
		cout << '\n';
	}
};

int main()
{
	STRING s[]{ "����ũ��", "��", "����", "��߳�" , "��Ʈ�ν�Ʈ��", "C���", "�������� �������" };

	// [����] s�� ���� ������������ ������ �� ����϶�.
	qsort(s, sizeof(s) / sizeof(STRING), sizeof(STRING), [](const void* a, const void* b) {
		return (int)((STRING*)a)->size() - (int)((STRING*)b)->size();		// unsigned long long Ÿ���̿��� ������ �ȵȴ�.
		});

	//��� ���
	cout << "\n ���� �������� ���İ��" << '\n';
	for (STRING& str : s)
		str.show();

}