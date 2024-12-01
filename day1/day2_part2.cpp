#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int find_coincidences(vector<int> haystack, int needle) {
  int sum = 0;

  for (int i = 0; i < haystack.size(); i++) {
    if (haystack[i] == needle) {
      sum += 1;
    }
  }

  return sum;
}

int main()
{
  vector<int> left_list = {};
  vector<int> right_list = {};

  ifstream input_file;

  input_file.open("input.txt");

  string input_value;

  if (input_file.is_open())
  {
    int left_line_member, right_line_member;

    while (input_file >> left_line_member >> right_line_member)
    {
      left_list.push_back(left_line_member);
      right_list.push_back(right_line_member);
    }
  }

  int sum = 0;

  for (int i = 0; i < left_list.size(); i++)
  {
    sum += left_list[i] * find_coincidences(right_list, left_list[i]);
  }

  cout << sum;

  return 0;
}