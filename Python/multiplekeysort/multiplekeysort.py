from operator import itemgetter

custom_grades = [
    { 'fname': 'Sumeet', 'lname': 'Tulsani', 'percentage': 92.5 },
    { 'fname': 'Sagar', 'lname': 'Tulsani','percentage': 90.1 },
    { 'fname': 'Aman', 'lname': 'valeja', 'percentage': 81.54 },
    { 'fname': 'Nilesh', 'lname': 'Mhaske', 'percentage': 36.54 },
    { 'fname': 'Satish', 'lname': 'katkade', 'percentage': 83.43 },
    { 'fname': 'Manoj', 'lname': 'Mhaske', 'percentage': 45.2 },
    { 'fname': 'Vishal', 'lname': 'Naik', 'percentage': 95.34 }
]

for x in sorted(custom_grades, key=itemgetter('fname')):
    print(x)

print("--------------------------------")

for x in sorted(custom_grades, key=itemgetter('lname')):
    print(x)

print("--------------------------------")

for x in sorted(custom_grades, key=itemgetter('fname', 'lname')):
    print(x)
