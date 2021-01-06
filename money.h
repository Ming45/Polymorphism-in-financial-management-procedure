#pragma once
#include<iostream>
#include<vector>
#include <stdio.h>//����rand
#include<time.h>//�����������������
using namespace std;

class Person;//�����಻�ܻ�ȡ
class Investment {//Ͷ�ʣ����ࣩ
	friend class Person;//��������˻�ȡͶ�ʵĽ����߱��̳�
protected:
	double m_capital=0;//Ͷ�ʽ��
public:
	Investment() = default;//Ĭ�Ϲ��캯��
	Investment(double x) :m_capital(x) {}//�вι��캯��
	Investment(const Investment& p) :m_capital(p.m_capital) {}//���ƹ��캯��
	~Investment()=default;//Ĭ����������

	virtual double settle() const = 0;//�麯�������洢��ͻ��������¶���

};

class Saving :public Investment {//�����ࣨͶ�ʵ������ࣩ
public:
	Saving() = default;//Ĭ�Ϲ��캯��
	Saving(double x){//�вι��캯������Ͷ�ʻ����е�Ͷ�ʽ���ʼ����
		m_capital = x ;
	}
	Saving(const Saving& p):Investment(p){//���ƹ��캯������Ͷ�ʻ����е�Ͷ�ʽ���ʼ����,����������ڸ���ʱ��Ҫ���û����
		m_capital = p.m_capital;
	}
	~Saving() = default;//Ĭ����������

	double settle() const{//����������ٶ���
		return m_capital * (1 + 1.78 / 100);
	}
};

class Fund :public Investment {//�����ࣨͶ�ʵ������ࣩ
public:
	Fund() = default;//Ĭ�Ϲ��캯��
	Fund(double x) {//�вι��캯������Ͷ�ʻ����е�Ͷ�ʽ���ʼ����
		m_capital = x ;
	}
	Fund(const Fund& p) :Investment(p) {//���ƹ��캯������Ͷ�ʻ����е�Ͷ�ʽ���ʼ����
		m_capital = p.m_capital;
	}
	~Fund() = default;//Ĭ����������

	double settle() const {//����������ٶ���
		srand(time(NULL));//���������������
		return m_capital * (rand() % 20 + 90) / 100;//90��109������������զ�о�ÿ�ζ��ǿ�Ǯ��
	}
};

class Person {//�������
	double m_principal;//����
	vector<const Investment*> theinvest;//���ָ��Ͷ�ʵ�ָ���vector����,   ���������ĵ�ַ���Ը���ָ���������ָ�����
public:
	Person() = default;//Ĭ�Ϲ��캯��
	Person(double x) {//�вι��캯��
		m_principal = x;//��ʼ������
	}
	Person(const Person& p){//���ƹ��캯������P�ĳ�ʼ�����𣬲���ʼ��Ͷ�ʵ�����
		m_principal = p.m_principal;
		theinvest=p.theinvest;
	}
	~Person() = default;//Ĭ����������

	void addInvest(const Investment& p) {//���,����Ͷ�ʵĺ���
		m_principal -= p.m_capital;//��ȥͶ�ʵ�Ǯ
		theinvest.push_back(&p);//��p�ĵ�ַ�⿪��vector�����ڵĻ���ָ��
	}

	double settle() {
		for (;theinvest.size();) {//��Ͷ���������Ͷ��ȫ�ó�������
			m_principal += theinvest[theinvest.size() - 1]->settle();//���ݸ����͵�����Ӧ���͵Ľ��㺯��,��������õ�һ��Ͷ�ʷŻر���
			theinvest.pop_back();//���ô�Ͷ��ɾȥ
		}
		return m_principal;
	}
};