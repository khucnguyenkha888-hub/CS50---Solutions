
while True:
      try:
          height = int(input("Height: "))
          if 1 <= height <= 8:
             break
      except ValueError:
             pass

wide = height - 1
for i in range(height):
    for o in range(wide):
        print(" ",end = "")
    for p in range(height - wide):
        print("#", end = "")
    print()
    wide -= 1


