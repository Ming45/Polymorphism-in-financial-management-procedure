#pragma once
#include<iostream>
using namespace std;

class Color {//������ԭɫ����ɫ�ࣨ��Ϊ��״�����Ԫ��
	double m_rad=0;
	double m_green=0;
	double m_bule=0;
public:
	Color() { cout << "default constructor color" << endl; }//Ĭ�Ϲ��캯��
	Color(double x, double y,double c) :m_rad(x), m_green(y), m_bule(c){//�вι��캯��
		cout << "parameter constructor color" << endl;
	}
	Color(const Color& p) :m_rad(p.m_rad), m_green(p.m_green), m_bule(p.m_bule) {//���ƹ��캯��
		cout << "copy constructor color" << endl;
	}
	~Color() { cout << "destruct color" << endl; }//��������
	Color& operator=(const Color& p) {//���ں����������
		if (this != &p) {
			m_rad=p.m_rad;
			m_green=p.m_green;
			m_bule = p.m_bule;
		}
		cout << "color endow" << endl;
		return *this;
	}
	 friend ostream& operator<<(ostream &os,const Color &a) {//����������Ҳ���������أ����ԣ�
		os <<"m_rad:"<< a.m_rad << "\nm_green:" << a.m_green << "\nm_bule:" << a.m_bule << endl;
		return os;
	 }
};

class Shape {//��״�ࣨ��Ϊ���࣬��ԪΪ��ɫ�ࣩ
	friend class Color;
protected://�ܱ��������ݳ�ԱΪ  ��ɫ�����ɫ   (protected��public��private�Ļ����)����Ϊprivate���������������н��޷�����m_color  ������ͨ�����в��ܷ����ܱ����� ��
	Color m_color;
public:
	Shape() { cout << "default constructor shape" << endl; }//Ĭ�Ϲ��캯��
	Shape(Color x) :m_color(x){//�вι��캯��
		cout << "parameter constructor shape" << endl;
	}
	Shape(const Shape& p) :m_color(p.m_color) {//���ƹ��캯��
		cout << "copy constructor shape" << endl;
	}
	~Shape() { cout << "destruct shape" << endl; }//��������


	Shape& operator=(const Shape& p) {//���ں����������
		if (this != &p) {
			m_color=p.m_color;
		}
		cout << "shape endow" << endl;
		return *this;
	}
};

class Point :public Shape {//���ࣨ�̳���״�ࣩ
protected:
	double m_x = 0;//xy����
	double m_y = 0;
public:
	Point() { cout << "default constructor point" << endl; }//Ĭ�Ϲ��캯��
	Point(double x, double y) :m_x(x), m_y(y) {//�вι��캯��
		cout << "parameter constructor point" << endl;
	}
	Point(const Point& p) :m_x(p.m_x), m_y(p.m_y) {//���ƹ��캯��
		cout << "copy constructor point" << endl;
	}
	~Point() { cout << "destruct point" << endl; }//��������
	Point& operator=(const Point& p) {//���ں����������
		if (this != &p) {
			m_x = p.m_x;
			m_y = p.m_y;
		}
		cout << "point endow" << endl;
		return *this;
	}


          //���޸�Ϊprivate������
	/*
	Point test(const Point& p) {
		p.m_color;
	}
	*/


};

class Circle :public Point {//Բ�ࣨ�̳е��ࣩ
protected:
	Point p;//�����͵�Բ��
	double m_radius = 0;//�뾶
public:
	Circle() { cout << "default constructor circle" << endl; }//Ĭ�Ϲ��캯��
	Circle(const Point& p, double r) :Point(p), m_radius(r) {//�вι��캯��(�����õ���point���͵�p����ʼ��point����������)
		cout << "parameter construct circle" << endl;
	}
	Circle(const Circle& c) :Point(c), m_radius(c.m_radius) {//���ƹ��캯��
		cout << "copy constructor circle" << endl;
	}
	~Circle() { cout << "destruct cirlce" << endl; }//��������
	Circle& operator=(const Circle& c) {//���ں����������
		if (this != &c) {
			p = c.p;
			m_radius = c.m_radius;
		}
		cout << "circle endow" << endl;
		return *this;
	}
};
