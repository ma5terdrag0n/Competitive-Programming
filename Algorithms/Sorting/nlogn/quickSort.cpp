// QuickSort - O(nlogn)
// PIVOT BASED ALGORITHM

template<typename T> 
int partition(vector<T> &v, int lo, int hi){
	int p = v[hi];
	int last = hi;
	int j = lo-1;
	int pos;
	for(int i = lo; i <= hi-1; i++){
		if(v[i] <= p){
			j++;
			swap(v[i], v[j]);
		}
	}
	swap(v[j+1], v[hi]);
	return j+1;
}


template<typename T>
void quick_sort(vector<T> &v, int lo, int hi){
	int mid = (lo + hi) / 2;
	if(lo < hi){
		int p = partition(v, lo, hi);
		quick_sort(v, lo, p-1);
		quick_sort(v, p+1, hi);
	}
}
