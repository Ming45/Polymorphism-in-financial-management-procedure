#pragma once
#include<iostream>
using namespace std;

class Color {//包含三原色的颜色类（作为形状类的友元）
	double m_rad=0;
	double m_green=0;
	double m_bule=0;
public:
	Color() { cout << "default constructor color" << endl; }//默认构造函数
	Color(double x, double y,double c) :m_rad(x), m_green(y), m_bule(c){//有参构造函数
		cout << "parameter constructor color" << endl;
	}
	Color(const Color& p) :m_rad(p.m_rad), m_green(p.m_green), m_bule(p.m_bule) {//复制构造函数
		cout << "copy constructor color" << endl;
	}
	~Color() { cout << "destruct color" << endl; }//析构函数
	Color& operator=(const Color& p) {//等于号运算符重载
		if (this != &p) {
			m_rad=p.m_rad;
			m_green=p.m_green;
			m_bule = p.m_bule;
		}
		cout << "color endow" << endl;
		return *this;
	}
	 friend ostream& operator<<(ostream &os,const Color &a) {//对输出运算符也进行了重载（试试）
		os <<"m_rad:"<< a.m_rad << "\nm_green:" << a.m_green << "\nm_bule:" << a.m_bule << endl;
		return os;
	 }
};

class Shape {//形状类（作为基类，友元为颜色类）
	friend class Color;
protected://受保护的数据成员为  颜色类的颜色   (protected是public和private的混合物)若设为private，则在其派生类中将无法访问m_color  （在普通函数中不能访问受保护的 ）
	Color m_color;
public:
	Shape() { cout << "default constructor shape" << endl; }//默认构造函数
	Shape(Color x) :m_color(x){//有参构造函数
		cout << "parameter constructor shape" << endl;
	}
	Shape(const Shape& p) :m_color(p.m_color) {//复制构造函数
		cout << "copy constructor shape" << endl;
	}
	~Shape() { cout << "destruct shape" << endl; }//析构函数


	Shape& operator=(const Shape& p) {//等于号运算符重载
		if (this != &p) {
			m_color=p.m_color;
		}
		cout << "shape endow" << endl;
		return *this;
	}
};

class Point :public Shape {//点类（继承形状类）
protected:
	double m_x = 0;//xy坐标
	double m_y = 0;
public:
	Point() { cout << "default constructor point" << endl; }//默认构造函数
	Point(double x, double y) :m_x(x), m_y(y) {//有参构造函数
		cout << "parameter constructor point" << endl;
	}
	Point(const Point& p) :m_x(p.m_x), m_y(p.m_y) {//复制构造函数
		cout << "copy constructor point" << endl;
	}
	~Point() { cout << "destruct point" << endl; }//析构函数
	Point& operator=(const Point& p) {//等于号运算符重载
		if (this != &p) {
			m_x = p.m_x;
			m_y = p.m_y;
		}
		cout << "point endow" << endl;
		return *this;
	}


          //对修改为private，测试
	/*
	Point test(const Point& p) {
		p.m_color;
	}
	*/


};

class Circle :public Point {//圆类（继承点类）
protected:
	Point p;//点类型的圆心
	double m_radius = 0;//半径
public:
	Circle() { cout << "default constructor circle" << endl; }//默认构造函数
	Circle(const Point& p, double r) :Point(p), m_radius(r) {//有参构造函数(里面用的是point类型的p来初始化point，拷贝基类)
		cout << "parameter construct circle" << endl;
	}
	Circle(const Circle& c) :Point(c), m_radius(c.m_radius) {//复制构造函数
		cout << "copy constructor circle" << endl;
	}
	~Circle() { cout << "destruct cirlce" << endl; }//析构函数
	Circle& operator=(const Circle& c) {//等于号运算符重载
		if (this != &c) {
			p = c.p;
			m_radius = c.m_radius;
		}
		cout << "circle endow" << endl;
		return *this;
	}
};
