#include"money.h"

int main() {
	Person Wang(100000);                   // ��ʼ����ʮ��Ԫ

	Wang.addInvest(Saving(50000));   // �������ֱ�Ͷ����������

	Wang.addInvest(Fund(20000));

	cout <<"��׽��㣺"<< Wang.settle() << endl;   // ���ȫ������ת�뱾��
}