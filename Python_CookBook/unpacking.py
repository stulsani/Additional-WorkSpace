records = [
    ('foo',45,23),
    ('bar',30),
    ('foo',21,45),
    ('bar',50)
]
def de_foo(x,y):
    print("In Foo: ",x+y)

def de_bar(x):
    print("In Bar: ",x)

for name,*args in records:
    if name == 'foo':
        de_foo(*args)
    elif name == 'bar':
        de_bar(*args)
