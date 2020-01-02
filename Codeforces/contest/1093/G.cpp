#include <iostream>
using namespace std;
const int max_num = 2e5 + 10;
int data[max_num][7];
int binary[1 << 5 | 1][7];
struct node {
	int left, right;
	int max_num, min_num;//线段的三个特征
};
node tree[int(8e5 + 20)][1 << 5 | 1];
int cnt;
int k;
class segment_tree {
public:
	inline void update_value(int root);
	void build(int root, int left, int right);
	void query(int root, int left, int right, int & max_num, int & min_num);
	void update_one(int root, int pos);
};
void segment_tree::update_value(int root){
	tree[root][cnt].max_num = max(tree[root << 1][cnt].max_num, tree[root << 1 | 1][cnt].max_num);
	tree[root][cnt].min_num = min(tree[root << 1][cnt].min_num, tree[root << 1 | 1][cnt].min_num);
}
void segment_tree::build(int root, int left, int right){
	tree[root][cnt].left = left;//线段左端点
	tree[root][cnt].right = right;//线段端点
	if(left == right){
		int tmp = 0;
		for(int i = 0; i < k; i++){
			tmp += binary[cnt][i] * data[right][i];
			tmp -= (1 - binary[cnt][i]) * data[right][i];
		}
		tree[root][cnt].max_num = tree[root][cnt].min_num = tmp;
		return;
	}
	build(root << 1, left, (left + right) / 2);//建立左子树
	build(root << 1 | 1, (left + right) / 2 + 1, right);//建立右子树
	update_value(root);
}

// 查询和O(lgn),lazy 更新没写
void segment_tree::query(int root, int left, int right, int & max_num, int & min_num){
	// 没有交集
	// push_down(root);
	if(left > tree[root][cnt].right || right < tree[root][cnt].left){
		return;
	}
	if(left <= tree[root][cnt].left && right >= tree[root][cnt].right) {
		max_num = max(tree[root][cnt].max_num, max_num);
		min_num = min(tree[root][cnt].min_num, min_num);
		return;
	}
	if(tree[root][cnt].left == tree[root][cnt].right)
		return;
	query(root << 1, left, right, max_num, min_num);
	query(root << 1 | 1, left, right, max_num, min_num);
}

//单点更新O(lgn)
void segment_tree::update_one(int root, int pos){
	//root 为树的结点序号，pos为原数组的序号,value 为pos位置的真值，不是变化值
	// push_down(root);
	if(tree[root][cnt].left > pos || tree[root][cnt].right < pos)
		return;

	if(tree[root][cnt].left == tree[root][cnt].right && tree[root][cnt].left == pos){
		int tmp = 0;
		for(int i = 0; i < k; i++){
			tmp += binary[cnt][i] * data[pos][i];
			tmp -= (1 - binary[cnt][i]) * data[pos][i];
		}
		tree[root][cnt].max_num = tree[root][cnt].min_num = tmp;
		return;
	}

	update_one(root << 1, pos);
	update_one(root << 1 | 1, pos);
	update_value(root);
}


int main(){
	for(int i = 0; i < 1 << 5; i++){
		int tmp  = i;
		int idx = 0;
		while(tmp > 0){
			binary[i][idx] = tmp & 1;
			tmp >>= 1;
			idx++;
		}
	}
	cnt = 0;
	int n; cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			cin >> data[i][j];
		}
	}
	int q; cin >> q;
	segment_tree seg;
	for(cnt=0;cnt< 1<<k;cnt++){
		seg.build(1, 1, n);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int pos; cin >> pos;
			for(int i = 0; i < k; i++){
				cin >> data[pos][i];
			}
			for(cnt =0 ;cnt< 1<<k;cnt++)
				seg.update_one(1, pos);
		}
		if(type == 2){
			int l, r; cin >> l >> r;
			int ans = -999999;
			for(cnt = 0; cnt < 1 << k; cnt++){
				int max_ans = -0xfffffff, min_ans = 0xfffffff;
				seg.query(1, l, r, max_ans, min_ans);
				ans = max(ans, max_ans - min_ans);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
