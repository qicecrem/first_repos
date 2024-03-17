//#include<iostream>
//#include<string>
//using std::cin;
//using std::endl;
//using std::cout;
//using std::string;
//int main()


	/*cout << "Please enter your first name: ";
	string name;
	cin >> name;
	string greeting = "Hello, " + name + "!";
	int pad = 1;
	int rows = pad * 2 + 3;
	int cols = greeting.size() + rows - 1;
	for (int i = 0; i != rows; ++i)
	{
		int c = 0;
		while (c != cols)
		{
			if (i == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (i == 0 || i == rows - 1 || c == 0 || c ==cols - 1)
				{
					cout << "*";
					++c;
				}
				else {
					cout << " ";
					++c;

				} 
			}
		}
		cout << endl;
	}

	return 0;*/
	/*cout << "Please enter your first name: " << endl;
	string name;
	cin >> name;
	int pad = 1;
	int rows = pad * 2 + 3;
	string greeting = "Heelo, " + name + "!";
	string::size_type cols = greeting.size() + 4;
	for (int i = 0; i < rows; i++)
	{
		string::size_type c = 0;
		while (c < cols)
		{
			if (i == pad + 1 && c == pad + 1)
			{
				cout << greeting ;
				c += greeting.size();
			}
			else {
				if (i == 0 || i == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";
					c++;
				}
				else {
					cout << " ";
					c++;
				}
			}
		}
		cout << endl;

	}
}*/
//#include<iomanip>
//#include<ios>
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	cout << "Please enter your first name: ";
//	string name;
//	cin >> name;
//	cout << "Hello," << name << "!" << endl;
//	cout << "Please enter your midterm and final exam grades: ";
//	double midterm, final;
//	cin >> midterm >> final;
//	cout << "Enter all your homework grades: \n";
//	int count=0;
//	double sum = 0;
//	double x;
//	cout << "Enter any letter to end";
//	while (cin >> x)
//	{
//		count++;
//		sum += x;
//
//	}
//
//	streamsize prec = cout.precision();
//	cout << "Your final grade is" << setprecision(3)
//		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count
//		<< setprecision(prec) << endl;
//	return 0;
//}
//#include<algorithm>
/*#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	cout << "Please enter your first name:";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	cout << "Enter all your homework grades, "
		" enter letter to end  \n";
	vector<double> homework;
	double x;
	while (cin >> x)
	{
		homework.push_back(x);
	}
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0)
	{
		cout << endl << "Ypo must enter your grades.""pleasetry again." << endl;
		return 1;
	}
	sort(homework.begin(), homework.end());
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
	streamsize prec = cout.precision();
	cout << "Ypur final grade is " << setprecision(3);
	cout<< 0.2 * midterm + 0.4 * final + 0.4 * median << setprecision(prec) << endl;

	return 0;
}
*/
//#include<string>
//using namespace std;
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.length() <= 1)
//		{
//			return s;
//		}
//		auto expand_from_center = [&](int left, int right)
//		{
//			while (left >= 0 && right < s.length() && s[left] == s[right])
//			{
//				left--;
//				right++;
//			}
//			return s.substr(left + 1, right - left - 1);
//		};
//		string max_str = s.substr(0, 1);
//		for (int i = 0; i < s.length() - 1; i++) {
//
//			string odd = expand_from_center(i, i);
//			string even = expand_from_center(i, i + 1);
//			if (odd.length() > max_str.length())
//			{
//				max_str = odd;
//			}
//			if (even.length() > max_str.length())
//			{
//				max_str = even;
//			}
//		}
//		return max_str;
//	}
//
//};
#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i])
		{
			i++;
			string_size j = i;
		}
		while (j != s.size() && !isspace(s[j]))
		{
			j++;
		}
		if (i != j)
		{
			ret.push_back(s.substr(i, j, -i));
			i = j;
		}
		return ret;
	}

}