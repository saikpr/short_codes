#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <string>
#include <stack>
using namespace std;

template <int val>
void printval(string str)
{
	if (val == 3)
		cout<<str;
	return;

}
int main()
{
	printval<2>(string("Hello"));
}