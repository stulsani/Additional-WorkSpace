shopping = {
    'soap' : 3.45,
    'shampoo' : 7.50,
    'crackers' : 10.23,
    'protein bars' : 20.00,
    'protein powder' : 60.59
}

print(min(zip(shopping.values(),shopping.keys())))
print(max(zip(shopping.values(),shopping.keys())))
print(sorted(zip(shopping.values(),shopping.keys())))
print(sorted(zip(shopping.keys(),shopping.values())))