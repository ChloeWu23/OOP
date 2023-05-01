#include<iostream>
#include<cstdlib>
using namespace std;
//bound checking
class SafeArray {
private:
int *data;
int size;
public:
  SafeArray(int _size): size(_size){
  data = new(nothrow) int[size]
  assert(data);
}

~SafeArray(){
delete [] data ;
}

int get_size() const {return size;}

itn &operator[](int index){
 // assert(index >=0 && index < size); if not quit the program
if(index >=0 && index < size) return data[index];
cerr << "Index " << index " is out of bound, expected to be 0 " <<size -1 << endl;
exit(1);
}
}

int main(){
 Safearray x(6); //call constructor
//give eror message for out of bound
x[4] = -1; //x.operator[](4)
x[20] = 5;  
}
