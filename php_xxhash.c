#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_xxhash.h"
#include "ext/hash/php_hash.h"

#include "xxhash.c"

#ifdef COMPILE_DL_XXHASH
ZEND_GET_MODULE(xxhash)
#endif

typedef struct {
	void *state;
} PHP_XXH32_CTX;

PHP_HASH_API void PHP_XXH32Init(PHP_XXH32_CTX *context)
{
	context->state = XXH32_init(0);
}

PHP_HASH_API void PHP_XXH32Update(PHP_XXH32_CTX *context, const unsigned char *input, unsigned int inputLen)
{
	XXH32_feed(context->state, (void *)input, (int)inputLen);
}

PHP_HASH_API void PHP_XXH32Final(unsigned char digest[4], PHP_XXH32_CTX *context)
{
	unsigned int h32;

	h32 = XXH32_result(context->state);

	digest[0] = (unsigned char) ((h32 >> 24) & 0xff);
	digest[1] = (unsigned char) ((h32 >> 16) & 0xff);
	digest[2] = (unsigned char) ((h32 >> 8) & 0xff);
	digest[3] = (unsigned char) (h32 & 0xff);

	context->state = XXH32_init(0);
}

const php_hash_ops php_hash_xxh32_ops = {
	(php_hash_init_func_t) PHP_XXH32Init,
	(php_hash_update_func_t) PHP_XXH32Update,
	(php_hash_final_func_t) PHP_XXH32Final,
	(php_hash_copy_func_t) php_hash_copy,
	4,
	4,
	sizeof(PHP_XXH32_CTX)
};

PHP_MINIT_FUNCTION(xxhash)
{
	php_hash_register_algo("xx32", &php_hash_xxh32_ops);

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(xxhash)
{
	return SUCCESS;
}

PHP_RINIT_FUNCTION(xxhash)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(xxhash)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(xxhash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xxhash support", "enabled");
	php_info_print_table_row(2, "extension version", PHP_XXHASH_VERSION);
	php_info_print_table_row(2, "xxhash release", "http://code.google.com/p/xxhash/source/detail?r=6");
	php_info_print_table_end();
}

PHP_FUNCTION(xxhash32)
{
	char *arg1 = NULL;
	char *ret1 = NULL;
	int arg1_len;
	unsigned int sum;

	/* parse the parameters */
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg1, &arg1_len) == FAILURE || arg1_len < 1)
	{
		RETURN_NULL();
	}

	/* compute the checksum */
	sum = XXH32(arg1, arg1_len, 0);

	/* return the checksum */
	RETURN_LONG((long)sum);
}

zend_function_entry xxhash_functions[] = {
	PHP_FE(xxhash32, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry xxhash_module_entry = {
	STANDARD_MODULE_HEADER,
	"xxhash",
	xxhash_functions,
	PHP_MINIT(xxhash),
	PHP_MSHUTDOWN(xxhash),
	NULL,
	NULL,
	PHP_MINFO(xxhash),
	PHP_XXHASH_VERSION,
	STANDARD_MODULE_PROPERTIES
};

