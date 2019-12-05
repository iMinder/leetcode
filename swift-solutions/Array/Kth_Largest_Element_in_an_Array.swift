
/**
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Example 1:

    Input: [3,2,1,5,6,4] and k = 2
    Output: 5
    Example 2:

    Input: [3,2,3,1,2,4,5,5,6] and k = 4
    Output: 4
    Note:
    You may assume k is always valid, 1 ≤ k ≤ array's length.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

public struct Heap<T> {
    var nodes = [T]()

    private var orderCriteria:(T, T) -> Bool

    public init(sort: @escaping(T,T) -> Bool) {
        self.orderCriteria = sort
    }

    public init(array:[T], sort: @escaping(T,T) -> Bool) {
        self.orderCriteria = sort
        self.configHeap()
    }

    private mutating func configHeap(from array: [T]) {
        nodes = array
        for i in stride(from (nodes.count / 2 - 1), to: 0, by: -1) {
            shiftDown(from: i)
        }
    }

    @inline(__always) internal func leftChildIndex(ofIndex: Int) -> Int {
        return  2 * ofIndex
    }

    @inline(__always) internal func rightChildIndex(ofIndex: Int) -> Int {
        return 2 * ofIndex + 1;
    }

    @inline(__always) internal func parentIndex(ofIndex: Int) -> Int {
        return (ofIndex - 1) / 2
    }

    internal mutating func shiftDown(from index: Int, until endIndex: Int) {
        let leftChildIndex = self.leftChildIndex(index)
        let rightChildIndex = leftChildIndex + 1
        var first = index
        if leftChildIndex < endIndex && orderCriteria(nodes[leftChildIndex], nodes[first]) {
            first = leftChildIndex
        }
        if rightChildIndex < endIndex && orderCriteria(nodes[rightChildIndex], nodes[first]) {
            first = rightChildIndex
        }
        if first == index {
            return
        }
        nodes.swapAt(index, first)
        shiftDown(first, endIndex)
    }

    internal mutating func shiftDown(from index: Int) {
        shiftDown(from: index, until: nodes.count)
    }
}

class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        guard let pivot = nums.first  else {
            fatalError("Invalie input")
        }

        let leftPart = nums.filter { $0 > pivot }
        let middlePart = nums.filter { $0 == pivot }
        let rightPart = nums.filter { $0 < pivot }
        if nums.count == middlePart.count {
            return pivot
        }
        if (leftPart.count > k - 1) {
            return findKthLargest(leftPart, k)
        } else if (leftPart.count + middlePart.count >= k ) {
            return pivot
        } else  {
            return findKthLargest(rightPart, k - leftPart.count - middlePart.count)
        }

    }
}

