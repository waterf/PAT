#include "iostream"
#include "math.h"

//第一个c++程序

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	int n, temp;
	char s;
	cin >> n;
	cin >> s;
	temp = floor(1.0*n/2+0.5);
	for(int i=0;i<n;i++)
		cout << s;
	cout << "\n";
	for(int i=0;i<temp-2;i++)
	{
		cout << s;
		for(int j=0;j<n-2;j++)
			cout << " ";
		cout << s << "\n";
	}
	for(int i=0;i<n;i++)
		cout << s;
	cout << endl;
}
