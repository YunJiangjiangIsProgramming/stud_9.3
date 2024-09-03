#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <functional>

using namespace std;

//��Ŀ��https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution0 {
  public:
      // genBST����������������ת��Ϊƽ������������ĺ��ĵݹ麯��
      // ������numsΪ�������飬l��r�ֱ�Ϊ��ǰ��������������ұ߽�
      // ����ֵ�������������ĸ��ڵ�
      TreeNode* genBST(const std::vector<int>& nums, int l, int r) {
          // ��l>rʱ����ʾ��ǰ������Ϊ�գ�����nullptr
          if (l > r) {
              return nullptr;
          }

          // ��l==rʱ����ʾ��ǰ������ֻʣһ��Ԫ�أ�����һ���½ڵ㲢����
          if (l == r) {
              return new TreeNode(nums[l]);
          }

          // �����м�λ�ã�ѡȡ�м�Ԫ����Ϊ���ڵ�
          int mid = (l + r) / 2;
          TreeNode* root = new TreeNode(nums[mid]);

          // �ݹ鹹����������������
          root->left = genBST(nums, l, mid - 1);
          root->right = genBST(nums, mid + 1, r);

          // ���ظ��ڵ�
          return root;
      }


      TreeNode* sortedArrayToBST(const std::vector<int>& nums) {

          return genBST(nums, 0, nums.size() - 1);
      }
  };

  //��Ŀ:https://leetcode.cn/problems/generate-parentheses/description/?envType=problem-list-v2&envId=backtracking
  class Solution2 {
  public:
      vector<string> generateParenthesis(int n)
      {
          vector<string> ret;
          std::string str;
          backtracking(n, 0, 0, ret, str);
          return ret;
      }

  private:
      void backtracking(int n, int left, int right, std::vector<std::string>& ret, std::string& str)
      {
          if (right > left) {
              return;
          }

          if (left == right && left == n) {
              ret.push_back(str);
              return;
          }

          if (left < n) {
              str.push_back('('); // ���������
              backtracking(n, left + 1, right, ret, str);
              str.pop_back(); // ���ݣ��Ƴ�������
          }

          if (right < left) {
              str.push_back(')'); // ���������
              backtracking(n, left, right + 1, ret, str);
              str.pop_back(); // ���ݣ��Ƴ�������
          }
      }
  };

  class Solution3 
  {
  public:
      long long maxStrength(vector<int>& nums) 
      {
          long long mn = nums[0], mx = mn;
          for (int i = 1; i < nums.size(); i++) 
          {
              long long x = nums[i];
              long long tmp = mn;
              mn = min({ mn, x, mn * x, mx * x });
              mx = max({ mx, x, tmp * x, mx * x });
          }
          return mx;
      }
  };


  void Fun(int& x) { cout << "��ֵ����" << endl; }
  void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

  void Fun(int&& x) { cout << "��ֵ����" << endl; }
  void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

  template<typename T>
  void PerfectForward(T&& t)
  {
	  // t��������ֵ����������ֵ
	  //Fun(move(t));


	  Fun(std::forward<T>(t));
	  //t++;
  }

  //int main()
  //{
  //	//int x = 1;
  //	//func1(x);  //������
  //	//func1(2);
  //
  //	PerfectForward(10);           // ��ֵ
  //
  //	int a;
  //	PerfectForward(a);            // ��ֵ
  //	PerfectForward(std::move(a)); // ��ֵ
  //
  //	const int b = 8;
  //	PerfectForward(b);		      // const ��ֵ
  //	PerfectForward(std::move(b)); // const ��ֵ
  //
  //	return 0;
  //}

 

  //int main()
  //{
  //	Person s1;
  //	Person s2 = s1;
  //	Person s3 = std::move(s1);
  //	//Person s4;
  //	//s4 = std::move(s2);
  //
  //	return 0;
  //}

  // ������A����󱻿���
  class A
  {
  public:
	  void func()
	  {
		  //A tmp(*this);
	  }

	  A()
	  {}

	  ~A()
	  {
		  delete[] p;
	  }

	
	  A(const A& aa) = delete;
	
  private:
	  int* p = new int[10];
  };

  struct Goods
  {
	  string _name;  // ����
	  double _price; // �۸�
	  int _evaluate; // ����
	  // ...

	  Goods(const char* str, double price, int evaluate)
		  :_name(str)
		  , _price(price)
		  , _evaluate(evaluate)
	  {}
  };

  struct ComparePriceLess
  {
	  bool operator()(const Goods& gl, const Goods& gr)
	  {
		  return gl._price < gr._price;
	  }
  };

  struct ComparePriceGreater
  {
	  bool operator()(const Goods& gl, const Goods& gr)
	  {
		  return gl._price > gr._price;
	  }
  };



  void testlambda()
  {

	  // ����int����Ƚϵ�lambda
	// lambda--�ɵ��ö���
	//[](int x, int y)->bool{return x + y; };
	  auto compare = [](int x, int y) {return x > y; };
	  cout << compare(1, 2) << endl;
}
int main()
{


	return 0;
}
