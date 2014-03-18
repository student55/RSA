
#include "iostream"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <math.h>
using namespace std;
__int64 step(int a, int b)
 { __int64 c=a; int i;
    for(i=1;i<b;i++)
        c=c*a;
    return c;
 }
 int nod(int a, int b) {
   int c;
   while (b) {
      c = a % b;
      a = b;
      b = c;
   }
   return (a);
 }
  __int64 step1(int a, int b,int n)
 {  int i; __int64 c=a;
    for(i=1;i<b;i++)
        {c=((c)%n*(a)%n);
        c=c%n;}
    return c%n;
 }
 __int64 prostoe(int a)
 { int i,k=0,c;
     for(i=2;i<a;i++){
        c=a%i;
        if(c==0){
            k=1;break;
        }
    }return k;
     }

 int prost(int a){
     int d,k=0,k1=0;
 while(k1==0)
{
 a=rand() % 99 + 13;
 k=prostoe(a);
 if(k==0)k1++;
 else k=0;
 }
 return a;
 }

int main()
{
	setlocale(LC_ALL, "Russian");
	__int64 i=0, j, n,k=0, c=0,f, e , d , mr = 0, m ;
	int  p=0, q=0,p1=0,q1=0;
	cout << endl;
	srand(time(NULL));
    do{
    while(k==0)
        {
    p=prost(p1);
    q=prost(q1);
    if (p!=q&&nod(p,q)==1)k++;
    }
	n = p*q;//произведение
	f = (p - 1)*(q - 1);//функция Эйлера
	while(1)//переключатель
    {
        e=prost(p1) ;
       //e=7;///////////////////////////////////
        c=nod(f,e);
        if (c==1&&e>1&&e<f&&e<100) break;
    }
	for (i = 0; i<20000; i++){ if (((e*i) % f == 1)&&(e!=i)){ d = i; break; } }//находим d
	} while (d<0&&d>120);
    cout<<"первое простое число: "<<p<<endl;
    cout<<"второе простое число: "<<q<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"f(n): "<<f<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"d: "<<d<<endl<<endl;
    cout<<"Ключи: "<<endl<<endl<<"Открытый ключ: ("<<e<<", "<<n<<")"<<endl<<"Закрытый ключ: ("<<d<<", "<<n<<")"<<endl<<endl;
    cout<<"Введите код для кодирвоания: ";
    cin >> m;
	//--------шифрование------------
	c=(step1((m),e,n));//c =( (step(m,e)) % n);
	//-------расшифровка-----------
	mr=(step1((c),d,n));//mr = ((step(c,d)) % n);

	cout << endl<< "Шифрованное слово: " << c << endl<< endl;
	cout << "ДеШифрованное слово: " << mr << endl;



}
