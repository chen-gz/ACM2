//LIS　最大上升子序列;O(nlogn)
int LIS(const int* lis_arr, const int& lis_len) {
	const int lis_maxn = 5000;
	int lis_arr[lis_maxn];
	int f[lis_maxn];//f[i]表示d 值为i 时候的最小a值
	int d[lis_maxn];//d[i]表示以i结尾的最长递增子序列长度
	//如果数比较大，把上面的开在外面
	auto binarysearch = [](const int* f, int size, const int& a) {
							int left = 0;
							int right = size - 1;
							while (left <= right) {
								int mid = (left + right) >> 1;
								if (a>f[mid - 1] && a < f[mid]) //<,<=是关于是否严格单调
									return mid;
								else if (a<f[mid])
									right = mid - 1;
								else
									left = mid + 1;
							}
						};
	int size = 1;
	int j;
	f[0] = lis_arr[0];
	d[0] = 1;
	for (int i = 1; i<lis_len; i++) {
		if (lis_arr[i] <= f[0]) {
			j = 0;
		}
		else if (lis_arr[i]>f[size - 1])
			j = size++;
		else
			j = binarysearch(f, size, lis_arr[i]);
		f[j] = lis_arr[i];
		d[i] = j + 1;
	}
	return size;
}
