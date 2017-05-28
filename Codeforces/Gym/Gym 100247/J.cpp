//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<vector>
//#include<string>
//#include<queue>
//using namespace std;
//#define readn(x) scanf("%d", &x)
//#define reads(x) scanf("%s",x)
//#define print(x) printf("%d ",x)
//typedef struct node {
//	int data;
//	struct node *f;
//	struct node *n;
//}NODE;
//int main() {
//	int n; readn(n);
//	int p; readn(p);
//	int tmp;
//	NODE *head = (NODE*)malloc(sizeof(NODE));
//	NODE *cur = head;
//	for (int i = 0; i < n; i++) {
//		readn(tmp);
//		NODE * temp = (NODE*)malloc(sizeof(NODE));
//		cur->n = temp;
//		temp->f = cur;
//		temp->data = tmp;
//		cur = cur->n;
//		cur->n = NULL;
//	}
//	cur = head;
//	for (int i = 0; i < p; i++) {
//		cur = cur->n;
//	}
//	int t; readn(t);
//	char s[100];
//	while (t--) {
//		scanf("%s", s);
//		if (!strcmp(s, "print")) {
//			printf("%d\n", cur->data);
//		}
//		if (!strcmp(s, "moveRight")) {
//			if (cur->n != NULL)
//				cur = cur->n;
//		}
//		if (!strcmp(s, "moveLeft")) {
//			if (cur->f != head)
//				cur = cur->f;
//		}
//		if (!strcmp(s, "insertLeft")) {
//			int tmp; readn(tmp);
//			NODE *temp = (NODE*)malloc(sizeof(NODE));
//			temp->data = tmp;
//			NODE *bef = cur->f;
//			bef->n = temp;
//			temp->f = bef;
//			temp->n = cur;
//			cur->f = temp;
//		}
//		if (!strcmp(s, "insertRight")) {
//			int tmp; readn(tmp);
//			NODE *temp = (NODE*)malloc(sizeof(NODE));
//			temp->data = tmp;
//			if (cur->n != NULL) {
//				temp->data = tmp;
//				NODE *next = cur->n;
//				next->f = temp;
//				temp->n = next;
//				temp->f = cur;
//				cur->n = temp;
//
//			}
//			else {
//
//
//				cur->n = temp;
//				temp -> f = cur;
//				temp->n = NULL;
//			}
//			
//
//		}
//	}
//	return 0;
//}