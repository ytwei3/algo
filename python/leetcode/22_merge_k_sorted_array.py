import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge_k_lists(lists):
    min_heap = []
    
    # Initialize the heap with the head of each list
    for i, l in enumerate(lists):
        print(f"Adding list {i} head with value {l.val} to the heap")
        if l:
            heapq.heappush(min_heap, (l.val, i, l))
    
    # Create a dummy head for the merged list
    dummy = ListNode(0)
    current = dummy
    
    while min_heap:
        # Get the smallest node
        val, idx, node = heapq.heappop(min_heap)
        current.next = node  # Add it to the merged list
        current = current.next  # Move to the next
        
        # If there is a next node, push it into the heap
        if node.next:
            heapq.heappush(min_heap, (node.next.val, idx, node.next))
    
    return dummy.next  # Return the merged list, skipping the dummy head

def print_list(head):
    """Helper function to convert linked list to a Python list for easy testing."""
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

if __name__ == "__main__":
    # Create three linked lists: 1 -> 4 -> 5, 1 -> 3 -> 4, and 2 -> 6
    node1_1 = ListNode(1)
    node1_2 = ListNode(4)
    node1_3 = ListNode(5)
    node1_1.next = node1_2
    node1_2.next = node1_3

    node2_1 = ListNode(1)
    node2_2 = ListNode(3)
    node2_3 = ListNode(4)
    node2_1.next = node2_2
    node2_2.next = node2_3

    node3_1 = ListNode(2)
    node3_2 = ListNode(6)
    node3_1.next = node3_2

    lists = [node1_1, node2_1, node3_1]

    # Test case: Merge the k linked lists
    merged_head = merge_k_lists(lists)

    # Print the merged linked list
    print(print_list(merged_head))  # Expected output: [1, 1, 2, 3, 4, 4, 5, 6]