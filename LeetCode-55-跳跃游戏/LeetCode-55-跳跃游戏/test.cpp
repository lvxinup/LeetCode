#define  _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int reach = 0;
		for (int i = 0; i<nums.size(); i++){
			if (reach < i || reach >= nums.size() - 1)
				break;
			reach = max(reach, i + nums[i]);
		}
		return reach >= nums.size() - 1 ? true : false;
	}
};

/*
class Solution {
public:
bool canJump(vector<int>& nums) {
vector<bool> output(nums.size(),false);
output[0] = true;
for(int i = 0;i<nums.size();i++){
if(output[i]){  //能到达当前位置时进入判断
int j = 1;
while(j <= nums[i] && (i+j<nums.size())){
output[i+j] = true;
j++;
}
}
else    //不能到达当前位置时，跳出循环
break;
}
return output[nums.size()-1];
}
};
*/