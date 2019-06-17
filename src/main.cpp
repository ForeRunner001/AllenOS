#include <iostream>
#include <climits>
#include <sstream>

class A {
public:
	int GetValue() const {
		return i;
	}
private:
	int i = 0;
};
using namespace std;
int main()
{
    std::cout << "Hello,Git!" << std::endl;
    long sl_value;
    cout << UINT_MAX
         << endl;
    A foo;
    const int j = foo.GetValue();
    std::cout << "j=" << j << std::endl;
    const string s1 = "Hello";
    string s2 = s1 + ",world";
    cout << s2 << endl;

    ostringstream oos("hello copy ");
    ostringstream oos2;
    oos2 << oos.str();
    string str = s1 + oos2.str() + ".avi";
    cout << str << endl;

    return 0;
}
