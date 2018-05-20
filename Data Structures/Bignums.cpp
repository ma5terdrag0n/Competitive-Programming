#include<bits/stdc++.h>

using namespace std;

void print(std::vector<int> c)
{
	reverse(c.begin(), c.end());
	for(int i = 0 ; i < c.size() ; i ++){
		cout << c[i];
	}
	cout << endl;
}

void addBignums(vector<int> a, vector<int> b, vector<int>& c){
    // a and b are given 2 bignums in the format explained in the article
    // and c is the vector which stores the result of addition of a and b.
    // We assume that number of digits in a and b are same.
    // If a = 0012 and b = 1223, then our array a and b will look like
    // a[] = {2,1,0,0} and b[] = {3,2,2,1}
    int carry = 0;
    for(int i = 0 ; i < a.size() ; i++){
        int digit = a[i] + b[i] + carry;
        carry = digit / 10;
        c.push_back(digit % 10);
    }
    if(carry != 0){
        c.push_back(carry);
    }
}

void makeEqualNumberOfDigits(vector<int> & a, vector<int> & b){
	while(a.size() < b.size()){
		a.push_back(0);
	}
	while(b.size() < a.size()){
		b.push_back(0);
	}
}

void multiplyBignums(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c){
	vector<int> tmp;
	vector<int> tmp2;
	int numberOfZeroesToPushInTmp = 0;
	for(int i = 0 ; i < a.size() ; i++){
		int key = a[i];
		// Push Required zeroes in tmp before multiplying a single
		// digit number "key" with b[].
		tmp.clear();   // making tmp empty initially
		for(int j = 0 ; j < numberOfZeroesToPushInTmp ; j++){
			tmp.push_back(0);
		}
		numberOfZeroesToPushInTmp++;
		int carry = 0; // initially
		for(int j = 0 ; j < b.size() ; j++){
			int digit = key * b[j] + carry;
			carry = digit / 10;
			tmp.push_back(digit % 10);
		}
		if(carry!=0){
			tmp.push_back(carry);
		}
		// add tmp and carry
		makeEqualNumberOfDigits(c, tmp);
		tmp2.clear();
		addBignums(c, tmp, tmp2); // adding c and tmp and storing result in tmp2
		c = tmp2;
	}
}

int main(){
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	std::vector<int> c;
	c.clear();
	addBignums(a, b, c);
	print(c); // print result of addition of 321 + 321 = 642

	c.clear();
	multiplyBignums(a, b, c);
	print(c); // print result of 321 * 321 = 103041
}
