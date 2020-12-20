#ifndef PHP_XXHASH_H
#define PHP_XXHASH_H

extern zend_module_entry xxhash_module_entry;
#define phpext_xxhash_ptr &xxhash_module_entry

#define PHP_XXHASH_VERSION "2.0"

#ifdef PHP_WIN32
#   define PHP_XXHASH_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#   define PHP_XXHASH_API __attribute__ ((visibility("default")))
#else
#   define PHP_XXHASH_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif


#ifdef ZTS
#define XXHASH_G(v) ZEND_TSRMG(xxhash_globals_id, zend_xxhash_globals *, v)
#ifdef COMPILE_DL_XXHASH
ZEND_TSRMLS_CACHE_EXTERN();
#endif
#else
#define XXHASH_G(v) (xxhash_globals.v)
#endif

#endif  /* PHP_XXHASH_H */