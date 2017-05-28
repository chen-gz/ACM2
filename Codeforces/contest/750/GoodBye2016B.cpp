//#include<iostream>
//#include<string>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//using namespace std;
//#define N 100003
//
//int main()
//{
//	long long n;
//	cin >> n;
//	long long fuck = 0, go = 0;
//	bool flag = true;
//	for (long long i = 0; i < n; i++){
//		long long tmp;
//		scanf("%I64d", &tmp);
//		string str;
//		cin >> str;
//		if (go == 0 && str != "South")
//			flag = 0;
//		if (go == 20000 && str != "North")
//			flag = 0;
//		if (str == "North"){
//			go -= tmp;
//			if (go < 0)
//				flag = 0;
//			go = go + (tmp / 40000 + 1) * 40000;
//			go %= 40000;
//		}
//		else if (str == "South"){
//			go += tmp;
//			if (go > 20000)
//				flag = 0;
//			go %= 40000;
//		}
//		else if (str == "East"){
//			fuck += tmp;
//			fuck %= 40000;
//		}
//		else if (str == "West"){
//			fuck -= tmp;
//			fuck = fuck + (tmp / 40000 + 1) * 40000;
//			fuck %= 40000;
//		}
//	}
//	if (flag && !go)
//		cout << "YES" << endl;
//	else
//		cout<<"NO"<<endl;
//}
