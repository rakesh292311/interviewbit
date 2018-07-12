#include <iostream>
#include <cmath>
#include  <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
	string largestNumber(const vector<int> &A);
	void setZeroes(vector<vector<int> > &A);
	int firstMissingPositive(vector<int> &A);
	int lPalin(ListNode * A);
	ListNode * reverseList(ListNode * A, int B);
	ListNode * lreverse(ListNode * A);
	ListNode * lfindmid(ListNode * A);
	int solve(vector<int> &A, int B, int C);
	void arrange(vector<int> &A);
	string convert(string str, int n);
	int numSetBits(unsigned int A);
	int singleNumber(const vector<int>& A);
	int findMinXor(vector<int>& A);
	int solve(vector<int>& A, vector<int>& B, vector<int>& C);
	ListNode * partition(ListNode * A, int B);
	ListNode * reverseBetween(ListNode * A, int B, int C);
	ListNode * detectCycle(ListNode * A);
	string simplifyPath(string A);
	vector<int> prevSmaller(vector<int>& A);
	int evalRPN(vector<string>& A);
	vector<vector<int>> subsets(vector<int>& A);
	vector<vector<string>> solveNQueens(int A);
	int colorful(int A);
	vector<int> equal(vector<int>& A);
	vector <int> primesum(int A);
	int titleToNumber(string A);

	Solution() {
//		convert("ABCDEFGHIJKLMNOPQRS", 6);
		//vector <int> a = { 1, 4, 5, 8, 10 };
		vector <int> b = { 12, 13};
		//vector <int> c = { 2, 3, 6, 6 };
		ListNode *a = new ListNode(1);
		//a->next = new ListNode(1);
		//lPalin(a);
		vector<string> o = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
	//	simplifyPath("/ a / . / b / .. / .. / c / ");
		//evalRPN(o);
		//reverseBetween(a, 1, 1);
		//prevSmaller(b);
		//subsets(b);
		//solve(a,b,c);
		//solveNQueens(4);
		colorful(23);
	};
};
bool compare(Interval &a, Interval &b)
{
	if (a.start < b.start)
		return true;
	else if (a.start == b.start)
	{
		if (a.end < b.end)
			return true;
	}
		return  false;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
	vector <Interval> result;
	int news = min(newInterval.start, newInterval.end);
	int newe = max(newInterval.start, newInterval.end);

	newInterval.start = news;
	newInterval.end = newe;
	intervals.push_back(newInterval);
	sort(intervals.begin(), intervals.end(), compare);
	static int j = 0;
	result.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++)
	{
		j = result.size() - 1;
		if (max(intervals[i].start, result[j].start) > min(intervals[i].end, result[j].end))
		{
				result.push_back(intervals[i]);
		}
		else
		{
			result[j].start = min(result[j].start, intervals[i].start);
			result[j].end = max(result[j].end, intervals[i].end);
		}
	}
	return result;
}
bool strcompare(string &a, string &b)
{
	string ab = a.append(b);
	string ba = b.append(a);
	return (ab.compare(ba) > 0) ? 1 : 0;
}
string Solution::largestNumber(const vector<int> &A) {
	vector <string> test;
	for (int i = 0;i < A.size(); i++)
	{
		test.push_back(to_string(A[i]));
	}
	sort(test.begin(), test.end(), strcompare);
	string result;
	for (int i = 0;i < test.size();i++)
	{
		result += test[i];
	}
	result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
	if (result.size() == 0)
		result = "0";
	return result;
}
void Solution::setZeroes(vector<vector<int> > &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector <bool> row(A.size());
	vector<bool> column(A[0].size());
	
	for (int i = 0;i < A.size();i++)
	{
		for (int j = 0; j < A[0].size();j++)
		{
			if (A[i][j] == 0)
			{
				row[i] = true;
				column[j] = true;
			}

		}
	}
	for (int i = 0;i < A.size();i++)
	{
		if (row[i])
		{
			for (int j = 0;j < A[0].size();j++)
			{
				A[i][j] = 0;
			}
		}
	}
	for (int i = 0;i < A[0].size();i++)
	{
		if (column[i])
		{
			for (int j = 0;j < A.size();j++)
			{
				A[j][i] = 0;
			}
		}
	}
	return;
}
int Solution::firstMissingPositive(vector<int> &A) {
	if (A.size() == 0)
		return 1;
	sort(A.begin(), A.end());
	if (A[0] > 1)
		return 1;
	for (int i = 1; i < A.size();i++)
	{
		if (A[i] > 0)
		{
			if (A[i] - A[i - 1] > 1)
			{
				if (A[i] > 0 && A[i - 1] >= 0)
					return A[i - 1] + 1;
				else if (A[i] > 1)
					return 1;
			}
		}

	}
	return 1;
}

 
int Solution::lPalin(ListNode* A) {
	if (A == NULL)
		return  0;
	ListNode *mid = lfindmid(A);
	ListNode *fh, *sh;
	sh = mid->next;
	mid->next = NULL;
	fh = A;
	sh = lreverse(sh);
	while (sh)
	{
		if (sh->val != fh->val)
			return 0;
		sh = sh->next;
		fh = fh->next;
	}
	return 1;
}
ListNode* Solution::reverseList(ListNode* A, int B) {
	if (A == NULL)
	{
		return A;

	}
	if (B == 0 || B == 1)
		return A;
	int c = 0;
	ListNode *cur, *prev, *next;
	cur = A;
	prev = next = NULL;
	while (cur && c<B)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		c++;
		
	}
	if (next != NULL)
		A->next = next;//reverseList(next, B);
	return prev;
}
ListNode * Solution::lreverse(ListNode* A) {
	ListNode *cur, *prev, *next;
	prev = next = NULL;
	cur = A;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
ListNode * Solution::lfindmid(ListNode* A) {
	ListNode *fast, *slow;
	if (A == NULL)
		return A;
	fast = slow = A;
	while (fast && fast->next)
	{
		fast = fast->next;
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
vector<int> Solution::primesum(int A) {
	vector<bool> isprime(A+1);
	vector <int> result;
	fill(isprime.begin(), isprime.end(), true);
	isprime[0] = false;
	isprime[1] = false;
	for (int i =2 ; i*i<=A;i++ )
	{
		if (isprime[i] == true)
		{
			for (int j = i*2; j <= A; j+=i)
				isprime[j] = false;
		}
	}
	for (int i = 2; i <= A / 2;i++)
	{
		if (isprime[i] == true)
		{
			if (isprime[A - i] == true)
			{
				result.push_back(i);
				result.push_back(A - i);
			}
		}
	}
	return result;
}
int Solution::titleToNumber(string A) {
	int len = A.length();
	int column=0;
	string::reverse_iterator it;
	int i = 1;
	for (it = A.rbegin(); it < A.rend();it++)
	{
		column += i * (*it - 'A' + 1);
		i =i * 26;
	}
	return column;
}
void findnumber(int limit,vector<int> &A, int rev, int  len, int car, int &count)
{
	if (len == 0)
	{
		if (car < limit)
			count++;
		return;
	}
	int ldigit = rev % 10;
	for (int i = 0; i < A.size();i++)
	{
//		if (A[i] <= ldigit)
	//	{
			if (A[i] == 0)
			{
				if (len == 1 || car != 0)
					findnumber(limit, A, rev / 10, len - 1, (car * 10) + A[i], count);
			}
			else
			{
				findnumber(limit, A, rev / 10, len - 1, (car * 10) + A[i], count);
			}
		//}
	}

}
int calnumbers(vector<int> &a, int b)
{
	int count = 1;
	int d = a.size();
	for (int i = 0;i < b; i++)
	{
		if (i==0 && a[0] == 0 && b!=1)
			count *= d-1;
		else
			count *= d;
	}
	return count;
}
int dp_calnumbers(vector<int> &A, int B, int C)
{
	vector<int> digit(B);
	int n = C;
	for (int i = digit.size() - 1;n>0;i--)
	{
		digit[i] = n % 10;
		n /= 10;
	}
	vector<int>lower(11);
	int d = A.size();

	fill(lower.begin(), lower.end(), 0);
	for (int i = 0; i < d; i++)
		lower[A[i] + 1] = 1;
	for (int i = 1; i <= 10; i++)
		lower[i] = lower[i - 1] + lower[i];

	vector <int>dp(B + 1);
	dp[0] = 0;
	bool flag = true;
	
	int d2;
	for (int i = 1; i <= B; i++)
	{
		d2 = lower[digit[i - 1]];
		dp[i] = dp[i - 1] * d;
		if (i == 1 && A[0] == 0 && B != 1)
			d2 = d2 - 1;

		if (flag)
			dp[i] += d2;
		//Is digit[i - 1] present in A ?
		flag = flag & (lower[digit[i - 1] + 1] == lower[digit[i - 1]] + 1);
	} 
	return dp[B];
}
int Solution::solve(vector<int> &A, int B, int C) {
	if (A.size() == 0 || B ==0 || C == 0 )
		return 0;

	int crev = 0, n = C,digit;
	int dcount = 0;
	while (n != 0)
	{
		dcount++;
		digit = n % 10;
		crev = (crev * 10) + digit;
		n /= 10;
	}
	if (B > dcount)
		return 0;
	else if (B < dcount)
		return calnumbers(A, B);
	else
		return dp_calnumbers(A,B,C);
	//int count = 0;
	//findnumber(C, A, crev, B, 0, count);
	//return count;

}
void Solution::arrange(vector<int> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		A[i] += A[A[i]] % n * n;
	}
	for (size_t i = 0; i < n; i++)
	{
		A[i] /= n;
	}
}
string Solution::convert(string str, int n) {
	
	string result;
	if (str.length() == 0)
		return result;
	if (n == 1)
		return str;
	// Find length of string
	int len = str.length();

	// Create an array of strings for all n rows
	vector<string> arr(n);

	// Initialize index for array of strings arr[]
	int row = 0;
	bool down; // True if we are moving down in rows, 
		   // else false

		   // Travers through given string
	for (int i = 0; i < len; ++i)
	{
		// append current character to current row
		arr[row].push_back(str[i]);

		// If last row is reached, change direction to 'up'
		if (row == n - 1)
			down = false;

		// If 1st row is reached, change direction to 'down'
		else if (row == 0)
			down = true;

		// If direction is down, increment, else decrement
		(down) ? (row++) : (row--);
	}

	// Print concatenation of all rows
	for (int i = 0; i < n; ++i)
		result+= arr[i];
	return result;
}
int Solution::numSetBits(unsigned int A) {
	if (A == 0)
		return 0;
	int j = 1, count = 0;
	for (size_t i = 0; i < 32; i++)
	{
		if (A & j)
			count++;
		j=j << 1;
	}
	return count;
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
int Solution::singleNumber(const vector<int> &A) {
	int answer = 0;
	for (size_t i = 0; i < A.size(); i++)
	{
		answer ^= A[i];
	}
	return answer;
}
int Solution::findMinXor(vector<int> &A) {
	if (A.size()  < 2)
		return 0;
	int n = A.size();
	int minxor = INT_MAX;
	int t = INT_MAX;
	sort(A.begin(), A.end());
	for (size_t i = 0; i < n-1; i++)
	{
		t = A[i] ^ A[i+1];
		if (minxor > t)
			minxor = t;
		
	}
	return minxor;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
	int diff = INT_MAX;  // Initialize min diff

						 // Initialize result
	int res_i = 0, res_j = 0, res_k = 0;

	// Traverse arrays
	int p = A.size();
	int q = B.size();
	int r = C.size();

	int i = 0, j = 0, k = 0;
	while (i < p && j < q && k < r)
	{
		// Find minimum and maximum of current three elements
		int minimum = min(A[i], min(B[j], C[k]));
		int maximum = max(A[i], max(B[j], C[k]));

		// Update result if current diff is less than the min
		// diff so far
		if (maximum - minimum < diff)
		{
			res_i = i, res_j = j, res_k = k;
			diff = maximum - minimum;
		}

		// We can't get less than 0 as values are absolute
		if (diff == 0) break;

		// Increment index of array with smallest value
		if (A[i] == minimum) i++;
		else if (B[j] == minimum) j++;
		else k++;
	}

	// Print result
	return diff;
}
void replacenode(ListNode* a, ListNode* b, ListNode* c)
{
	ListNode *temp1 = a, *temp2 = b;

	if (a != b)
	{
		while (temp1)
		{
			if (temp1->next == b)
				break;
			temp1 = temp1->next;
		}
	}
	while (temp2)
	{
		if (temp2->next == c)
			break;
		temp2 = temp2->next;
	}
	temp2->next = c->next;
	if (a != b)
	{
		temp1->next = c;
		c->next = b;
	}
	else {
		c->next = a;
		a = c;
	}
	return;

}
ListNode* Solution::partition(ListNode* A, int B) {
	if (A == NULL)
		return A;
	ListNode *pos = NULL, *temp = A;
	while (temp)
	{
		if (temp->val >= B)
		{
			pos = temp;
			break;

		}
		temp = temp->next;

	}
	if (pos)
		temp = pos->next;
	while (temp)
	{
		if (temp->val < B)
		{
			replacenode(A, pos, temp);
			temp = pos;
		}
		temp = temp->next;
	}
	return A;
}


ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
	ListNode *temp = A, *prev = NULL;
	int count = 0;
	while (temp)
	{
		++count; if (count == B) break;
		prev = temp;
		temp = temp->next;
	}
	if (prev)
		prev->next = reverseList(temp, C);
	else
		return reverseList(temp, C);
	return A;
}
ListNode* Solution::detectCycle(ListNode* A) {
	if (A == NULL)
		return A;

	ListNode * slow_ptr, *fast_ptr;
	slow_ptr = fast_ptr = A;
	while (fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next;
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
		if (slow_ptr == fast_ptr)
			break;
	}
	if (slow_ptr == fast_ptr)
	{
		slow_ptr = A;
		while (fast_ptr != slow_ptr)
		{
			fast_ptr = fast_ptr->next;
			slow_ptr = slow_ptr->next;
		}
		return slow_ptr;
	}
	return NULL;

	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
string Solution::simplifyPath(string A) {
	if (A.size() == 0)
		return A;
	string result;
	int f = A.rfind("\/");
	if (f != string::npos)
	{
		A.erase(f);
		f = A.rfind("\/");
		if (f != string::npos)
		{
			for (f; f < A.size(); f++)
			{
				result.push_back(A[f]);
			}
		}
	}
	return result;
}
vector<int> Solution::prevSmaller(vector<int> &A) {
	vector<int> result(A.size());
	stack<int> min;
	for (int i = 0;i < A.size();i++)
	{
		if (min.empty())
		{
			min.push(A[i]);
			result[i] = -1;
		}
		else
		{
			if(A[i] < min.top()){
				while (!min.empty() )
				{
					if (A[i] < min.top())
						min.pop();
					else
						break;
				
				}
				if (min.empty())
					result[i] = -1;
				else
					result[i] = min.top();

				min.push(A[i]);

			}
			else
			{
				while (!min.empty())
				{
					if (A[i] < min.top())
						min.pop();
					else
					{
						result[i] = min.top();
						break;
					}
				}
				min.push(A[i]);
			}
		}
	}
	return result;
}
int Solution::evalRPN(vector<string> &A) {
	if (A.size() == 0)
		return 0;
	stack<int> operands;
	string plus, minus, mul, div;
	plus = "+";
	minus = "-";
	mul = "*";
	div = "/";
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i]!= plus && A[i] != minus && A[i] != mul && A[i] != div)
		{
			operands.push(atoi(A[i].c_str()));
		}
		else
		{
			int t1 = operands.top();
			operands.pop();
			int t2 = operands.top();
			operands.pop();
			if (A[i] == "*")
				t2 = t2 * t1;
			else if (A[i] == "/")
				t2  = t2/t1;
			else if (A[i] == "+")
				t2 += t1;
			else if (A[i] == "-")
				t2 -= t1;
			operands.push(t1);
		}
	}
	return operands.top();
}
class MinStack {
public:
	MinStack();
	void push(int x);
	void pop();
	int top();
	int getMin();

};
MinStack::MinStack() {
}

