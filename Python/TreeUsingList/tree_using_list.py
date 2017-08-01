def binary_tree(r):
    return [r, [], []]

def add_left_child(root,lc):
    t = root.pop(1)
    if len(t) > 1:
        root.insert(1,[lc,t,[]])
    else:
        root.insert(1,[lc,[],[]])
    return root

def add_right_child(root,rc):
    t = root.pop(2)
    if len(t) > 1:
        root.insert(2,[rc,[],t])
    else:
        root.insert(2,[rc,[],[]])
    return root

def get_root_value(root):
    return root[0]

def get_left_subtree(root):
    return root[1]

def get_right_subtree(root):
    return root[2]

def set_new_root_value(root,newvalue):
    root[0] = newvalue

bt = binary_tree(20)
add_left_child(bt,10)
add_right_child(bt,30)
add_right_child(bt,25)

print("Root: ", get_root_value(bt))
print("Left SubTree: ", get_left_subtree(bt))
print("Right SubTree: ", get_right_subtree(bt))

set_new_root_value(bt,12)

print("Root: ", get_root_value(bt))
