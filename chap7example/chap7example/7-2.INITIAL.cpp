//7-2.INITIAL.CPP

#include <iostream>
using namespace std;

class A{
public:
    int data;
    A(){
        cout<<"Constructor of class A"<<endl;
        data = 0;
    }
    ~A(){
        //cout<<"Destructor of class A"<<endl;
    }
};

class B : public A{//virtual �߰��غ���
public:
    B(){
        cout<<"Constructor of class B, derived from A"<<endl;
        data = 100;
    }
    ~B(){
        //cout<<"Destructor of class B"<<endl;
    }
};

class C : public A{//virtual �߰��غ���
public:
    C(){
        cout<<"Constructor of class C, derived from A"<<endl;
        data = 200;
    }
    ~C(){
        //cout<<"Destructor of class C"<<endl;
    }
};

class D : public B, public C{
public:
    D(){
        cout<<"Constructor of class D, derived from B and C"<<endl;
    }
    ~D(){
        //cout<<"Destructor of class D"<<endl;
    }
};

void main()
{
    // �ּ�1
	/*
    cout<<"Defining an object of class A"<<endl;
    A aa;
    cout<<endl;
    */
    // �ּ� 2
	/*
    cout<<"Defining an object of class B"<<endl;
    B bb;
    cout<<endl;
    */
    // �ּ� 3
	/*
    cout<<"Defining an object of class C"<<endl;
    C cc;
    cout<<endl;
    */
    // �ּ� 4
	/*
    cout<<"Defining an object of class D"<<endl;
    D dd;
    //class B,class C�� virtual�� ������ ����, ������ ��� class�� 
    //data���� ��ȣ�ϱ� ������ error�� �߻��Ѵ�.
    cout << dd.data; 
    //B�� C�� A�� virtual�� ��ӹް� D�� �ݺ�����ϸ� ��� ���� �� ����     //����� class�� �����͸� ���ٰ����ϴ�.
    cout << dd.B::data; 
    cout << dd.C::data;
    cout << endl;
    */
    system("pause");
}