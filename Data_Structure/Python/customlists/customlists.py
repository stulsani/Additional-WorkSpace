import heapq

grades = [23,45,21,56,43,76,99,43,34,65,69,74]

print(heapq.nlargest(3,grades))

custom_grades = [
    { 'name': 'Sumeet', 'percentage': 92.5 },
    { 'name': 'Sagar', 'percentage': 90.1 },
    { 'name': 'Aman', 'percentage': 81.54 },
    { 'name': 'Nilesh', 'percentage': 36.54 },
    { 'name': 'Satish', 'percentage': 83.43 },
    { 'name': 'Manoj', 'percentage': 45.2 },
    { 'name': 'Vishal', 'percentage': 95.34 }
]

print(heapq.nsmallest(2, custom_grades, key=lambda custom_grades: custom_grades['percentage']))