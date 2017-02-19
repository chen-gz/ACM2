///*
//最少拦截系统
//*/
//#include<cstdio>  
//#include<cstring>   
//#include<iostream>
//using namespace std;
//const int INF = 30001;
//int a[1001];   
//int h[1001]; 
//int main(){
//	int n, ans;
//	while (scanf("%d", &n) != EOF){
//		ans = 0;
//		for (int i = 0; i < n; i++){
//			cin >> a[i];
//			h[i] = INF; 
//		}
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j <= ans; j++){
//				if (h[j] >= a[i]){
//					if (h[j] == INF)
//						ans++;
//					h[j] = a[i];
//					break;
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}