def add_style(style):
    def add_wrapping(item):
        def wrapped_item():
            return 'a {} wrapped up box of {}'.format(style,str(item()))
        return wrapped_item
    return add_wrapping


@add_style('beutifull')
def new_book():
    return 'a new book!!'

@add_style('horibal')
def new_bike():
    return 'a new Bike!!'

print(new_book())
print(new_bike())
