// Merge Sort - O(nlogn)

template<typename T> 
void merge(vector<T> &v, int lo, int hi){
	int mid = (lo + hi) / 2;
	int start = lo;
	vector<T> tmp;
	int cnt = mid+1;
	while(lo <= mid && cnt <= hi){
		if(v[lo] < v[cnt]){
			tmp.pb(v[lo++]);
		}else{
			tmp.pb(v[cnt++]);
		}
	}
	while(cnt <= hi)tmp.pb(v[cnt++]);
	while(lo <= mid)tmp.pb(v[lo++]);
	for(int i  = 0 ; i < tmp.size() ; i++){
		v[start++] = tmp[i];
	}
}


template<typename T>
void merge_sort(vector<T> &v, int lo, int hi){
	int mid = (lo + hi) / 2;
	if(lo < hi){
		merge_sort(v, lo, mid);
		merge_sort(v, mid+1, hi);
		merge(v, lo, hi);
	}
}
