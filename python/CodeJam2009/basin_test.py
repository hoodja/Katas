import unittest
import collections

def get_number_of_maps(line):
  return int(line)

def get_height_and_width(line):
  nums = line.split()
  return (int(nums[0]), int(nums[1]))

class Cell(object):
  def __init__(self, height, west):
    self.height = height
    self.west = west

def build_cells(graph):
  previous = None
  cells = []
  for x in map(int, graph.split()):
    cells.append( Cell(x, west=previous) )
  return cells

def find_basins(height, width, graph):
  sink_names = (chr(x) for x in range(ord('a'), ord('z')))
  cells = build_cells(graph)

  for (index,thisCell) in enumerate(cells):
    if index == 0:
      thisCell.name = sink_names.next()
    else:
      west_cell = cells[index-1]
      if west_cell.height < thisCell.height:
        thisCell.name = west_cell.name
      else:
        thisCell.name = sink_names.next()
  return " ".join(cell.name for cell in cells)


class basin_test(unittest.TestCase):
  def test_truth(self):
    self.assertEqual(True, True)

  def test_can_read_number_of_maps(self):
    self.assertEqual(get_number_of_maps("10"), 10)

  def test_can_read_another_number_of_maps(self):
    self.assertEqual(get_number_of_maps("100"), 100)

  def test_can_read_height_and_width(self):
    self.assertEqual(get_height_and_width("1 1"), (1,1))

  def test_can_read_another_height_and_width(self):
    self.assertEqual(get_height_and_width("10 100"), (10, 100))

  def test_can_find_basins_of_1_x_1_map(self):
    self.assertEqual(find_basins(1,1,"1"), "a")

  def test_can_find_1_x_2(self):
    self.assertEqual(find_basins(1,2,"1 1"), "a b")

  def test_can_find_1_x_2_with_one_basin(self):
    self.assertEqual(find_basins(1,2,"1 2"), "a a")

  def pending_can_find_2_x_2(self):
    self.assertEqual(find_basins(2,2,"""1 1
1 1"""),
"""a b
c d""")

if __name__ == "__main__":
  unittest.main()
