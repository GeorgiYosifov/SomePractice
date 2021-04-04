class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data

class LinkedList: 
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = Node(data=nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = Node(data=elem)
                node = node.next

    def occurings(self, node_data):
        count = 0 
        node = self.head
        while node is not None:
            if node.data == node_data:
                count += 1
            node = node.next
        return count
    
    def add_last(self, node_data):
        if self.head is None:
            self.head = node
            return
        for current_node in self:
            pass
        current_node.next = Node(node_data)
        
    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next
        
    def __repr__(self):
        for node in llist:
            print(node, end=" ")
    

llist = LinkedList(["a", "b", "c", "c",])

llist.add_last("D")
print(llist.occurings("c"))

llist.__repr__()
