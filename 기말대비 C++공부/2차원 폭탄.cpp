//----------------------------------------------------------------
// 2���� ���� �����ϰ� ��ź�� �Ͷ߸���
//----------------------------------------------------------------
#include <iostream>
#include <random>
#include <math.h>

using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ -100,100};

//[����] 2���� �� 100���� �����϶�.
//��ǥ���� [-100, 100] ���������� ����
//�������� ��ź�� ������. (�ݰ� 20���� ����޴´�.)
//��ź�� ������ �޴� ���� ����϶�.

class Point2D {
public:
	int x;
	int y;

	void Show() {
		cout << "( " << x << ", " << y << " )" << '\n';
	}
};

int main()
{

	Point2D points[100];

	for (Point2D& p : points) {			//Point2D�� �ִ� x,y�� �ٲ��ֱ����� ������ �ؾߵ�
		p.x = uid(dre);
		p.y = uid(dre);
	}

	for (Point2D p : points) {
		if (sqrt(p.x * p.x + p.y * p.y) <= 20)
			p.Show();
	}



}