void MinStack::push(int x) {
}

void MinStack::pop() {
}

int MinStack::top() {
	return 0;
}

int MinStack::getMin() {
	return 0;
}
void calcsubset(vector<vector<int>> &r, vector<int> &a, int start, vector<int> &s)
{
	if (start == a.size())
	{
		r.push_back(s);
		return;
	}
	calcsubset(r, a, start + 1, s);
	s.push_back(a[start]);
	calcsubset(r, a,start + 1, s);
	s.pop_back();

}
vector<vector<int> > Solution::subsets(vector<int> &A) {
	vector<vector<int> > result;
	if (A.size() == 0)
		return result;
	vector<int> temp;
	sort(A.begin(), A.end());
	calcsubset(result, A, 0, temp);
	sort(result.begin(), result.end());
	return result;
}
bool isSafe_nqueen(vector<int> &a, int r, int pos)
{
	int length = a.size();
	for (int i = 0; i < r; i++)
	{
		if ((a[i] == pos) || ((a[i] ^ i) == (pos ^ r)))
			return false;
	}
	return true;
}
void solveNQueensUtil(vector<int> &b, int r)
{
	int n = b.size();
	for (size_t i = 0; i < n; i++)
	{
		if (isSafe_nqueen(b, r, i))
		{
			b[r] = i;
			if (r == n - 1)
				return;
			solveNQueensUtil(b, r + 1);
		}
	}

}
vector<vector<string> > Solution::solveNQueens(int A) {
	vector<vector<string>> result (A,vector<string>(A));
	//return result;
	for (size_t i = 0; i < A; i++)
	{
		for (size_t j = 0; j< A; j++)
		{
			result[i][j] = '.';
		}

	}
	vector<int> board(A,-1);
	solveNQueensUtil(board, 0);
	for (size_t i = 0; i < A;i++)
	{
		if (board[i] == -1)
			return vector<vector<string>>(0);
	}
	for (size_t i = 0; i < A; i++)
	{
		result[i][board[i]] = 'Q';
	}
	return result;
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
int hashfunction(int A)
{
	int k = 1;
	while (A)
	{
		k *= A % 10;
		A = A / 10;
	}
	return k;
}
int Solution::colorful(int A) {
	unordered_map <int, int> hashmap;
	int r, d,k;
	while (A)
	{
		k = hashfunction(A);
		if (hashmap.find(k) == hashmap.end())
			hashmap.emplace(k, d);
		else
			return 0;
		A /= 10;
		

	}
	return 1;
}
vector<int> Solution::equal(vector<int> &A) {

}
int main()
{
	Solution *s = new Solution();
	return 0;
}
