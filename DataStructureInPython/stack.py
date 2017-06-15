# Implementing stack using lists

class Stack:
    def __init__(self):
        self.mystack = []

    def isEmpty(self):
        return self.mystack == []

    def push(self,num):
        self.mystack.append(num)

    def pop(self):
        return self.mystack.pop()

    def peek(self):
        return self.mystack[len(self.mystack) - 1]

    def size(self):
        return len(self.mystack)


ourstack = Stack()
print(ourstack.isEmpty())
ourstack.push(25)
print(ourstack.isEmpty())
print(ourstack.mystack[0])
ourstack.push(35)
ourstack.push(45)
print(ourstack.mystack[2])
print("Popping")
print(ourstack.pop())
print("Peek")
print(ourstack.peek())
print(ourstack.size())
