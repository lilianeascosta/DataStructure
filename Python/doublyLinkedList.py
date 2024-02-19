from hashlib import new
from threading import current_thread


class DoubleNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def append(self,data):
        new_node = DoubleNode(data)

        new_node.next = None
        new_node.previous = None

        if self.head == None:
            new_node.previous = None
            new_node.next = None
            self.head = new_node
            return

        last_node = self.head
        while last_node.next != None:
            last_node = last_node.next
        last_node.next = new_node
        self.tail = new_node

        new_node.previous = last_node
        new_node.next = None
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

    def to_list(self):
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

    def display(self):
        contents = self.head

        if contents is None:
            print("Empty doubly linked list")

        while contents:
            print(contents.data)
            contents = contents.next

        print("-----------")

    def reverse_doublylinkedlist(self):
        current_node = self.head
        while current_node != None:
            previous = current_node.previous
            next = current_node.next

            if previous == None:
                self.tail = current_node

            current_node.previous = next
            current_node.next = previous

            if next == None:
                previous = current_node

            current_node = next

        self.head = previous

    def search_item(self, value):
        if self.head == None:
            print("Empty Doubly Linked List")
        
        found = False
        current_node = self.head

        while found != True:
            if current_node.data == value:
                found = True
                print(value, " was found inside the Linked List.")
                return True

            current_node = current_node.next
            if (current_node == None) and (found == False):
                print(value, " wasn't found inside the Linked List.")
                return False

    def remove_at_start(self):
        if self.head == None:
            print("Error: doubly linked list empty")
            return

        if self.get(1) == None:
            self.head = None

        new_first = self.get(1)
        new_first.previous = None
        self.head = new_first

        return

    def remove_at_end(self):
        if self.head == None:
            print("Error: doubly linked list empty")
            return
        if self.length() == 1:
            self.remove_at_start()

        new_last = self.tail.previous
        new_last.next = None
        self.tail = new_last
        return

    def insert_at_start(self, value):
        new_node = DoubleNode(value)
        if self.head == None:
            self.head = new_node
            return

        first_node = self.get(0)

        first_node.previous = new_node
        self.head = new_node
        self.head.next = first_node

        return

    def insert_at_end(self, value):
        new_node = DoubleNode(value)
        if self.head == None:
            self.head = new_node
            return

        current_end = self.tail
        current_end.next = new_node
        new_node.previous = current_end
        self.tail = new_node

        return

    def remove_element_by_value(self, value):
        if self.head == None:
            print("Error: doubly linked list is empty")
            return

        if self.search_item(value) == False:
            print("Error: element doesn't exist inside the doubly linked list")
            return

        current_idx = 0
        current_node = self.head
        while current_node != None:
            if current_node.data == value:
                if current_idx == 0:
                    self.remove_at_start
                    return
                if current_idx+1 == self.length():
                    self.remove_at_end()
                    return

                before_node = current_node.previous
                next_node = current_node.next

                before_node.next = next_node
                next_node.previous = before_node

                return

            current_node = current_node.next
            current_idx += 1

    def insert_at_index(self, index, value):
        print("inside insert at index")
        new_node = DoubleNode(value)
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
            return

        before_node = self.get(index-1)
        next_node = self.get(index)
        

        before_node.next = new_node
        next_node.previous = new_node
        new_node.next = next_node
        new_node.previous = before_node

        return
               


# Test
my_list = DoublyLinkedList()
my_list.display()

my_list.append(3)
my_list.append(7)
my_list.append(2)
my_list.append(1)

my_list.display()

print("Total number of elements are: " + str(my_list.length()))
print(my_list.to_list())

print("-----------")
data = my_list.get(2)
print(data)

print("-----------")
my_list.reverse_doublylinkedlist()
my_list.display()

my_list.search_item(2)

my_list.search_item(22)

my_list.remove_at_start()
my_list.display()

my_list.remove_at_end() # quando chamado mais de uma vez não está funcionando
my_list.display()

my_list.insert_at_start(100)
my_list.display()

my_list.remove_at_end()
my_list.display()

my_list.insert_at_end(4)
my_list.insert_at_end(6)
my_list.insert_at_end(8)
my_list.display()

my_list.remove_element_by_value(100)
my_list.display()

my_list.insert_at_index(2,3)
my_list.display()