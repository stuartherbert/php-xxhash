#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_xxhash.h"

#include "xxhash.c"

#ifdef COMPILE_DL_XXHASH
	ZEND_GET_MODULE(xxhash);
	#ifdef ZTS
		ZEND_TSRMLS_CACHE_DEFINE();
	#endif
#endif

PHP_MINFO_FUNCTION(xxhash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xxhash support", "enabled");
	php_info_print_table_row(2, "extension version", PHP_XXHASH_VERSION);
	php_info_print_table_row(2, "xxhash release", "r40");
	php_info_print_table_end();
}

PHP_FUNCTION(xxhash32)
{
    char *arg = NULL;
    size_t arg_len, len;
    zend_string *strg;
	unsigned int sum;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE || arg_len < 1) {
        return;
    }

	// compute the checksum
	sum = XXH32(arg, arg_len, 0);

	//convert to a hex string
	strg = strpprintf(0, "%08x", sum);

	// return the checksum
	RETURN_STR(strg);
}

PHP_FUNCTION(xxhash64)
{
	char *arg = NULL;
    size_t arg_len, len;
    zend_string *strg;
	unsigned long long sum;
	//typedef unsigned int U32;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE || arg_len < 1) {
        return;
    }

	// compute the checksum
	sum = XXH64(arg, arg_len, 0);

	//convert to a hex string
	strg = strpprintf(0, "%08x%08x", (U32)(sum >> 32), (U32)sum);

	// return the checksum
	RETURN_STR(strg);
}

const zend_function_entry xxhash_functions[] = {
	ZEND_FE(xxhash32, NULL)
	ZEND_FE(xxhash64, NULL)
	PHP_FE_END
};

zend_module_entry xxhash_module_entry = {
	STANDARD_MODULE_HEADER,
	"xxhash",
	xxhash_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(xxhash),
	PHP_XXHASH_VERSION,
	STANDARD_MODULE_PROPERTIES
};
