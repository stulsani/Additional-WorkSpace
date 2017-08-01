class BinaryTree:
    def __init__(self,data):
        self.key = data
        self.left = None
        self.right = None

    def insert_left_child(self,data):
        if self.left == None:
            self.left = BinaryTree(data)
        else:
            t = BinaryTree(data)
            t.left = self.left
            self.left = t

    def insert_right_child(self,data):
        if self.right == None:
            self.right = BinaryTree(data)
        else:
            t = BinaryTree(data)
            t.right = self.right
            self.right = t

    def get_left_child(self):
        return self.left

    def get_right_child(self):
        return self.right

    def get_root_value(self):
        return self.key

    def set_root_value(self,data):
        self.key = data


r = BinaryTree('a')

r.insert_left_child('b')

r.insert_left_child('c')
print(r.get_left_child())
print(r.get_left_child().get_root_value())

r.insert_right_child('d')
print(r.get_right_child())
print(r.get_right_child().get_root_value())

r.set_root_value('hello')
print(r.get_root_value())
