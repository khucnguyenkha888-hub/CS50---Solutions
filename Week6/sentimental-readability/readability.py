text = input("Text: ")
length = len(text)

Letters = 0
Sentences = 0
Words = 1


for i in range(length):
    if text[i].isalpha():
       Letters += 1

for i in range(length):
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        Sentences += 1

for i in range(length):
    if text[i] == " ":
        Words += 1



L = (Letters/Words) * 100
S = (Sentences/Words) * 100
Index = 0.0588 * L - 0.296 * S - 15.8
n = int((Index * 10 + 5) / 10)
if n < 1:
   print("Before Grade 1")
elif n > 16:
   print("Grade 16+")
else:
   print(f"Grade {n}")


