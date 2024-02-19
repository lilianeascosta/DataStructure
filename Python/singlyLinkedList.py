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
                return current_node
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

    def search_item(self, value):
        if self.head == None:
            print("Empty Linked List")

        found = False
        current_node = self.head
        
        while found != True:
            if current_node.data == value:
                found = True
                return True
            current_node = current_node.next
            if (current_node == None) and (found == False):
                print(value, " wasn't found inside the Linked List.")
                return False

    def remove_at_start(self):
        if self.head == None:
            print("Error: linked list empty")
            return
        
        if self.get(1) == None: # there is only one element inside the list
            self.head = None

        new_first = self.get(1)
        self.head = new_first
        
        return

    def remove_at_end(self):
        if self.head == None:
            print("Error: linked list empty")
            return
        if self.length() == 1: # há apenas um elemento na lista
            self.remove_at_start()

        new_last = self.get(self.length() - 2)
        new_last.next = None
        return

    def insert_at_start(self, value):
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            return
        
        first_node = self.get(0) # to take the first node before the update

        self.head = new_node # making the head to point at the new_node, the new first one
        self.head.next = first_node # making the new first to the old first.

        return

    def insert_at_end(self, value):
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            return
        
        current_node = self.head

        while current_node.next:
            current_node = current_node.next

        current_node.next = new_node
        return

    def remove_element_by_value(self, value):
        if self.head == None:
            print("Error: linked list is empty")
            return
        if self.search_item(value) == False:
            print("Error: element doesn't exist inside the linked list")
            return
        
        current_idx = 0
        current_node = self.head
        while current_node != None:
            if current_node.data == value:
                if(current_idx == 0):
                    self.remove_at_start()
                    return
                if(current_idx+1 == self.length()):
                    self.remove_at_end()
                    return

                # taking the values I need
                before_node = self.get(current_idx-1)
                next_node = self.get(current_idx+1)

                # updating the connection
                before_node.next = next_node

                return

            current_node = current_node.next
            current_idx += 1

    def insert_at_index(self, index, value):
        new_node = Node(value)
        if self.head == None:
            self.head = new_node
            return
        
        length = self.length()
        if index == 0:
            self.insert_at_start(value)
            return
        if index == length:
            self.insert_at_end(value)
            return
        if index > length:
            print("Error: out of index")
            return

        # taking the values I need
        new_node = Node(value)
        before_node = self.get(index-1)
        next_node = self.get(index) # I'll replace the value of this "index"

        # making the necessary conections
        before_node.next = new_node
        new_node.next = next_node

        return


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

print("-----------")
print("Searching item")
my_list.search_item(7)
my_list.search_item(77)

print("-----------")
print("Removing item from start")
my_list.remove_at_start()
my_list.display()

print("-----------")
print("Removing item from end")
my_list.remove_at_end()
my_list.display()

print("-----------")
print("Inserting item at start")
my_list.insert_at_start(10)
my_list.display()

print("-----------")
print("Inserting item at end")
my_list.insert_at_end(3)
my_list.display()

print("-----------")
print("Removing item by value")
my_list.remove_element_by_value(3)
my_list.display()

print("-----------")
print("Inserting item at index")
my_list.insert_at_index(2, 88)
my_list.display()