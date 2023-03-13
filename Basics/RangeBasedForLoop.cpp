#include <iostream>
int main()
{
	using namespace std;
	int arr[] = { 1,2,3,4,5 };

	cout << "FOR -LOOP" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	cout << "Range Based For loop \n";

	for (auto &x : arr) {                     // taking &x will not create duplicate variable of the each array value
		x = 4;                               //to modify elements of the array 
		cout << x << " ";
	}
	cout << endl;
	cout << "Using Range Based For loop On initializer list : \n";
	for (auto x : {1,2,3,4,5}) {           // initializer list                                      
		cout << x << " ";
	}
	cout << endl;


	//    Let's see How Range based for loop works internally

	auto begin = std::begin(arr);
	auto end = std::end(arr);
	for (; begin != end; ++begin)
	{
		cout << *begin << " ";
	}

	auto range = arr;
	auto begin1 = std::begin(arr);     // we cannot use range variable std::begin(range) although it is having arr , 
	                                   // because auto is of type is pointer to arr now not a range type.
	                                   // NOTE : std::begin() and std::end() do not work with pointer to arrays;
	auto end1 = std::end(arr);
	for (; begin1 != end1; ++begin1)
	{
		auto v = *begin;                         // this is how range based for loop is implemented internally
	}

	//  Begin and End should be sametype but, but in some ranges begin and end may not be same like character arrays ( end with \0) 
	//  so in this cases Range Based for loop may not work  - In cpp 17 they changed this we can have different begin and end type.


	// forwarding reference 

	auto &&range2 = arr;                        // && - Forwarding reference opoerator we can use this for std::begin() and std::end() 
	                                            // the type of the range2 will now become the type of arr
	auto begin2 = std::begin(range2);
	auto end2 = std::end(range2);

	return 0;
}


//          For Loop                                          Range-Based For
/*
           1. Index based Iteration                   1. Does not use to iterate
		   2. Requires End condition                  2. No End condition
		   3. index variable needs to be incremented  3. No need to increment
		   4. More control over iteration             4. Less control over iteration
		   5. use for finer Control                   5. use with ranges
*/