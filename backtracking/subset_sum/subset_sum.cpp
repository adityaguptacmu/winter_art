#include <iostream>
#include <string>
#include <cassert>

// optimisation possible.

using namespace std;
void generateSubsets(int *array, int size, int sum);
void subset_sum(int *array, int* answer_vector, int size, int a_v_index , int curr_sum, int iteration, int sum);
void print_vector(int *answer_vector, int a_v_index);

int main(int argc, char const *argv[])
{
  cout << "subset_sum" << endl;
  int array_sum[] = {1,2,3,4};
  int size = sizeof(array_sum)/sizeof(int);
  cout << size << endl;
  generateSubsets(array_sum, size, 7);
  return 0;
}

void generateSubsets(int *array, int size, int sum)
{
  int *answer_vector = (int *)malloc(size * sizeof(int));
  subset_sum(array, answer_vector, size, 0, 0, 0, sum);
  free(answer_vector);
}



void subset_sum(int *array, int* answer_vector, int size, int a_v_index , int curr_sum, int iteration, int sum)
{
  cout << "---------------------------" << endl;
  cout << "answer_vector = ";
  print_vector(answer_vector, a_v_index);
  cout << "a_v_index " << a_v_index << endl;
  cout << "iteration " << iteration << endl;
  cout << "curr_sum " << curr_sum << endl;
  cout << "---------------------------" << endl;

  if(curr_sum == sum)
  {
    cout << "+++++++++++++++++++++++++++" << endl;
    cout << "SUM FOUND, answer_vector = " << endl;
    print_vector(answer_vector, a_v_index);
    cout << "+++++++++++++++++++++++++++" << endl;
    // cout << "a_v_index " << a_v_index << endl;
    // cout << "iteration " << iteration << endl;
    // cout << "array[iteration] " << array[iteration] << endl;
    // cout << "array[iteration - 1] " << array[iteration - 1] << endl;
    // cout << "curr_sum - array[iteration] " << curr_sum - array[iteration - 1] << endl;
    // cout << "---------------------------" << endl;
    subset_sum(array, answer_vector, size, a_v_index - 1, curr_sum - sum, iteration - 1, sum);
    return;
  }
  else
  {
    for(int i = iteration; i < size; i++)
    {
      cout << i << endl;
      answer_vector[a_v_index] = array[i];
      subset_sum(array, answer_vector, size, a_v_index + 1, curr_sum + array[i], i + 1, sum);
    }
  }
  cout << "***************************" << endl;
  cout << "RETURNING" << endl;
  cout << "answer_vector = ";
  print_vector(answer_vector, a_v_index);
  cout << "a_v_index " << a_v_index << endl;
  cout << "iteration " << iteration << endl;
  cout << "curr_sum " << curr_sum << endl;
  cout << "***************************" << endl;
}

void print_vector(int *answer_vector, int a_v_index)
{
  for(int i = 0; i < a_v_index ; i++)
  {
    cout << answer_vector[i] << " ";
  }
  cout << endl;
}


