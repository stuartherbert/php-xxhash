PHP-xxHash
==========

A PHP extension to add support for the [xxHash](https://github.com/Cyan4973/xxHash) fast hashing algorithm.

[xxHash](https://github.com/Cyan4973/xxHash) is an Extremely fast Hash algorithm, running at RAM speed limits. 
It successfully completes the [SMHasher](http://code.google.com/p/smhasher/wiki/SMHasher) test suite which evaluates collision, dispersion and randomness qualities of hash functions.

## PHP7 Compatability

Please note at the moment the master branch should be used for PHP 5.x and develop branch should be used for PHP 7.x

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
string xxhash32(string $data);
string xxhash64(string $data);
```

In both cases a string will be returned, representing the digest (hash) of the $data input.


## Credits
* Original implementation of [php-xxhash](https://github.com/stuartherbert/php-xxhash) by Stuart Herbert.
* [xxHash](https://github.com/Cyan4973/xxHash) by Yann Collet.

## Licence

BSD 2-clause license.