vector<int> twoSum(vector<int> &numbers, int target) {
        // std::multimap<int, int> mapIndex;
        // for (int i = 0; i < numbers.size(); i++)
        //     mapIndex.insert(make_pair(numbers[i], i));
            
    //     vector<int> sortedArr(numbers);
    //     std::sort(sortedArr.begin(), sortedArr.end());
    //     int i = 0;
    //     int j = sortedArr.size() - 1;
    //     while(i < j)
    //     {
    //         if(sortedArr[i] + sortedArr[j] == target)
    //         {
    //             vector<int> ret;
    //             int index1 =0,index2 = 0;
    //             for(int k = 0; k < numbers.size();k++)
    //             {
    //                 if(sortedArr[i] == numbers[k])
    //                 {
    //                     index1=k;
    //                     break;
    //                 }
                        
    //             }
    //             for(int k = numbers.size() -1; k != 0; k--)
    //             {
    //                 if(sortedArr[j] == numbers[k])
    //                 {
    //                     index2 = k;
    //                     break;
    //                 }
    //             }
                
    //             if(index1 > index2)
    //                 std::swap(index1,index2);
    //             ret.push_back(index1+1);
    //             ret.push_back(index2+1);
                
    //             // if(sortedArr[i] != sortedArr[j])
    //             // {
    //             //     int index1 = mapIndex.find(sortedArr[i])->second;
    //             //     int index2 = mapIndex.find(sortedArr[j])->second;
    //             //     if(index1 > index2)
    //             //         std::swap(index1, index2);
    //             //     ret.push_back(index1+1);
    //             //     ret.push_back(index2+1);
    //             // }
    //             // else
    //             // {
    //             //     auto iter = mapIndex.find(sortedArr[i]);
                    
    //             //     int index1 = iter->second;
    //             //     iter++;
    //             //     int index2 = iter->second;
    //             //     if(index1 > index2)
    //             //         std::swap(index1, index2);
    //             //     ret.push_back(index1+1);
    //             //     ret.push_back(index2+1);
    //             // }
    //             return ret;
    //         }
    //         else if (sortedArr[i] + sortedArr[j] < target)
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j--;
    //         }
            
    //     }
    //     vector<int> vet(2,-1);
    //   return   vet;
    
        // unordered_map<int, int> mapping;
        // vector<int> result;
        // for (int i = 0; i < numbers.size(); i++)
        // {
        //     mapping[numbers[i]] = i;
        // }
        // for (int i = 0; i < numbers.size(); i++)
        // {
        //     const int gap = target - numbers[i];
        //     if (mapping.find(gap) != mapping.end() && mapping[gap] > i)
        //     {
        //         result.push_back(i+1);
        //         result.push_back(mapping[gap] + 1);
        //         break;
        //     }
        // }
        // return result;
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++)
        {
            if(m.find(numbers[i]) != m.end())
            {
                result.push_back(m[numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
            else
            {
                m[target - numbers[i]] = i;
            }
        }
        return result;
    }