class Solution {
public:
	int search(int A[], int n, int target) {

		// if(A[0] == target)
		//     return 0;
		// else if(A[n - 1] == target)
		//     return n - 1;
		// else if (n < 3)
		//     return -1;

		// //顺序数组
		// if(A[0] < A[n - 1])
		// {
		//     if(target < A[0] || target > A[n - 1])
		//         return -1;
		//     return binary_search(A, 0 , n -1, target);
		// }
		// else 
		// {
		//     //存在逆序的情况
		//     int middle = (n - 1) / 2;
		//     if(A[middle] == target)
		//         return middle;
		//     //对其中满足条件的一半执行查找
		//     if(A[middle] < A[n - 1])
		//     {
		//         //后半部是有序的
		//         if(target >= A[middle] && target <= A[n - 1])
		//             return binary_search(A, middle, n - 1, target);
		//         else 
		//             return search(A, middle, target);
		//     }
		//     else
		//     {
		//         if(target >= A[0] &&  target <= A[middle - 1])
		//             return binary_search(A, 0, middle - 1, target);
		//         else
		//             return middle + search(A+middle, n - middle, target);
		//     }
		int first = 0;
		int last = n;
		while (first != last)
		{
			int middle = first + (last - first) / 2;
			if (A[middle] == target)
				return middle;
			if (A[first] <= A[middle])
			{
				if (A[first] <= target && target < A[middle])
					last = middle;
				else
					first = middle + 1;
			}
			else
			{
				if (A[middle + 1] <= target && target <= A[last - 1])
					first = middle + 1;
				else
					last = middle;
			}
		}
		return -1;
	}
	// private:
	//     int binary_search(int A[], int begin, int end, int target)
	//     {
	//         if(begin <= end)
	//         {
	//             int middle = begin + (end - begin) / 2;
	//             if(A[middle] == target)
	//                 return middle;
	//             else if(A[middle] > target)
	//                 return binary_search(A, begin, middle -1, target);
	//             else 
	//                 return binary_search(A, middle+1, end, target);
	//         }
	//         return -1;
	//     }
};