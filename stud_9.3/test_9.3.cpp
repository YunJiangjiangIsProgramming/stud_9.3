#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <functional>

using namespace std;

//题目：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
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
      // genBST函数：将有序数组转换为平衡二叉搜索树的核心递归函数
      // 参数：nums为有序数组，l和r分别为当前处理子数组的左、右边界
      // 返回值：构建的子树的根节点
      TreeNode* genBST(const std::vector<int>& nums, int l, int r) {
          // 当l>r时，表示当前子数组为空，返回nullptr
          if (l > r) {
              return nullptr;
          }

          // 当l==r时，表示当前子数组只剩一个元素，创建一个新节点并返回
          if (l == r) {
              return new TreeNode(nums[l]);
          }

          // 计算中间位置，选取中间元素作为根节点
          int mid = (l + r) / 2;
          TreeNode* root = new TreeNode(nums[mid]);

          // 递归构建左子树和右子树
          root->left = genBST(nums, l, mid - 1);
          root->right = genBST(nums, mid + 1, r);

          // 返回根节点
          return root;
      }


      TreeNode* sortedArrayToBST(const std::vector<int>& nums) {

          return genBST(nums, 0, nums.size() - 1);
      }
  };

  //题目:https://leetcode.cn/problems/generate-parentheses/description/?envType=problem-list-v2&envId=backtracking
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
              str.push_back('('); // 添加左括号
              backtracking(n, left + 1, right, ret, str);
              str.pop_back(); // 回溯，移除左括号
          }

          if (right < left) {
              str.push_back(')'); // 添加右括号
              backtracking(n, left, right + 1, ret, str);
              str.pop_back(); // 回溯，移除右括号
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


  void Fun(int& x) { cout << "左值引用" << endl; }
  void Fun(const int& x) { cout << "const 左值引用" << endl; }

  void Fun(int&& x) { cout << "右值引用" << endl; }
  void Fun(const int&& x) { cout << "const 右值引用" << endl; }

  template<typename T>
  void PerfectForward(T&& t)
  {
	  // t可能是左值，可能是右值
	  //Fun(move(t));


	  Fun(std::forward<T>(t));
	  //t++;
  }

  //int main()
  //{
  //	//int x = 1;
  //	//func1(x);  //不可以
  //	//func1(2);
  //
  //	PerfectForward(10);           // 右值
  //
  //	int a;
  //	PerfectForward(a);            // 左值
  //	PerfectForward(std::move(a)); // 右值
  //
  //	const int b = 8;
  //	PerfectForward(b);		      // const 左值
  //	PerfectForward(std::move(b)); // const 右值
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

  // 不想让A类对象被拷贝
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
	  string _name;  // 名字
	  double _price; // 价格
	  int _evaluate; // 评价
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

	  // 进行int对象比较的lambda
	// lambda--可调用对象
	//[](int x, int y)->bool{return x + y; };
	  auto compare = [](int x, int y) {return x > y; };
	  cout << compare(1, 2) << endl;
}
int main()
{


	return 0;
}
