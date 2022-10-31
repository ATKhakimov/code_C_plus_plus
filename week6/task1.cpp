#include <iostream>
#include <vector>

class Numbers {
  public:

    Numbers() =
    default;
  explicit Numbers(int number);
  explicit Numbers(int number, int numm);
  explicit Numbers(const int * num_arr, int Asize);
  explicit Numbers(const std::vector < int > & numm_arr);
  explicit Numbers(const int * num_arr, int Asize,
    const std::vector < int > & numm_arr);
  Numbers(const Numbers & other);
  Numbers(Numbers && other);
  ~Numbers();
  Numbers & operator = (const Numbers & other);
  Numbers & operator = (Numbers && other);
  friend std::ostream & operator << (std::ostream & stream,
    const Numbers & numberer);

  std::size_t length() const {
    return mas_len;
  }

  private:
    int * mas_arr;
  std::size_t mas_len;
  std::vector < int > mas_vec;

};

Numbers::Numbers(int number) {
  mas_arr = new int[1];
  mas_arr[0] = number;
  mas_len = 1;
}

Numbers::Numbers(int number, int numm): mas_vec {
  std::vector < int > (1, numm)
} {
  mas_arr = new int[1];
  mas_arr[0] = number;
  mas_len = 1;
}

Numbers::Numbers(const int * num_arr, int Asize) {
  if (num_arr != nullptr) {
    mas_len = Asize;
    mas_arr = new int[mas_len];

    for (std::size_t i = 0; i < mas_len; ++i)
      mas_arr[i] = num_arr[i];
  } else {
    mas_arr = nullptr;
    mas_len = 0;
  }
}

Numbers::Numbers(const std::vector < int > & numm_arr): mas_vec {
  numm_arr
} {}

Numbers::Numbers(const int * num_arr, int Asize,
    const std::vector < int > & numm_arr):
  mas_vec {
    numm_arr
  } {
    if (num_arr != nullptr) {
      mas_len = Asize;
      mas_arr = new int[mas_len];

      for (std::size_t i = 0; i < mas_len; ++i)
        mas_arr[i] = num_arr[i];
    } else {
      mas_arr = nullptr;
      mas_len = 0;
    }
  }

Numbers::Numbers(const Numbers & other):
  mas_len {
    other.mas_len
  }, mas_vec {
    other.mas_vec
  } {
    if (other.mas_arr != nullptr) {
      mas_arr = new int[mas_len];

      for (std::size_t i = 0; i < mas_len; ++i)
        mas_arr[i] = other.mas_arr[i];
    } else
      mas_arr = nullptr;
  }

Numbers::Numbers(Numbers && other):
  mas_len {
    other.mas_len
  }, mas_vec {
    std::move(other.mas_vec)
  } {
    mas_arr = other.mas_arr;
    other.mas_arr = nullptr;
    other.mas_len = 0;
  }

Numbers & Numbers::operator = (const Numbers & other) {
  if (this != & other) {
    delete[] mas_arr;

    if (other.mas_arr != nullptr) {
      mas_arr = new int[mas_len];

      for (std::size_t i = 0; i < mas_len; ++i)
        mas_arr[i] = other.mas_arr[i];
    } else
      mas_arr = nullptr;

    mas_vec = other.mas_vec;
  }

  return *this;
}

Numbers & Numbers::operator = (Numbers && other) {
  if (this != & other) {
    delete[] mas_arr;
    mas_arr = other.mas_arr;
    other.mas_arr = nullptr;
    other.mas_len = 0;
    mas_vec = std::move(other.mas_vec);
    other.mas_vec.clear();
  }
  return *this;
}

Numbers::~Numbers() {
  delete[] mas_arr;
}

std::ostream & operator << (std::ostream & stream,
  const Numbers & numberer) {
  stream << "Elements: ";
  for (std::size_t i = 0; i < numberer.length(); ++i) {
    stream << numberer.mas_arr[i];
    if (i != numberer.length() - 1)
      stream << ", ";
  }
  return stream;
}

int main() {
  Numbers num {
    12
  };
  Numbers num2 {
    12,
    13
  };
  int arr[] {
    11,
    12,
    13,
    14
  };
  Numbers num3 {
    arr,
    4
  };
  std::cout << "Examples" << std::endl;
  std::cout << num2 << std::endl;
  std::cout << num3 << std::endl;
}