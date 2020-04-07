# From Google Find the middle element of a linked list.....
#error

#Node Setup
class Node:

    def __init__(self, data, next):
        self.data = data
        self.next = next

def middle_element(cls, head):
    head = Node()
    fastPointer = head
    slowPointer = head
    
    while fastPointer.next != None and fastPointer.next.next != None:
        fastPointer = fastPointer.next.next
        slowPointer = slowPointer.next
    
    print(slowPointer)

if __name__ == "__main__":
    inp = input()
    element = middleElement(inp)