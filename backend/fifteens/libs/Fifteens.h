#ifndef FIFTEENS_LIBS_FIFTEENS_H_
#define FIFTEENS_LIBS_FIFTEENS_H_

#include <cassert>
#include <vector>

#include "Position.h"

namespace fifteens {
class Move {
 public:
  Position get_start_position() { return start_position; }
  Position get_end_position() { return end_position; }

  void set_start_position(Position start) { start_position = start; }
  void set_end_position(Position end) {
    end_position = end;
    assert((start_position - end_position).is_valid());
  }
 private:
  Position start_position;
  Position end_position;
};

// receives matrix
std::vector<Move> solve(const std::vector<std::vector<int>>& input_matrix);

// receives list of positions
std::vector<Move> solve(const std::vector<Position>& positions);

} // fifteens

#endif //FIFTEENS_LIBS_FIFTEENS_H_
