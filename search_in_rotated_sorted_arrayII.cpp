class Solution {
public:
    bool search(int A[], int n, int target) {
        int first = 0 ;
        int last = n;
        while(first != last)
        {
            int middle = first + (last - first) / 2;
            if(A[middle] == target)
                return true;
            if(A[first] < A[middle])
            {
                //有序序列
                if(A[first] <= target && target < A[middle])
                    last = middle;
                else
                    first = middle  + 1;
            }
            else if(A[first] > A[middle])
            {
                //后半部有序，对后半部进行处理
                if(A[middle] < target && target <= A[last - 1])
                    first = middle + 1;
                else
                    last = middle;
            }
            else
            {       //只能一步步向后走了
                    first ++;
            }
        }
        return false;
    }
};