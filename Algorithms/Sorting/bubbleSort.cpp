// Bubble Sort - O(n*n)

template<typename T>
void bubble_sort(vector<T> &v){
	int n = v.size();
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = 0 ; j < n - i - 1 ;  j++){
			if(v[j] > v[j+1])
				swap(v[j], v[j+1]);
		}
	}
}
