import csv

html_start = """<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
"""
html_end = """
</body>
</html>"""
card_template = """
<h1>{name}</h1>
<h2>{position}</h2>
<ul>
    <li>{phone}</li>
    <li><a href="mailto:{email}">{email}</a></li>
</ul>
<img src="{photo}" alt="{name}">
<hr>
"""
with open('data.csv',newline='',encoding='utf-8') as f:
    reader=csv.DictReader(f,delimiter=';')
    cards=[]
    for row in reader:
        card=card_template.format(
            name=row['name'],
            position=row['position'],
            phone=row['phone'],
            email=row['e-mail'],
            photo=row['photo']
        )
        cards.append(card)

with open('visitcards.html','w',encoding='utf-8') as f:
    f.write(html_start)
    f.write(''.join(cards))
    f.write(html_end)