#[derive(Debug)]
struct ListNode {
    value: i32,
    next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(value: i32) -> Self {
        ListNode { value, next: None }
    }
}

fn reverse_linked_list_iterative(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut prev = None;
    let mut current = head;

    while let Some(mut node) = current {
        current = node.next.take(); // Move to the next node
        node.next = prev; // Reverse the link
        prev = Some(node); // Move prev to the current node
    }

    prev // New head of the reversed list
}

fn main() {
    // Create a linked list: 1 -> 2 -> 3
    let node3 = Box::new(ListNode::new(3));
    let mut node2 = Box::new(ListNode::new(2));
    node2.next = Some(node3);
    let mut node1 = Box::new(ListNode::new(1));
    node1.next = Some(node2);

    let head = Some(node1);

    // Reverse the linked list
    let reversed_head = reverse_linked_list_iterative(head);

    // Print the reversed linked list
    println!("{:?}", reversed_head);
}
