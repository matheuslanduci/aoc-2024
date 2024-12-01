#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

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

  sort(left_list.begin(), left_list.end());
  sort(right_list.begin(), right_list.end());

  int sum = 0;

  for (int i = 0; i < left_list.size(); i++)
  {
    sum += abs(left_list[i] - right_list[i]);
  }

  cout << sum;

  return 0;
}