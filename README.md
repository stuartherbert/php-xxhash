# php-xxhash

PHP extension to add support for the [xxhash](http://code.google.com/p/xxhash/) fast hashing algorithm.  _xxhash_ is designed to be fast enough to use in real-time streaming applications.

## How To Install

```
   phpize
   ./configure --enable-xxhash
   make
   sudo make install
```

## How To Use

This extension adds one new PHP function:

```
    int xxhash32(string $data);
```

It will checksum the string, and return the checksum.

## `hash()` integration

It also registers the hash algorithm to be used in the `hash()` functions:

```
    hash('xx', $data);

Or:

    $h = hash_init('xx');
    hash_update($h, $data);
    echo hash_final($h);
```

## License

BSD 2-clause license.
