#include<iostream>
using namespace std;
class stack
{
  public:
      stack() {top = 0;}
      int push(int value)
      {
           if (top+1<=maxsize)  {
                top++;
                S[top]=value;
                return 1;}
        return 0;}
        int pop(int *old);
        int whathight() {return top;}
        int isempty() { return (top<1);}
        private :
        int top;
        int S[100];
        int maxsize=100;
};
int n,m;
stack somestack;
/*
        |n+1 <=> m=0
f(m,n)= |f(m-1,1) <=> n=0
        |f(m-1,f(m,n-1))               <=> m!=0, n!=0
*/
int main()
{
cout<<"m=";cin>>m;
cout<<"n=";cin>>n;
somestack.push((n-2)+3);
int direction=1;
int oldval1,oldval2,oldval3;
oldval3=m;
oldval2=n;
while (somestack.whathight()>=1) {
    cout<<endl<<somestack.whathight();
    if (direction==1)
            {
            somestack.pop(&oldval1);
            somestack.push(oldval1);
            somestack.push(oldval1-1);
                                            if (oldval1==0) direction=0;}
                                            else
                                        {
                                            somestack.pop(&oldval1);
                                            somestack.push(oldval1+2);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);
                                            somestack.pop(&oldval1-1);
                                            somestack.push(oldval1+2);
                                            somestack.pop(&oldval1-1);} }
                                        while(oldval3==0) {oldval2=oldval2+1;oldval3=1;}
                                        while(oldval2==0) {oldval3=oldval3-1; oldval2=1;}
cout<<" Compute = "<<oldval3+oldval2-1;
return 0;}
int stack::pop(int *old)
{if  (isempty()) { return 0;}
 *old=S[top];top--;
 return 1;}
