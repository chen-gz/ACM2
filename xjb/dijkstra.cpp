////��Դ���·��dijkstra�㷨��ʹ�����ȶ����Ż�
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<vector>
//#include<cstring>
//using namespace std;
//const int MAX_V = 200000 + 1;//���ߵĸ���
//#define INT_MAX 2147483647
//struct edge
//{
//	int to, cost;
//	edge(int to, int cost) {
//		this->to = to;
//		this->cost = cost;
//	}
//};
//typedef pair<int, int> P;
////int V;//�ߵ�ʵ�ʸ���
//// ������ʼΪ0 �������� ��1��ʼ���㣬��V��Ҫ+1��
////int d[MAX_V];//��̾���
////vector<edge> G[MAX_V]; //�ĸ�ʽ��
//void dijkstra(int start, vector<edge> G[], int V, int d[]) {
//	//����˵��
//	//start ��� G[] ͼ�� V ������� d[] Ϊ���صĽ��
//	bool used[MAX_V];
//	priority_queue<P, vector<P>, greater<P> > que;
//	memset(used, false, sizeof(used));
//	fill(d, d + V, INT_MAX);
//	d[start] = 0;
//	que.push(P(0, start));
//	while (!que.empty()) {
//		P p = que.top();
//		que.pop();
//		int v = p.second;
//		if (d[v] < p.first || used[v])
//			continue;
//		used[v] = true;
//		for (int i = 0; i < G[v].size(); i++) {
//			edge e = G[v][i];
//			if (d[e.to] > d[v] + e.cost) {
//				d[e.to] = d[v] + e.cost;
//				que.push(P(d[e.to], e.to));
//			}
//		}
//	}
//}