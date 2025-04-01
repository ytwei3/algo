from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = curr = ListNode(0)

        while list1 and list2:
            print(f"Comparing {list1.val} and {list2.val}")
            if list1.val < list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        
        while list1:
            curr.next = list1
            list1 = list1.next
            curr = curr.next
            
        while list2:
            curr.next = list2
            list2 = list2.next
            curr = curr.next
        
        return curr

def print_list(head: Optional[ListNode]) -> list:
    """Helper function to convert linked list to a Python list for easy testing."""
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

if __name__ == "__main__":
    # Create two linked lists: 1 -> 2 -> 4 and 1 -> 3 -> 4
    node1_1 = ListNode(1)
    node1_2 = ListNode(2)
    node1_3 = ListNode(4)
    node1_1.next = node1_2
    node1_2.next = node1_3

    node2_1 = ListNode(1)
    node2_2 = ListNode(3)
    node2_3 = ListNode(4)
    node2_1.next = node2_2
    node2_2.next = node2_3

    solution = Solution()

    # Test case: Merge the two linked lists
    merged_head = solution.mergeTwoLists(node1_1, node2_1)

    # Print the merged linked list
    print(print_list(merged_head))  # Expected output: [1, 1, 2, 3, 4, 4]