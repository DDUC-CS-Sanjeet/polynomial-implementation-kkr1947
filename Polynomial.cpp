#include<iostream>
using namespace std;
class Polynomial
{
  private:
  int size;
  int *arr;
public:
	Polynomial()
	{
    size=0;
	arr=NULL;
	}
    Polynomial(int deg)
    {
    size=deg;
	arr = new int[size];
	for ( int i = 0; i<size; i++ )
      {
         arr[i] = 0;
      }
    }
     ~Polynomial()
    {
    delete []arr;
    }
     Polynomial operator +(Polynomial const &p)
	{ 
	int f=0;
	if(p.size>=size)
		f=1;
		else
		f=0;
	if(f==1)
    {
      Polynomial s(p.size);
      for ( int i = 0; i < (p.size-size); i++ )
      s.arr[i]=p.arr[i];
      for ( int i = 0; i < p.size; i++ )     
      s.arr[i+(p.size-size)]=arr[i]+p.arr[i+(p.size-size)];
      	return s;
    }
      else
      {
       Polynomial s(size);
      for ( int i = 0; i < (size-p.size); i++ )
      s.arr[i]=arr[i];
       for ( int i = 0; i<size; i++ )    
       s.arr[i+(size-p.size)]=arr[i+(size-p.size)]+p.arr[i];
		return s;
      }
	 }
	Polynomial operator -(Polynomial const &p)
	{ 	int f=0;
	if(p.size>=size)
		f=1;
		else
		f=0;
	if(f==1)
    {
      Polynomial s(p.size);
      for ( int i = 0; i < (p.size-size); i++ )
      s.arr[i]=p.arr[i];
      for ( int i = 0; i < p.size; i++ )     
      s.arr[i+(p.size-size)]=arr[i]-p.arr[i+(p.size-size)];
      	return s;
    }
      else
      {
       Polynomial s(size);
      for ( int i = 0; i < (size-p.size); i++ )
      s.arr[i]=arr[i];
       for ( int i = 0; i<size; i++ )    
       s.arr[i+(size-p.size)]=arr[i+(size-p.size)]-p.arr[i];
		return s;
      }
	 }
	Polynomial operator =(Polynomial const &p)
	{ 
int f=0;
	if(p.size>=size)
		f=1;
		
	else
		f=0;
	if(f==1)
    {
      Polynomial s(p.size);
      for ( int i = 0; i < p.size; i++ )     
      s.arr[i]=p.arr[i];
      	return s;
    }
      else
      {
       Polynomial s(size);
       for ( int i = 0; i<size; i++ )    
       s.arr[i]=p.arr[i];
		return s;
      }
    } 
  void storePolynomial()
    {
	cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++)
	cin>>arr[i];
    }
    void display()
    {
	cout<<"The elements of the array :"<<endl;
    for(int i=0;i<size;i++)
	{
	cout<<arr[i];
	if(i!=(size-1))
	cout<<"x^"<<(size-i-1)<<"+";
	}
     cout<<endl;
    }
  };

int main()
{
  int degFirst, degSecond;
  cout<<"Enter the first degree"<<endl;
  cin>>degFirst;
  cout<<"Enter the second degree"<<endl;
  cin>>degSecond;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  Polynomial thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  firstPolynomial.display();
  secondPolynomial.display();
  thirdPolynomial.display();
  fourthPolynomial.display();
  return 0;
}
