class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self,data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            return
        
        current_node = self.head

        while current_node.next:
            current_node = current_node.next

        current_node.next = new_node
        return

    def length(self):
        if self.head == None:
            return 0

        current_node = self.head
        total = 0

        while current_node:
            total += 1
            current_node = current_node.next
        
        return total

    def to_list(self): # transform the linked list into an array
        node_data = []
        current_node = self.head

        while current_node:
            node_data.append(current_node.data)
            current_node = current_node.next
        
        return node_data

    def get(self, index):
        if index >= self.length() or index < 0:
            print("Error: Index out of range")
            return None
        current_idx = 0
        current_node = self.head
        while current_node != None:
            if current_idx == index:
                return current_node.data
            current_node = current_node.next
            current_idx += 1

    def display(self): # show the linked list elements.
        contents = self.head

        if contents is None:
            print("Empty linked list")
        
        while contents:
            print(contents.data)
            contents = contents.next

        print("---------------")

    def reverse_linkedList(self):
        previous_node = None
        current_node = self.head
        while current_node != None:
            next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = next
        self.head = previous_node

    # TO DO:
    # def search_items(self, value):

    # def remove_at_start():

    # def remove_at_end():

# Test
my_list = LinkedList()
my_list.display()

my_list.append(3)
my_list.append(7)
my_list.append(2)
my_list.append(1)

my_list.display()

print("Total number of elements are: " + str(my_list.length()))
print(my_list.to_list())

print("-----------")
my_list.reverse_linkedList()
my_list.display()


# my_list.search_item(7)
# my_list.search_item(77)

# my_list.remove_at_start()
# my_list.display()

# my_list.remove_at_end()
# my_list.display()

# my_list.insert_at_start(1)
# my_list.display()

# my_list.insert_at_end(3)
# my_list.display()

# my_list.remove_element_by_value(3)
# my_list.display()

# my_list.insert_at_index(2, 88)
# my_list.display()