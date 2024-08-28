#include <iostream>
#include <vector>
int size = -1;

void quick_sort(int *v, int left, int right)
{
  if (left >= right) {
    return;
  }
  int pviot = v[right];
  int l = left, r =right;
  while (l < r) {
    while (l < r && v[l] <= pviot) {
      ++l;
    }
    if (l < r && v[l] > pviot) {
      v[r] = v[l];
      --r;
    }
    // for (int i = 0; i < size; i++) {
    //   std::cout << v[i] << " ";
    // }
    // std::cout << std::endl;
    while (l < r && v[r] >= pviot) {
      --r;
    }
    if (l < r && v[r] < pviot) {
      v[l] = v[r];
      ++l;
    }
    // for (int i = 0; i < size; i++) {
    //   std::cout << v[i] << " ";
    // }
    // std::cout << std::endl;
  }
  // for (int i = 0; i < size; i++) {
  //   std::cout << v[i] << " ";
  // }
  // std::cout << std::endl;
  v[l] = pviot;
  quick_sort(v, left, l - 1);
  quick_sort(v, l + 1, right);
}

int main() {
  // std::vector<int> v = {7, 5, 4, 3, 6, 1, 2};
  std::vector<int> v = {7, 6, 5, 4, 3, 2, 1};
  size = v.size();
  std::cout << "Before: ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  quick_sort(v.data(), 0, v.size() - 1);
  std::cout << "After: ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}