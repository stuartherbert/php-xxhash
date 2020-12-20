# php-xxhash

PHP extension to add support for the [xxhash - r42](https://github.com/Cyan4973/xxHash) extremely fast hashing algorithm.  _xxhash_ is designed to be fast enough to use in real-time streaming applications.


## How To Install

Run
```
   phpize
   ./configure --enable-xxhash
   make
   sudo make install
```  

Add to the php.ini
```  
    extension=xxhash.so
```

Restart apache
```
    sudo service apache2 restart  
```
  

## How To Use

This extension adds three new PHP functions:

```
    // 32 bit version (all values are positive)
    int xxhash32(string $data);
    
    // 64 bit version (can return negative values since PHP doesn't support unsigned long values)
    long xxhash64(string $data);
    
    // 64 bit version (all values are positive but returned as strings)
    string xxhash64Unsigned(string $data);
```

They will checksum the string, and return the checksum.

## Credits
* Original implementation of [php-xxhash](https://github.com/stuartherbert/php-xxhash) by Stuart Herbert.
* Original update to PHP 7 of [php-xxhash](https://github.com/eskimi/php-xxhash) by Eskimi.
* [xxHash](https://github.com/Cyan4973/xxHash) by Yann Collet.


## License

BSD 2-clause license.