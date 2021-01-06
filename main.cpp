#include "shape.h"

int main() {
	Color col(1, 2, 3),col2(col),col3;//颜色类的有参构造，复制构造，默认构造
	Shape s(col), s2(s),s3;//形状类的
	Point p1(2, 3), p2(3, 4), p3(p1), p4;//点类的
	Circle c1(p1, 3), c2(c1), c3;//圆类的

	col3 = col2;//颜色类的等于号运算符赋值
	s3 = s2;//形状类的
	p4 = p2;//点类的
	c3 = c1;//圆类的

	cout << col << endl;//重载输出试试
	return 0;
}