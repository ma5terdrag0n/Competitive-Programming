template<typename T>
void insertion_sort(vector<T> &v){
	int n = v.size();
	for(int i = 0 ; i < n ; i++){
		int x = v[i];
		int j = i - 1;
		while(j >= 0 && v[j] > x){
			swap(v[j], v[j+1]);
			j--;
		}
		v[j+1] = x;
	}
}
