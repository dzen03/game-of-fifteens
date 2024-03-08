#ifndef FIFTEENS_LIBS_POSITION_H_
#define FIFTEENS_LIBS_POSITION_H_

namespace fifteens {
struct Position {
  int x = uninitialised_value;
  int y = uninitialised_value;

  int number = uninitialised_value;

  Position(int x, int y, int number) : x(x), y(y), number(number) {}

  Position(int x, int y) : x(x), y(y) {
    number = uninitialised_value;
  }

  friend Position operator-(Position left, const Position &right) {
    return {left.x - right.x, left.y - right.y};
  }

  friend Position operator+(Position left, const Position &right) {
    return {left.x + right.x, left.y + right.y};
  }

  Position &operator+=(const Position &right) {
    x += right.x;
    y += right.y;
    return *this;
  }

  bool is_valid() const {
    return x >= 0 && y >= 0;
  }
 private:
  static constexpr int uninitialised_value = -1;
};

} // fifteens

#endif //FIFTEENS_LIBS_POSITION_H_
