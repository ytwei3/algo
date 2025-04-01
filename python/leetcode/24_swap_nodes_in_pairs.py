class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapPairs(head):
    # Dummy node to simplify edge cases
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while prev.next and prev.next.next:
        # Nodes to be swapped
        first = prev.next
        second = first.next

        # Swapping
        # prev.next = second
        first.next = second.next
        second.next = first

        # Move to the next pair
        prev = first

    return dummy.next

def print_list(head):
    """Helper function to convert linked list to a Python list for easy testing."""
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

if __name__ == "__main__":
    # Create a linked list: 1 -> 2 -> 3 -> 4
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node1.next = node2
    node2.next = node3
    node3.next = node4

    # Swap pairs
    swapped_head = swapPairs(node1)

    # Print the swapped list
    print(print_list(swapped_head))  # Output: [2, 1, 4, 3]