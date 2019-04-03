#define  _CRT_SECURE_NO_WARNINGS 1

//两个数异或：相当于每一位相加，而不考虑进位；
//两个数相与，并左移一位：相当于求得进位；
//将上述两步的结果相加

int Add(int num1, int num2) {
	while (num2 != 0){
		int sum = num1 ^ num2;
		int carray = (num1 & num2) << 1;
		num1 = sum;
		num2 = carray;
	}
	return num1;
}