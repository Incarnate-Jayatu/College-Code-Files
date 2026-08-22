#include<iostream>
using namespace std;

class Sub
{
	public:
            int x,y;
            //constructor
         Sub(int a2, int b2) {
         	x=a2;
         	y=b2;
		 }  
		 
		 // operator overloading
		 Sub operator-(Sub obj){
		    Sub temp (0,0);
		 	temp.x = x - obj.x;
		 	temp.y = y - obj.y;
		 	return temp;
		 }
		 
		 void display (){
		 	cout<<"x"<< x <<"y"<< y << endl; 		
		 }
};
class Add
{
	public:
            int j,m;
            //constructor
         Add(int a1, int b1) {
         	j=a1;
         	m=b1;
		 }  
		 
		 // operator overloading
		 Add operator+(Add obj){
		    Add temp (0,0);
		 	temp.j = j + obj.j;
		 	temp.m = m + obj.m;
		 	return temp;
		 }
		 
		 void display (){
		 	cout<<"j"<< j <<"m"<< m << endl; 		
		 }
};
class Mul
{
	public:
            int v,w;
            //constructor
         Mul(int a3, int b3) {
         	v=a3;
         	w=b3;
		 }  
		 
		 // operator overloading
		 Mul operator*(Mul obj){
		    Mul temp (0,0);
		 	temp.v = v * obj.v;
		 	temp.w = w * obj.w;
		 	return temp;
		 }
		 
		 void display (){
		 	cout<<"v"<< v <<"w"<< w << endl; 		
		 }
};

class Div
{
	public:
            int s,t;
            //constructor
         Div(int a4, int b4) {
         	s=a4;
         	t=b4;
		 }  
		 
		 // operator overloading
		 Div operator/(Div obj){
		    Div temp (0,0);
		 	temp.s = s/obj.s;
		 	temp.t = t/obj.t;
		 	return temp;
		 }
		 
		 void display (){
		 	cout<<"s"<< s <<"t"<< t << endl; 		
		 }
};

int main(){
	Add a1(2,3);
	Add b1(4,5);
	Add c1 = a1+b1;
	c1.display();
	
	Sub a2(2,3);
	Sub b2(4,5);
	Sub c2= a2-b2;
	c2.display();
	
	Mul a3(2,3);
	Mul b3(4,5);
	Mul c3= a3*b3;
	c3.display();
	
	Div a4(2,3);
	Div b4(4,5);
	Div c4= a4/b4;
	c4.display();
	return 0;
}
