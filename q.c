  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  #define S 100
  #define M 999

  typedef struct { char k[S]; float v; } E;
  typedef struct { E e[M]; int c; } C;
  typedef struct { float w[S]; float b; } N;

  void i(C* c) { c->c = 0; memset(c->e, 0, sizeof(c->e)); }
  void a(C* c, char* k, float v) { strcpy(c->e[c->c].k, k); c->e[c->c].v = v; c->c++; }
  float g(C* c, char* k) { for(int i=0; i<c->c; i++) if(!strcmp(c->e[i].k, k)) return c->e[i].v; return 0; }

  void n(N* n) { for(int i=0; i<S; i++) n->w[i] = (float)rand()/RAND_MAX; n->b = 0; }
  float r(N* n, float* x) { float s = n->b; for(int i=0; i<S; i++) s += n->w[i] * x[i]; return s; }

  int main() {
      C c; N n; i(&c); n(&n);

      srand(time(NULL));

      for(int i=0; i<10; i++) {
          char k[10]; sprintf(k, "k%d", i);
          float v = (float)rand()/RAND_MAX;
          a(&c, k, v);

          float x[S]; for(int j=0; j<S; j++) x[j] = (float)rand()/RAND_MAX;
          float o = r(&n, x);

          printf("result: %.3f\n", o);
      }

      return 0;
  }
