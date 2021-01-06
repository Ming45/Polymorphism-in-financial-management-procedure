# Polymorphism-in-financial-management-procedure
C++作业：理财管理系统中的多态

问题描述】

         设计一个简单的理财管理程序，其中包含 4 个类，分别为投资（Investment）、储蓄（Saving）、基金（Fund）和理财人（Person）。储蓄和基金为两种具体投资，都有确定的投资金额（m_capital），但它们年底结算（settle）的方式不同，具体如下：

m_capital = m_capital * (1 + 1.78 / 100);                  // 储蓄

m_capital = m_capital * (rand() % 20 + 90) / 100;   // 基金

       理财人对象初始化时确定本金 m_principal 。理财人通过其成员函数 addInvest 添加和保存每一笔投资，并从本金中减去投资额。一年后，理财人通过其成员函数 settle 结算所有投资，将投资额返回本金。实现效果如下：

Person Wang(100000);                   // 初始本金十万元

Wang.addInvest(Saving(50000));   // 储蓄、基金分别投资五万、两万

Wang.addInvest(Fund(20000));

cout << Wang.settle() << endl;   // 年底全部结算转入本金

【要求】

1. 分析和设计以上 4 个类的成员以及类之间的关系，给出他们的定义。

2. 根据不同投资类型，给出 settle 的不同实现。

3. 利用上述代码进行测试。

【提示】

1. 可将 Investment 类设置为 Fund 类和 Saving 类的公共基类。

2. 可以利用 vector 保存理财人所有投资，其元素为基类指针。 
