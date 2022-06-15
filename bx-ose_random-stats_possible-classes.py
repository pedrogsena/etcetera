import random

stat_names = ["STR", "INT", "WIS", "DEX", "CON", "CHA"]
class_names = ["Fighter", "Magic-User", "Cleric", "Thief", "Dwarf", "Elf", "Halfling"]

def die(size):
  size = int(size)
  if size < 2: size = 2 #coinflip
  return random.randint(1, size)
  
def _3d6():
  result = 0
  for i in range(3):
    result = result + die(6)
  return result

def _4d6dl():
  result = 0
  dice_array =  [0, 0, 0, 0]
  for i in range(4):
    dice_array[i] = die(6)
  minimum = dice_array[0]
  for i in range(3):
    if minimum > dice_array[i+1]:
      result = result + minimum
      minimum = dice_array[i+1]
    else: result = result + dice_array[i+1]
  # print(dice_array)
  return result

def generate_stats(method):
  stats = [STR, INT, WIS, DEX, CON, CHA] = [0, 0, 0, 0, 0, 0]
  for i in range(6):
    if method != 0: stats[i] = _4d6dl()
    else: stats[i] = _3d6()
  return stats

def dwarf_req(stats):
  if stats[4] >= 9: return True
  else: return False

def elf_req(stats):
  if stats[1] >= 9: return True
  else: return False

def halfling_req(stats):
  if stats[3] >= 9 and stats[4] > 9: return True
  else: return False

def possible_classes(stats):
  possible = ["True", "True", "True", "True", "True", "True", "True"]
  for i in range(7):
    if i == 4: possible[i] = dwarf_req(stats)
    elif i == 5: possible[i] = elf_req(stats)
    elif i == 6: possible[i] = halfling_req(stats)
  return possible
  
def print_stats(stats, method):
  print("Your next B/X-OSE character's stats:")
  if method != 0: print("(Method: 4d6 drop lowest, six times, in order.)")
  else: print("(Method: 3d6, six times, in order.)")
  for i in range(6):
    print(stat_names[i], ":", stats[i])

def print_possible_classes(possible):
  to_print=""
  for i in range(7):
    if possible[i]:
      to_print = to_print + class_names[i]
      if i == 6 and possible[i]: to_print += "."
      elif i == 5 and possible[i] and not possible[i+1]: to_print += "."
      elif i == 4 and possible[i] and not possible[i+1] and not possible[i+2]: to_print += "."
      elif i == 3 and not possible[i+1] and not possible[i+2] and not possible[i+3]: to_print += "."
      else: to_print += ", "
  print("Possible classes:", to_print)

method = 0
# method = input("Pick a method - type 0 for 3d6, or anything else for 4d6-drop-lowest, both six times in order: ")
stats = generate_stats(method)
print_stats(stats, method)
possible = possible_classes(stats)
print_possible_classes(possible)