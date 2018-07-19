// Sorting algorithm O(n*n)

template<typename T>
void selection_sort(vector<T> &v){
	int n = v.size();
	for(int i = 0 ; i < n-1 ; i++){
		T mini = v[i];
		int idx = i; 
		for(int j = i; j < n ; j ++){
			if(mini > v[j]){
				mini = v[j];
				idx = j;
			}
		}
		swap(v[i], v[idx]);
	}
}
