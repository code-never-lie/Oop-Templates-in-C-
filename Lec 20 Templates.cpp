Templates (Generics)
C++ templates are a powerful mechanism for code reuse, as they enable the programmer to write code that behaves the same for data of any type.

- C++ is a strongly typed  language

int add( int x, int  y) {
  int t= x+y;
  return t;
}

void main () {

int a=2,b=3;
cout<<add(a,b)<<endl;
double c=2.4, d=2.3;
cout<<add(c,d)<<endl; //dats loss  result=4
}
................................................
Remedy

1- Function Overloading
2- Templates
..........................................

1- Function Overloading
     same name funtion with different type and number of      parameters


int add( int x, int  y) {
  int t= x+y;
  return t;
}
double add( double x, double  y) {
  double t= x+y;
  return t;
}
void main () {

int a=2,b=3;
cout<<add(a,b)<<endl;
double c=2.4, d=2.3;
cout<<add(c,d)<<endl; 
}
...................................................
2- Templates
Compiler will decide T at compile Time
It will generate as many function as many Ts
- generate two add function at compile time
- one add for integer second add for double

template <class T>
T add(T  x,T   y) {
 T  t= x+y;
  return t;
}

void main () {

int a=2,b=3;
cout<<add(a,b)<<endl;
double c=2.4, d=2.3;
cout<<add(c,d)<<endl; 
//cout<<add(a,d)<<endl;error  Ambigious T
}
.....................................................
Template with classes
class Stack{
private:
int size;
int tos;
int *a;
public : 
  Stack(int s) {size=s; tos=-1;
                a= new int[size];}
  void push(int d) {a[++tos]=d;}
  int pop () { retur a[tos--];}
};

void main(){
int a=2,b=3;
Stack s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}

- We can't use above stack for double, chars and user defined classes
..............................................
template <class T>
class Stack{
private:
int size;
int tos;
T *a;
public : 
  Stack(int s) {size=s; tos=-1;
                a= new T[size];}
  void push(T d) {a[++tos]=d;}
  T pop () { return a[tos--];}
};

void main(){
int a=2,b=3;
Stack <int>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}
...................................................
Swap two chars
void main(){
char a='+',b='*';
Stack <char>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}
..................................................
SWAP two Doubles
void main(){
double a=2.5,b=3.5;
Stack <double>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}
..................................................
swap two Strings (using c++ strings)

void main(){
string a="RabNawaz",b="OsamaBin";
Stack <string>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}
........................................

swap two Strings (using c style strings)


void main(){
char *a="RabNawaz",*b="OsamaBin";
Stack <char *>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a<<b<<endl;
}
................................................
swap two Cars

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack{
private:
int size;
int tos;
T *a;
public : 
  Stack(int s) {size=s; tos=-1;
                a= new T[size];}
  void push(T d) {a[++tos]=d;}
  T pop () { return a[tos--];}
};

class Car{
private:
string owner;
public :
	Car()  { }
Car (string o) {owner=o;}
string getOwner(){return owner;}
void setOwner(string o){owner=o;}
};
void main () {
Car a("RabNawaz ki car "),b("OsamaBin ki car ");
Stack <Car>s(2);
s.push(a);
s.push(b);
a=s.pop();
b=s.pop();
cout<<a.getOwner()<<b.getOwner()<<endl;
}
.......................................
Mutli Parameter template
template <class T1,class T2>
class A{
public :
T1 d1;
T2 d2;
};
void main(){
A <int,double>ob;
ob.d1=10;
ob.d2=2.5;
}
..........................................
Static Members in Templates

template <class T>
class A {
public :
A() { a++;}
static int a;
T d1;

};
template <class T>
int A<T>::a=0;

void main () {
A <int> ob1;
A <float>ob2;
A <double> ob3;
A <int> ob4;
cout<<ob1.a<<endl;
cout<<ob2.a<<endl;
cout<<ob3.a<<endl;
cout<<ob4.a<<endl;
}
......................................................

Static variable of Type T

template <class T1>
 T1 f(T1 p){ return p;}

template <class T>
class A {
public :
A() { a++;}
static T a;
T d1;

};
template <class T>
int A<T>::a=f(0);

void main () {

A <int> ob1;
//A <float>ob2;
//A <double> ob3;
A <int> ob4;
cout<<ob1.a<<endl;
//cout<<ob2.a<<endl;
//cout<<ob3.a<<endl;
cout<<ob4.a<<endl;
}
...........................................
















};






