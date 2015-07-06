PHP-xxHash
==========

A PHP extension to add support for the [xxHash](https://github.com/Cyan4973/xxHash) fast hashing algorithm.

[xxHash](https://github.com/Cyan4973/xxHash) is an Extremely fast Hash algorithm, running at RAM speed limits. 
It successfully completes the [SMHasher](http://code.google.com/p/smhasher/wiki/SMHasher) test suite which evaluates collision, dispersion and randomness qualities of hash functions.

## Installation Instructions

```
   phpize
   ./configure --enable-xxhash
   make
   sudo make install
```
Don't forget to load the extension in via php.ini or the like.

## Usage Instructions

Upon installation and enabling the extension within php.ini the following two new functions will be available to you:

```
int xxhash32(string $data);
int xxhash64(string $data);
```

In both cases an integer will be returned, representing the hash of the $data input.


## Credits
* Original implementation of [php-xxhash](https://github.com/stuartherbert/php-xxhash) by Stuart Herbert.


## Licence

BSD 2-clause license.