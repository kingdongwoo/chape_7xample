//7-1.INHERITANCE_METHOD.cpp

#include <iostream>
using namespace std;
class A{
private:
    int a_private;
protected:
    int a_protected;
public:
    int a_public;
    void SetData(){ //값을 바꾸기 위한 SetData함수
        a_private = 1;
        a_protected = 2;
        a_public = 3;
    }
    void ModifyData(int a, int b, int c){
        a_private = a;
        a_protected = b;
        a_public = c;
    }
};
//class A를 public 상속받은 class B
class B : public A{
public:
    void SetData(){
    //마찬가지로 값을 변경하기 위한 함수인 SetData()
    //protected와 public은 변경이 무리없지만
    //private변수는 변경할 수 없다.
    //a_private = 11;
    a_protected = 22;
    a_public = 33;
    }
};
//protected 상속받은 class C
class C : protected A{
public:
    void SetData(){
        //B와 마찬가지로 private만 수정할 수 없다.
        //a_private = 11;
        a_protected = 22;
        a_public = 33;
    }
};
//private 상속받은 class D
class D : private A{
public:
    void SetData(){
        //마찬가지로 private만 수정할 수 없다.
        //a_private = 11;
        a_protected = 22;
        a_public = 33;
    }
    void callModifyData(){
        A::ModifyData(11, 22, 33);
    }
};
//어떤 상속을 받은 class이건, private member 변수는 절대 건드릴 수 없으며, 
//public, protected는 아무런 상관이 없어 보인다.
void main(){
    A a;
    //a 객체는 안에 존재하는 member 변수들이지만
    //private와 protected member 변수는 class 외부에서 건드릴 수 없다.
    a.a_public = 2;
    cout <<"a_public = " <<a.a_public << endl;
    //a.a_private = 1; //안된다.
    //a.a_protected = 2;	//안된다.
    a.SetData();
    cout <<"a_public = " <<a.a_public << endl;
    
    /* //주석 1
    B b;
    //A에 public 상속을 받은 b객체는
    //역시 마찬가지로 a객체와 같은 반응을 보인다.
    b.a_public = 4;
    cout <<"a_public = " <<b.a_public << endl;
    b.SetData();
    cout <<"a_public = " <<b.a_public << endl;
    //b.a_private = 1; //안된다.
    //b.a_protected = 2;	//안된다. 
    */
    /* //주석 2
    C c;
    //A에 protected 상속을 받은 c객체,
    //class 외부에서는 class A의 public member 변수 조차 사용할 수 없어진 것을 알 수 있다.
    c.a_public = 5;
    cout <<"a_public = " <<c.a_public << endl;
    c.SetData();
    cout <<"a_public = " <<c.a_public << endl;
    //c.a_private = 1;	//안된다.
    //c.a_protected = 2;	//안된다.
    */
    /* //주석 3
    D d;
    //A에 private 상속을 받은 d객체,
    //마찬가지로 모든 member변수를 사용할 수 없다.
    d.a_public = 6;
    cout <<"a_public = " <<d.a_public << endl;
    d.SetData();
    cout <<"a_public = " <<d.a_public << endl;
    //d.a_private = 1;		//안된다.
    //d.a_protected = 2;	//안된다.
    d.callModifyData(); //class A의 public함수 ModifyData를 이용 변경
    */
	system("pause");
}