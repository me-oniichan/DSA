class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null) return null;
        ListNode slow=  head;
        ListNode fast=  head;
        ListNode flag=  head;
        while(fast.next!=null && fast.next.next!=null){
            fast = fast.next.next;
            slow  = slow.next;
            while(slow!=flag){
                slow=slow.next;
                flag=flag.next;
            }
            return flag;
        }
        return null;
    }
}