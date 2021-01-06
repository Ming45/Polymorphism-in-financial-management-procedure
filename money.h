#pragma once
#include<iostream>
#include<vector>
#include <stdio.h>//用于rand
#include<time.h>//用于设置随机数种子
using namespace std;

class Person;//派生类不能获取
class Investment {//投资（基类）
	friend class Person;//方便理财人获取投资的金额，不具备继承
protected:
	double m_capital=0;//投资金额
public:
	Investment() = default;//默认构造函数
	Investment(double x) :m_capital(x) {}//有参构造函数
	Investment(const Investment& p) :m_capital(p.m_capital) {}//复制构造函数
	~Investment()=default;//默认析构函数

	virtual double settle() const = 0;//虚函数，后面储蓄和基金再重新定义

};

class Saving :public Investment {//储蓄类（投资的派生类）
public:
	Saving() = default;//默认构造函数
	Saving(double x){//有参构造函数（将投资基类中的投资金额初始化）
		m_capital = x ;
	}
	Saving(const Saving& p):Investment(p){//复制构造函数（将投资基类中的投资金额初始化）,派生类对象在复制时还要调用基类的
		m_capital = p.m_capital;
	}
	~Saving() = default;//默认析构函数

	double settle() const{//储蓄类结算再定义
		return m_capital * (1 + 1.78 / 100);
	}
};

class Fund :public Investment {//基金类（投资的派生类）
public:
	Fund() = default;//默认构造函数
	Fund(double x) {//有参构造函数（将投资基类中的投资金额初始化）
		m_capital = x ;
	}
	Fund(const Fund& p) :Investment(p) {//复制构造函数（将投资基类中的投资金额初始化）
		m_capital = p.m_capital;
	}
	~Fund() = default;//默认析构函数

	double settle() const {//基金类结算再定义
		srand(time(NULL));//先设置随机数种子
		return m_capital * (rand() % 20 + 90) / 100;//90到109的任意整数（咋感觉每次都是亏钱）
	}
};

class Person {//理财人类
	double m_principal;//本金
	vector<const Investment*> theinvest;//存放指向投资的指针的vector容器,   派生类对象的地址可以赋给指向基类对象的指针变量
public:
	Person() = default;//默认构造函数
	Person(double x) {//有参构造函数
		m_principal = x;//初始化本金
	}
	Person(const Person& p){//复制构造函数，用P的初始化本金，并初始化投资的容器
		m_principal = p.m_principal;
		theinvest=p.theinvest;
	}
	~Person() = default;//默认析构函数

	void addInvest(const Investment& p) {//添加,保存投资的函数
		m_principal -= p.m_capital;//减去投资的钱
		theinvest.push_back(&p);//将p的地址解开给vector容器内的基类指针
	}

	double settle() {
		for (;theinvest.size();) {//将投资容器里的投资全拿出来结算
			m_principal += theinvest[theinvest.size() - 1]->settle();//根据该类型调用相应类型的结算函数,并将结算好的一次投资放回本金
			theinvest.pop_back();//将该次投资删去
		}
		return m_principal;
	}
};