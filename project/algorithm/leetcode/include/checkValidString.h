#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/valid-parenthesis-string/
//������  �����ŵ���Сֵ ���ֵ
//��������̰���㷨
//�ڼ���ַ����Ƿ���Чʱ������ֻ�����Ƿ� ��balance���������Ƿ����ַ���ʱ����δ��Ե������ŵ����������磬�ڼ�� ��(()())�� �Ƿ���Чʱ�������ڷ����ַ���ʱ�õ��� 1, 2, 1, 2, 1, 0 ��ƽ����̣���(�� ��1�������ţ���(�� ��2�������ţ���(()�� ʣ��һ�������ţ��������ơ�
//	���磬����������ַ���(***)����ô�ڷ���ÿ������ʱ��balance �Ŀ���ֵ�� '(' ��Ӧ[1], '(*' ��Ӧ[0, 1, 2], '(**' ��Ӧ[0, 1, 2, 3], '(***' ��Ӧ[0, 1, 2, 3, 4], '(***)'��Ӧ[0, 1, 2, 3]��(ָ���ǿ��ܵ�δƥ�������������)
//	���⣬���ǿ���֤����Щ״̬�����γ�һ�����������䡣��ˣ�����ֻ��Ҫ֪�������������ұ߽硣Ҳ����˵�����ǽ��������������м�״̬����Ϊ[lo, hi] = [1, 1], [0, 2], [0, 3], [0, 4], [0, 3]
//
//	���ߣ�LeetCode
//	���ӣ�https ://leetcode-cn.com/problems/valid-parenthesis-string/solution/you-xiao-de-gua-hao-zi-fu-chuan-by-leetcode/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
bool checkValidString(string s) {
	int min = 0, max = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			min++;
			max++;
		}
		else if (s[i] == ')')
		{
			min--;			
			max--;
			if (max < 0)
			{
				return false;
			}
			min = min >= 0 ? min : 0;
		}
		else
		{
			min--;
			max++;
			min = min >= 0 ? min : 0;
		}
	}

	if (min == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkValidStringIndex(string& s, int index, stack<char>& sta)
{
	if (s.size() - index < sta.size())
	{
		return false;
	}
	if (index == s.size())
	{
		if (sta.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int i = index;
	if (s[i] == ')')
	{
		if (!sta.empty())
		{
			//if (sta.top() == '(')
			{
				sta.pop();
				if (checkValidStringIndex(s, index + 1, sta))
				{
					return true;
				}
				sta.push('(');
			}
			//else
			//{
			//	sta.push(s[i]);
			//	if (checkValidStringIndex(s, index + 1, sta))
			//	{
			//		return true;
			//	}
			//	sta.pop();
			//}
		}
		//else
		//{
		//	return false;
		//}

	}
	else if (s[i] == '*')
	{
		if (checkValidStringIndex(s, index + 1, sta))
		{
			return true;
		}
		sta.push('(');
		if (checkValidStringIndex(s, index + 1, sta))
		{
			return true;
		}
		sta.pop();

		if (!sta.empty())
		{
			//if (sta.top() == '(')
			{
				sta.pop();
				if (checkValidStringIndex(s, index + 1, sta))
				{
					return true;
				}
				sta.push('(');
			}
			//else
			//{
			//	sta.push(')');
			//	if (checkValidStringIndex(s, index + 1, sta))
			//	{
			//		return true;
			//	}
			//	sta.pop();
			//}
		}
	}
	else
	{
		sta.push(s[i]);
		if (checkValidStringIndex(s, index + 1, sta))
		{
			return true;
		}
		sta.pop();
	}

	return false;
}

//ջ+���� ����֦��ʱ����֦����ͨ��
bool checkValidString2(string s) {
	stack<char> sta;
	for (int i = 0; i < s.size(); i++)
	{
		if (!sta.empty()&& s[i] == ')' && sta.top() == '(')
		{
			sta.pop();
		}
		else
		{
			sta.push(s[i]);
		}
	}
	string ss(sta.size(),'(');
	int i = sta.size();
	while (!sta.empty())
	{
		ss[i - 1] = sta.top();
		sta.pop();
		i--;
	}
	return checkValidStringIndex(ss,0,sta);
}

bool checkValidString3(string s) {
	int dp1[101],dp2[101];
	dp1[0] = 0;
	dp2[0] = 0;
	for (int j = 0; j < s.size(); j++)
	{
		int i = j + 1;
		if (s[j] == '(')
		{
			dp1[i] = dp1[i - 1] + 1;
			dp2[i] = dp2[i - 1] + 1;
		}
		else if (s[j] == ')')
		{
			dp1[i] = dp1[i - 1] - 1 >= 0? dp1[i - 1] - 1:0;
			dp2[i] = dp2[i - 1] - 1;
			if (dp2[i] < 0)
			{
				return false;
			}
		}
		else
		{
			dp1[i] = dp1[i - 1] - 1 >= 0 ? dp1[i - 1] - 1 : 0;
			dp2[i] = dp2[i - 1] + 1;
		}
	}
	return dp1[s.size()] == 0;
}
//dp
bool checkValidString4(string s) {
	bool dp[101][101] = {false};
	memset(dp, false, 101 * 101 * sizeof(bool));
	dp[0][0] = true;
	dp[1][0] = true;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] == '(')
			{
				dp[i + 1][j + 1] = false;
				continue;
			}

			if (s[j] == '*')
			{
				if ((i + 1 <= j && dp[i+1][j]) || i + 1 > j)
				{
					dp[i + 1][j + 1] = true;
					continue;
				}
			}
			dp[i + 1][j + 1] = false;
			for (int k = i; k < j; k++)
			{
				if ((s[k] == '('||s[k] == '*') && ((i + 1 <= k && dp[i + 1][k]) || i + 1 > k) && ((k+2 <= j && dp[k + 2][j]) || k + 2 > j))
				{
					dp[i + 1][j + 1] = true;
					break;
				}
			}
		}
	}

	return dp[1][s.size()];
}
//stackʹ������ջ��һ��������¼ '('��һ��������¼ ''��˼������Ȱ� '' �ݴ���������Ҫ�����ж����ǿո�'(' �� ')'���ȵ�Ҫ�õ�ʱ���ٰ�����������
bool checkValidString5(string s) 
{
	stack<int> sta1;
	stack<int> sta2;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			sta1.push(i);
		}
		else if (s[i] == '*')
		{
			sta2.push(i);
		}
		else
		{
			if (!sta1.empty())
			{
				sta1.pop();
			}
			else if (!sta2.empty())
			{
				sta2.pop();
			}
			else
			{
				return false;
			}
		}
	}
	while (!sta1.empty() && !sta2.empty())
	{
		if (sta1.top() < sta2.top())
		{
			sta1.pop();
			sta2.pop();
		}
		else
		{
			return false;
		}
	}
	if (sta1.empty())
	{
		return true;
	}
	return false;
}

