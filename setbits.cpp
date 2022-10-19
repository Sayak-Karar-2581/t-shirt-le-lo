#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<"Number of Set bits is : "<<__builtin_popcount(n);
	return 0;
}
