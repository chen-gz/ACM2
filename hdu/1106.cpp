//#include <cstdio>  
//#include <string>  
//#include <iostream>  
//#include <vector>  
//#include <algorithm>  
//using namespace std;
//int main(){
//	string strs;
//	while (cin >> strs)
//	{
//		int num = 0;
//		vector<int> vi;
//		int i = 0;
//		for (; i < (int)strs.size() && strs[i] == '5'; i++);
//		for (; i < (int)strs.size(); ){
//			if ('5' == strs[i])
//			{
//				vi.push_back(num);
//				num = 0;
//				for (i++; i < (int)strs.size() && strs[i] == '5'; i++);
//			}
//			else
//			{
//				num = num * 10 + (strs[i] - '0');
//				i++;
//				if (i == (int)strs.size()) vi.push_back(num); 
//			}
//		}
//		sort(vi.begin(), vi.end());
//		for (int i = 0; i < (int)vi.size() - 1; i++)
//		{
//			printf("%d ", vi[i]);
//		}
//		printf("%d\n", vi[vi.size() - 1]);
//	}
//	return 0;
//}