
#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>

class Bitset{
public:

  // TODO COMMENT
  Bitset();

  // TODO COMMENT
  Bitset(int size);

  // TODO COMMENT
  Bitset(const std::string & value);

  // TODO COMMENT
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset& operator=(const Bitset &) = delete;

  // TODO COMMENT
  int size() const;

  // TODO COMMENT
  bool good() const;

  // TODO COMMENT
  void set(int index);

  // TODO COMMENT
  void reset(int index);

  // TODO COMMENT
  void toggle(int index);

  // TODO COMMENT
  bool test(int index);

  // TODO COMMENT
  std::string asString() const;

private:

  // TODO
    bool validity;
    int *bit_array;
    int N;
};

#endif
