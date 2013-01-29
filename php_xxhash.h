#ifndef PHP_XXHASH_H
#define PHP_XXHASH_H

#define PHP_XXHASH_VERSION "1.0.0"

extern const zend_module_entry xxhash_module_entry;
#define phpext_xxhash_ptr &xxhash_module_entry

#if defined(PHP_WIN32) && defined(XXHASH_EXPORTS)
#define PHP_XXHASH_API __declspec(dllexport)
#else
#define PHP_XXHASH_API PHPAPI
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_FUNCTION(xxhash32);

#endif /* PHP_XXHASH_H */

