 int removeDuplicates(int A[], int n) {
        // int current = A[0];
        // int count = 0;
        // for(int i = 1; i < n; i++)
        // {
        //     if(current == A[i])
        //     {
        //         count ++;
        //     }
        //     else if(count > 0)
        //     {
        //         i = i - count;
        //         for (int j = 0; j < n - count ;j++)
        //         {
        //             A[i + j] = A[i + j + count];
        //         }
                
        //         current = A[i];
        //         n -= count;
        //         count = 0;
        //     }
        //     else
        //     {
        //         current = A[i];
        //     }
        // }
        
        // //最后一个
        //  if(count > 0)
        //   {
        //       n -= count;
        //   }
        
        //借助快速排序的划分思想，记住下标
        // if (n < 1)
        // {
        //     return 0;
        // }
        
        // int index = 0;
        
        // for (int i = 1; i < n ; i++)
        // {
        //     if(A[index] != A[i])
        //     {
        //         A[++index] = A[i];
        //     }
        // }
        // return index + 1;
        
        //方法2 ： 利用STL
        return distance(A, unique(A, A + n));
        
        //方法3： 

    }