custom_grades = {
    'Sumeet' : 92.5,
    'Sagar' : 90.1,
    'Aman' : 81.5,
    'Nilesh' : 36.54,
    'Satish' : 83.43,
    'Manoj' : 45.2,
    'Vishal' : 95.35,
}

print(min(zip(custom_grades.values(),custom_grades.keys())))

print(max(zip(custom_grades.values(),custom_grades.keys())))