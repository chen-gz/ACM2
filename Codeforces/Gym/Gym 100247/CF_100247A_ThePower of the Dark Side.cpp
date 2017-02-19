//#include <iostream>
//#include <algorithm>
//using namespace std;
//typedef struct node {
//	int x, y, z, num;
//	bool flag;
//}Jedi;
//Jedi jedi[200000];
//int main(){
//	int n; cin >> n;
//	for (int i = 0; i < n; i++) {
//		int tmp[3];
//		for (int j = 0; j < 3; j++)
//			cin >> tmp[j];
//		sort(tmp, tmp + 3);
//		jedi[i].num = i + 1;
//		jedi[i].x = tmp[2];
//		jedi[i].y = tmp[1];
//		jedi[i].z = tmp[0];
//	}
//	int maxy = 0, maxz = 0;
//	for (int i = 0; i < n; i++) {
//		if (jedi[i].y > maxy)
//			maxy = jedi[i].y;
//		if (jedi[i].z > maxz)
//			maxz = jedi[i].z;
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//		if (maxy < jedi[i].x && maxz < jedi[i].y) {
//			jedi[i].flag = true;
//			ans++;
//		}
//	cout << ans << endl;
//	for (int i = 0; i < n; i++)
//		if (jedi[i].flag)
//			cout << jedi[i].num << " ";
//	return 0;
//}
