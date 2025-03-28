from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
    
        # Move first pointer N+1 steps ahead
        for _ in range(n + 1):
            first = first.next
    
        # Move both pointers until first reaches the end
        while first:
            first = first.next
            second = second.next
    
        # Remove the N-th node from the end
        second.next = second.next.next
    
        return dummy.next

def print_list(head: Optional[ListNode]) -> list:
    """Helper function to convert linked list to a Python list for easy testing."""
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

if __name__ == "__main__":
    # Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    node5 = ListNode(5)
    node4 = ListNode(4, node5)
    node3 = ListNode(3, node4)
    node2 = ListNode(2, node3)
    node1 = ListNode(1, node2)

    solution = Solution()

    # Test case: Remove the 2nd node from the end
    updated_head = solution.removeNthFromEnd(node1, 2)

    # Print the updated linked list
    print(print_list(updated_head))  # Expected output: [1, 2, 3, 5]