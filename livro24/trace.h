#ifdef USE_TRACE
#  define TRACE printf("%s %u\n",__FILE__, __LINE__);
#  define TRACE2 { printf("%s %u", __FILE__, __LINE__); \
                fflush(stdout); }
#  define TRACEF(a) { \
         printf("%s %u:", __FILE__, __LINE__); \
         printf a; \
         fflush(stdout); \
        }
#else
#  define TRACE
#  define TRACE2
#  define TRACEF(a)
#endif
