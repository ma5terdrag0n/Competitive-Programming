// Recursive Bubble sort - O(n*n) - It's Bullshit

template<typename T>
void bubble_sort(vector<T> &v, int n = 0){
	if(n == v.size()-1)return;
	for(int i = 0 ;i < v.size() - n - 1; i++){
		if(v[i] > v[i+1])
		swap(v[i], v[i+1]);
	}
	bubble_sort(v, n+1);
}
