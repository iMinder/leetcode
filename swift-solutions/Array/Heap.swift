public struct Heap<T> {
    var nodes = [T]()

    private var orderCriteria:(T, T) -> Bool

    public init(sort: @escaping(T,T) -> Bool) {
        self.orderCriteria = sort
    }

    public init(array:[T], sort: @escaping(T,T) -> Bool) {
        self.nodes = array
        self.orderCriteria = sort
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
