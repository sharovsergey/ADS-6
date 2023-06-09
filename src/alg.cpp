// Copyright 2021 NNTU-CS
#include <cstdio>
#include <cstdlib>
using namespace std;

template<typename T, typename Cmp>
class TPQueue {
private:
   T*      arr;
   size_t  cnt;
   size_t  mem;
   Cmp     cmp;
public:

   TPQueue(void): arr(NULL), cnt(0), mem(16){}
   ~TPQueue() {
       this->clear();
   }

   TPQueue(const TPQueue&);
   TPQueue& operator = (const TPQueue&);
public:

   bool  push(const T& val) {
       size_t  i, p;
       T tmp;

       if(! this->_alloc())
           return false;
       arr[cnt] = val;

       i = cnt;
       p = (! i) ? 0 : (i - 1) >> 1;

       while((i > 0) && ! cmp(arr[p], arr[i])) {
           tmp    = arr[i];
           arr[i] = arr[p];
           arr[p] = tmp;

           i = p--;
           if(! i)
               break;
           p >>= 1;
       }
       ++cnt;
       return true;
   }

   void  pop(void) {
       if(cnt > 1) {
           arr[0] = arr[--cnt];
           this->this_heapify(0);
       } else
           cnt = 0;
   }

   T& top(void) { return arr[0]; }
   T& top(void) const { return arr[0]; }

   bool empty(void) const { return (! cnt); }

   size_t  size(void) const { return cnt; }

   void clear(void) {
       if(arr != NULL)
           delete[] arr;
       arr = NULL;
       cnt = 0;
       mem = 16; 
   }

private:

   bool _alloc(void) {
      size_t tmem;
      T* tmp;

      if(arr == NULL) {
           arr = new T[mem];
           if(arr == NULL)
                return false;
      }

      if((cnt + 1) >= mem) {
           tmem = cnt + 1 + cnt / 3;
           tmp  = new T[tmem];
           if(tmp == NULL)
                return false;
           for(size_t i = 0u; i < cnt; ++i)
                 tmp[i] = arr[i];
           delete[] arr;
           arr = tmp;
           mem = tmem;
       }
       return true;
   }

   void  this_heapify(size_t index) {
       size_t l, r, big;
       T  tmp;

       while(1) {
           l = (index << 1) + 1u;
           r = (index << 1) + 2u;

           if((l < cnt) && cmp(arr[l], arr[index]))
                big = l;
           else
                big = index;

           if((r < cnt) && cmp(arr[r], arr[big]))
                big = r;

           if(big != index) {
                tmp = arr[index];
                arr[index] = arr[big];
                arr[big]   = tmp;
                index = big;
           } else
                break;
       }
   }
};

struct cmp {
   bool operator () (const int& a, const int& b) const{
       return (a > b);
   }
};

int main(void){
    TPQueue<int, cmp> pq;

    for(int i = 0; i < 30; ++i)
        pq.push(rand() % 400);

    while(! pq.empty()){
        printf("%d\n", pq.top());
        pq.pop();
    }
    return 0;
}
