import Foundation

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map = [Int: Int]()
        for (index, value) in nums.enumerated() {
            if let previous = map[target - value] {
                return[previous, index]
            } else {
                map[value] = index
            }
        }
        return []
    }
}

let soluton = Solution()
print(soluton.twoSum([2,7,11,15], 9))

