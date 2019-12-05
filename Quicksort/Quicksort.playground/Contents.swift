//import UIKit
//
//var str = "Hello, playground"
//
////- partition
//func quicksort<T :Comparable> (_ array:[T]) -> [T]{
//    guard array.count > 0 else {
//        return [];
//    }
//    let p
//}
////- sort
public class Interval {
       public var start: Int
       public var end: Int
       public init(_ start: Int, _ end: Int) {
             self.start = start
                 self.end = end
           }
     }
class Solution {
    func merge(_ intervals: [Interval]) -> [Interval] {
        guard intervals.count > 1 else {
            return intervals
        }
        var ordered = [Interval]()
        if let first = intervals.first {
            ordered.append(first)
        }
        for interval in intervals {
            if let last = ordered.last{
                if last.end >= interval.start {
                    ordered.last?.end = interval.end
                } else {
                    ordered.append(interval)
                }
            }
        }
        return ordered
    }
}
