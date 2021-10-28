#pragma once
#include<stdlib.h>
#include<vector>
using namespace std;
inline void NEXT(const string&T, vector<int>&next) {//��ģʽ������vector,next(T.size())
	next[0] = -1;
	for (int i = 1; i < T.size(); i++) {
		int j = next[i - 1];
		while (j >= 0 && T[i - 1] != T[j]) j = next[j];//���Ƽ���
		if (j >= 0 && T[i - 1] == T[j]) next[i] = j + 1;
		else next[i] = 0;
	}
}
inline string::size_type COUNT_KMP(const string&S, const string&T) {
	//����ģʽ��T��next������T������S�еĸ���count��KMP�㷨
	//����T�ǿգ�
	vector<int>next(T.size());
	NEXT(T, next);
	string::size_type index, count = 0;
	for (index = 0; index < S.size(); ++index) {
		int pos = 0;
		string::size_type iter = index;
		while (pos < T.size() && iter < S.size()) {
			if (S[iter] == T[pos]) { ++iter; ++pos; }
			else {
				if (pos == 0) ++iter;
				else pos = next[pos - 1] + 1;
			}
		}
		if (pos == T.size() && (iter - index) == T.size()) ++count;
	}
	return count;
}

