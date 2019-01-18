/**
 * Definition for singly-linked list.
 */

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

//class Solution {
//    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
//        var remainder: Int = 0
//        var l1Cusor: ListNode? = l1
//        var l2Cusor: ListNode? = l2
//        let startNode = ListNode(0)
//        var cusor:ListNode? = ListNode(0)
//        startNode.next = cusor
//        while(true) {
//            guard let currentL1 = l1Cusor, let currentL2 = l2Cusor else {
//                break
//            }
//            cusor?.next = ListNode((currentL1.val + currentL2.val + remainder) % 10)
//            remainder = (currentL1.val + currentL2.val + remainder) / 10
//            l1Cusor = l1Cusor?.next
//            l2Cusor = l2Cusor?.next
//            cusor = cusor?.next
//        }
//        while(true) {
//            guard let currentL1 = l1Cusor else {
//                break
//            }
//            cusor?.next = ListNode((currentL1.val + remainder) % 10)
//            remainder = (currentL1.val + remainder) / 10
//            cusor = cusor?.next
//            l1Cusor = l1Cusor?.next
//        }
//
//        while(true) {
//            guard let currentL2 = l2Cusor else {
//                break
//            }
//            cusor?.next = ListNode((currentL2.val + remainder) % 10)
//            remainder = (currentL2.val + remainder) / 10
//            cusor = cusor?.next
//            l2Cusor = l2Cusor?.next
//        }
//
//        if remainder != 0 {
//            cusor?.next = ListNode(remainder)
//        }
//
//        return startNode.next?.next
//    }
//}
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var c1: ListNode? = l1
        var c2: ListNode? = l2
        if c1==nil
        {return c2!}
        if c2==nil
        {return c1!}
        let sentinel = ListNode(0)
        var d: ListNode?  = sentinel;
        var sum:Int = 0
        while (c1 != nil || c2 != nil) {
            sum /= 10
            if c1 != nil {
                sum += c1!.val
                c1 = c1!.next
            }
            if c2 != nil {
                sum += c2!.val
                c2 = c2!.next
            }
            d!.next = ListNode(sum % 10)
            d = d!.next;
        }
        
        if sum / 10 == 1
        {
            d!.next = ListNode(1)
        }
        return sentinel.next
    }
}
