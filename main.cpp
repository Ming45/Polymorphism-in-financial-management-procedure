#include "shape.h"

int main() {
	Color col(1, 2, 3),col2(col),col3;//��ɫ����вι��죬���ƹ��죬Ĭ�Ϲ���
	Shape s(col), s2(s),s3;//��״���
	Point p1(2, 3), p2(3, 4), p3(p1), p4;//�����
	Circle c1(p1, 3), c2(c1), c3;//Բ���

	col3 = col2;//��ɫ��ĵ��ں��������ֵ
	s3 = s2;//��״���
	p4 = p2;//�����
	c3 = c1;//Բ���

	cout << col << endl;//�����������
	return 0;
}