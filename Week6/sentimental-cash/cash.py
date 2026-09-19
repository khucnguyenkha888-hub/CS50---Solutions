while True:
      try:
          cash = float(input("Change: "))
          if 0 < cash:
             break
      except ValueError:
          pass

Cash = round(cash * 100)
k = 0
while Cash > 0:
    if Cash >= 25:
        Cash -= 25
        k += 1
    elif Cash >= 10:
        Cash -= 10
        k += 1
    elif Cash >= 5:
        Cash -= 5
        k += 1
    else:
        Cash -= 1
        k += 1

print(k)
