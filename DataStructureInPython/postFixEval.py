from stack import Stack

def postFixEval(postfixExpr):
    myString = postfixExpr.split()
    myStack = Stack()
    for token in myString:
        if token in "123456789":
            myStack.push(int(token))
        elif token in "+-*/":
            if not myStack.isEmpty():
                oper1 = myStack.pop()
            else:
                print("Invalid Input")
                return
            if not myStack.isEmpty():
                oper2 = myStack.pop()
            else:
                print("Invalid Input")
                return
            result = doOperation(token,oper1,oper2)
            myStack.push(result)
        else:
            print("Sorry, Wrong Input!!")
            return
    if not myStack.isEmpty():
        return myStack.peek()

def doOperation(token,oper1,oper2):
    if token == '*':
        return oper1 * oper2
    elif token == '+':
        return oper1 + oper2
    elif token == '-':
        return oper1 - oper2
    elif token == '/':
        return oper1 / oper2

myInput = input("Enter the String: ")
print("Answer is: ")
print(postFixEval(myInput))
