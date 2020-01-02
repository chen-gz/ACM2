#include <iostream>
using namespace std;
const int max_num = 2e5 + 10;
int data[max_num];
struct node {
	int left, right;
	int sum, max_num, min_num;//线段的三个特征
	bool lazy;
	int lazy_value;
};
node tree[4 * max_num];
class segment_tree {

public:
	void print_node(int root);
	inline void update_value(int root);
	void build(int root, int left, int right);
	int query(int root, int left, int right);
	void update_one(int root, int pos, int value);
	void push_down(int root);
	void update(int root, int left, int right, int value);
};
void segment_tree::update_value(int root){
	tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
	tree[root].max_num = max(tree[root << 1].max_num, tree[root << 1 | 1].max_num);
	tree[root].min_num = min(tree[root << 1].min_num, tree[root << 1 | 1].min_num);
}
void segment_tree::print_node(int root){
	cout << "left: " << tree[root].left << " right: " << tree[root].right << endl;
	cout << "sum " << tree[root].sum << " max_num: " << tree[root].max_num << " min_num: " << tree[root].min_num << endl;
	cout << endl;
}
void segment_tree::build(int root, int left, int right){
	tree[root].left = left;//线段左端点
	tree[root].right = right;//线段端点
	if(left == right){
		tree[root].sum = data[right];//赋值,节点的值
		tree[root].max_num = data[right];
		tree[root].min_num = data[right];
		return;
	}
	build(root << 1, left, (left + right) / 2);//建立左子树
	build(root << 1 | 1, (left + right) / 2 + 1, right);//建立右子树
	update_value(root);
}

// 查询和O(lgn),lazy 更新没写
int segment_tree::query(int root, int left, int right){
	// 没有交集
	push_down(root);
	if(left > tree[root].right && right < tree[root].left){
		return 0;
	}
	if(left <= tree[root].left && right >= tree[root].right){
		return tree[root].sum;
	}
	int p1 = query(root << 1, left, right);
	int p2 = query(root << 1 | 1, left, right);
	return p1 + p2;
}

//单点更新O(lgn)
void segment_tree::update_one(int root, int pos, int value){
	//root 为树的结点序号，pos为原数组的序号,value 为pos位置的真值，不是变化值
	push_down(root);
	if(tree[root].left > pos || tree[root].right < pos)
		return;
	if(tree[root].left == tree[root].right && tree[root].left == pos){
		tree[root].sum = value;
		tree[root].max_num = tree[root].min_num = value;
		return;
	}
	if(tree[root].left == tree[root].right)
		return;
	update_one(root << 1, pos, value);
	update_one(root << 1 | 1, pos, value);
	update_value(root);
}

//向下更新子结点,更新lazy的操作
void segment_tree::push_down(int root){
	if(tree[root].lazy){
		tree[root].lazy = false;
		tree[root].sum += (tree[root].right - tree[root].left + 1) * tree[root].lazy_value;
		tree[root].max_num += tree[root].lazy_value;
		tree[root].min_num += tree[root].lazy_value;
		if(tree[root].left != tree[root].right){
			tree[root << 1].lazy = true;
			tree[root << 1].lazy_value += tree[root].lazy_value;
			tree[root << 1 | 1].lazy = true;
			tree[root << 1 | 1].lazy_value += tree[root].lazy_value;
		}
		tree[root].lazy_value = 0;
	}
}

//区间更新
//父亲结点状态比子结点新，子结点延迟更新,lazy思想， 查询时更新需要更新的结点，
void segment_tree::update(int root, int left, int right, int value){
	// root 为当前树的结点,left,right更新的区间，value变化的值
	if(tree[root].left > right || tree[root].right < left)
		return;
	if(tree[root].left >= left && tree[root].right <= right){
		tree[root].lazy = true;
		tree[root].lazy_value += value;
		return;
	}
	if(tree[root].left == tree[root].right)
		return;
	update(root << 1, left, right, value);
	update(root << 1 | 1, left, right, value);
	update_value(root);
}
int main(){
	int sum = 0;
	for(int i = 1; i <= 10; i++){
		data[i] = rand() % 20;
	}
	segment_tree seg;
	// seg.build(1, 1, int(1e4));
	seg.update(1, 1, 5, 1);
	for(int i = 1; i <= 10; i++){
		cout << data[i] << " ";
		sum += data[i];
	}
	cout << endl;
	cout << sum << endl;
	cout << endl;
	for(int i = 1; i < 20; i++){
		seg.print_node(i);
	}
	cout << endl;
}
