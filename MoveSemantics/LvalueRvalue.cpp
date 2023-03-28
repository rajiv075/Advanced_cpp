#include<iostream>

//Add function returns by value

int Add(int x,int y){
	return x + y;
}

// Transform returning by reference

int& Transform(int& x) 
{
	x *= x;
	return x;
}

void Print(int& x)
{
	std::cout << " Print(int& x) "<<std::endl;
}
void Print(const int& x)
{
	std::cout << " Print(const int& x) "<<std::endl;
}
void Print(int&& x)
{
	std::cout << " Print(int&& x) "<<std::endl;
}

int main() {

	int&& rvalueReference1 = Add(2, 3);
	int&& rvalueReference2 = 10;
	
	// rvalue reference can not bind to l-value
	// l-value reference always bind to l-value , it can never bind to temperary
	int x = 3;
	int& lvalueRefernce1 = Transform(x);

	//l-value reference may be bind to temperary if reference is constant.
	const int& lvalueReference2 = 10;  



	Print(10);  // This will call Print(int&& x). If function accepting R-value reference is not there then 
	            // it will call Print(const int&) "const l-value reference".


	Print(x);    // This will call Print function accepting l-value reference.

	return 0;
}