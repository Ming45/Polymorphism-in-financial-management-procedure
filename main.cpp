#include"money.h"

int main() {
	Person Wang(100000);                   // 初始本金十万元

	Wang.addInvest(Saving(50000));   // 储蓄、基金分别投资五万、两万

	Wang.addInvest(Fund(20000));

	cout <<"年底结算："<< Wang.settle() << endl;   // 年底全部结算转入本金
}